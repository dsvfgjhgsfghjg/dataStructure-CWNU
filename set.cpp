#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>



typedef struct node {
    int data;
    struct node *next;
} LinkList;
LinkList* init() {
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    if (head == NULL) {
        printf("内存分配失败");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    return head;
}
LinkList* insert(LinkList *head, int data) {
    LinkList *newNode = (LinkList *)malloc(sizeof(LinkList));
    if (head == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head->next == NULL) {
        head->next = newNode;
    }else {
        LinkList *temp = head->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
return head;

}
LinkList* search(LinkList *head, int data) {
    LinkList *current = head->next;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }else {
            current = current->next;
        }
    }
    return NULL;
}
LinkList* deleteNode(LinkList* head,int data) {
    if (head->next == NULL) {
        return head;
    }
    if (head->data == data) {
        LinkList *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    LinkList *current = head->next;
    while (current->data!=data && current != NULL) {
            current = current->next;
    }
    LinkList *temp = current;
    free(temp);
    return head;
}
void printList(LinkList *head) {
    LinkList *temp = head->next; // 假设头节点不存储数据
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
LinkList* intersettion(LinkList* set1,LinkList* set2){
    LinkList *set = init();
    LinkList *current1 = set1->next;
    LinkList *current2 = set2->next;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            insert(set, current1->data);
        }
        if (current1->data < current2->data) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }
    return set;
}
LinkList* unionset(LinkList* list1, LinkList* list2) {
    LinkList* set = init();
    LinkList* current1 = list1->next;
    LinkList* current2 = list2->next;
    while (current1 != NULL || current2 != NULL) {
        if(current1 == NULL) {
            insert(set, current2->data);
            current2 = current2->next;
            continue;
        } else if(current2 == NULL) {
            insert(set, current1->data);
            current1 = current1->next;
            continue;
        }
        if(current1->data == current2->data) {

            insert(set, current1->data);
            current1 = current1->next;
            current2 = current2->next;
        }else if (current1->data < current2->data) {
            insert(set, current1->data);
            current1 = current1->next;
        }else if (current1->data > current2->data) {
            insert(set, current2->data);
            current2 = current2->next;
        }
    }
    /*while (current1 != NULL) {
        insert(set, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insert(set, current2->data);
        current2 = current2->next;
    }*/

    return set;
}
LinkList* difference(LinkList* list1, LinkList* list2) {
    LinkList* set = init();
    LinkList* current1 = list1->next;

    while (current1 != NULL) {
        LinkList* temp = list2->next;
        int found = 0;

        while (temp != NULL) {
            if (temp->data == current1->data) {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            insert(set, current1->data);
        }

        current1 = current1->next;
    }

    return set;
}
void freeList(LinkList *head) {
    LinkList *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {

    LinkList *set1 = init();
    LinkList *set2 = init();

    LinkList *unions = init();
    LinkList *intersetions = init();
    LinkList *differ = init();

    insert(set1, 1);
    insert(set1, 2);
    insert(set1, 3);
    printf("set1:");
    printList(set1);
    insert(set2, 3);
    insert(set2, 4);
    insert(set2, 5);
    printf("set2:");
    printList(set2);
    unions=unionset(set1, set2);
    printf("并集:");
    printList(unions);
    intersetions=intersettion(set1, set2);
    printf("交集:");
    printList(intersetions);
    differ=difference(set1, set2);
    printf("差集:");
    printList(differ);

    freeList(set1);
    freeList(set2);
    freeList(unions);
    freeList(intersetions);
    freeList(differ);
    return 0;
}