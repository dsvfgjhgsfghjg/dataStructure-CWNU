#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row, col, value;
} Triplet;

Triplet* initTriplet(int size);
void printTriplet(Triplet* triplet, int trip_num);
void printMatrix(int row, int col, int matrix[row][col]);
void freeTriplet(Triplet* triplet, int size);
Triplet* convertToTriplet(int row, int col, int matrix[row][col], int* trip_num);
void transpose(Triplet* triplet, int trip_num, Triplet** transposed, int* transposed_num);
void convertFromTriplet(Triplet* triplet, int trip_num, int row, int col, int matrix[row][col]);

int main() {
    int row = 4, col = 5;
    int matrix[4][5] = {
        {1, 0, 0, 0, 2},
        {0, 0, 3, 0, 0},
        {0, 4, 0, 0, 0},
        {0, 0, 0, 5, 6}
    };
    int trip_num = 0;
    Triplet* triplet = convertToTriplet(row, col, matrix, &trip_num);

    printf("Original triplets:\n");
    printTriplet(triplet, trip_num);

    Triplet* transposed = NULL;
    int transposed_num = 0;
    transpose(triplet, trip_num, &transposed, &transposed_num);

    printf("\nTransposed triplets:\n");
    printTriplet(transposed, transposed_num);

    int transposed_matrix[5][4] = {0};
    convertFromTriplet(transposed, transposed_num, 5, 4, transposed_matrix);

    printf("\nTransposed matrix:\n");
    printMatrix(5, 4, transposed_matrix);

    freeTriplet(triplet, trip_num);
    freeTriplet(transposed, transposed_num);

    return 0;
}

Triplet* initTriplet(int size) {
    Triplet* triplet = (Triplet*)malloc(size * sizeof(Triplet));
    if (triplet == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    return triplet;
}

Triplet* convertToTriplet(int row, int col, int matrix[row][col], int* trip_num) {
    int size = row * col;  // Assuming a reasonable upper bound for the number of non-zero elements
    Triplet* triplet = initTriplet(size);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                triplet[*trip_num].row = i;
                triplet[*trip_num].col = j;
                triplet[*trip_num].value = matrix[i][j];
                (*trip_num)++;
            }
        }
    }
    // Resize the allocated memory to the actual number of triplets
    triplet = realloc(triplet, *trip_num * sizeof(Triplet));
    if (triplet == NULL) {
        printf("Memory reallocation error\n");
        exit(1);
    }
    return triplet;
}

void printTriplet(Triplet* triplet, int trip_num) {
    for (int i = 0; i < trip_num; i++) {
        printf("(%d, %d, %d)\n", triplet[i].row, triplet[i].col, triplet[i].value);
    }
}

void printMatrix(int row, int col, int matrix[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeTriplet(Triplet* triplet, int size) {
    free(triplet);
}

void transpose(Triplet* triplet, int trip_num, Triplet** transposed, int* transposed_num) {
    *transposed = initTriplet(trip_num);  // Allocate memory for the transposed triplets
    for (int i = 0; i < trip_num; i++) {
        (*transposed)[*transposed_num].row = triplet[i].col;
        (*transposed)[*transposed_num].col = triplet[i].row;
        (*transposed)[*transposed_num].value = triplet[i].value;
        (*transposed_num)++;
    }
    // Resize the allocated memory to the actual number of transposed triplets
    *transposed = realloc(*transposed, *transposed_num * sizeof(Triplet));
    if (*transposed == NULL) {
        printf("Memory reallocation error\n");
        exit(1);
    }
}

void convertFromTriplet(Triplet* triplet, int trip_num, int row, int col, int matrix[row][col]) {
    for (int i = 0; i < trip_num; i++) {
        matrix[triplet[i].row][triplet[i].col] = triplet[i].value;
    }
}