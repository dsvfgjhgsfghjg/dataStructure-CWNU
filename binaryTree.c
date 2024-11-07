#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode{
  char data;
  struct BiTNode *lchild,*rchild,*parent;
}BiTNode,*Root;
Root createRoot(char data){
    Root root = (Root)malloc(sizeof(BiTNode));
    if(root == NULL){
      printf("Memory allocation error");
      exit(1);
    }
    root->data = data;
    root->lchild = root->rchild = NULL;
    return root;
}
BiTNode* insert(char data,int isLeft,BiTNode *parent){

}

void preOrder(BiTNode* node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  preOrder(node->lchild);
  preOrder(node->rchild);
}

void inOrder(BiTNode* node) {
  if (node == NULL) {
    return;
  }
  inOrder(node->lchild);
  printf("%d ", node->data);
  inOrder(node->rchild);
}

void postOrder(BiTNode* node) {
  if (node == NULL) {
    return;
  }
  postOrder(node->lchild);
  postOrder(node->rchild);
  printf("%d ", node->data);
}
int dealInput(char *c) {

    if (*c == '#'||*c == ' ') {
      return 0;
    }else if(*c >'A'||*c <'Z'){
      return 1;
    }else if(*c >= 'a'&&*c <= 'z'){
      *c = *c +32;
      return 1;
    }else {
      return -1;
    }
  }

int inputer(char *Buffer,BiTNode* currentNode,BiTNode *parent,int isLeft){

  while (*Buffer != '\0') {
    int isNULL = dealInput(Buffer);
    if(isNULL==-1) {
      printf("Invalid Input");
     exit(-1);
    }else {
      BiTNode* newNode = insert(parent->data,isLeft,currentNode);

    }

    *Buffer++;
  }

    }
int main(void){
  BiTNode *root = createRoot(1);
  char Buffer[100];
}

//今夜我不关心人类，我只想你
//programming by 蜀中大侠