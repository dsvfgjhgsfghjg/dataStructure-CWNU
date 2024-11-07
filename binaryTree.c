#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode{
  int data;
  struct BiTNode *lchild,*rchild,*parent;
}BiTNode,*Root;
Root createRoot(int data){
    Root root = (Root)malloc(sizeof(BiTNode));
    if(root == NULL){
      printf("Memory allocation error");
      exit(1);
    }
    root->data = data;
    root->lchild = root->rchild = NULL;
    return root;
}
BiTNode* insert(Root root,int data,BiTNode* parents){
  if(root == NULL){
    printf("You can't add root node to the tree, I will help you creat one and add data into the Root node!");
    root = createRoot(data);
    return root;
  }
   BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
   newNode->data = data;
   newNode->lchild = NULL;
   newNode->rchild = NULL;
   newNode->parent = parents;
   return newNode;
}
void preOrder(Root root){
if(root == NULL){
  printf("The tree is empty!");
  return;
}
}
void inOrder(Root root){

}
void postOrder(Root root){

}



//今夜我不关心人类，我只想你
//programming by 蜀中大侠