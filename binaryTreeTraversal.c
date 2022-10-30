/* 
Traversal in a Binary Tree:

    1. PreOrder Traversal: Root -> Left SubTree -> Right Subtree    

    2. PostOrder Traversal:  Left SubTree -> Right Subtree -> Root     

    3. InOrder Traversal:  Left SubTree -> Root ->Right Subtree    

 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode * lChild;
    struct TreeNode * rChild;
};

struct TreeNode * createNode(int item){
    struct TreeNode * n;
    n= (struct TreeNode *)malloc(sizeof(struct TreeNode));
    n->data= item;
    n->lChild= NULL;
    n->rChild= NULL;
    return n;

}

int main(){
    struct TreeNode * root;
    struct TreeNode * child2;
    struct TreeNode * child3;
    struct TreeNode * child4;
    struct TreeNode * child5;
    struct TreeNode * child6;
    struct TreeNode * child7;

    root= createNode(2);
    child2=createNode(1);
    child3=createNode(4);
    child4=createNode(11);
    child5=createNode(12);
    child6=createNode(9);
    child7=createNode(3);


    root->lChild=child2;
    root->rChild=child3;

    child2->lChild= child4;
    child2->rChild= child5;
    
    child3->lChild= child6;
    child3->rChild= child7;
    

/* 
    Our Binary Tree looks like this:
                2
              / \
            1    4
          /\    /\
        11 12  9 3

            
*/


    // PreOrder Traversal:
    PreOrder(root);     // 2 1 11 12 4 9 3 

    // PostOrder Traversal
    PostOrder(root);    // 11 12 1 9 3 4 2

    // InOrder Traversal
    InOrder(root);    // 11 1 12 2 9 4 3
    return 0;
}

void PreOrder(struct TreeNode * ptr){
    if(ptr!=NULL){
        printf("%3d",ptr->data);
        PreOrder(ptr->lChild);
        PreOrder(ptr->rChild);
    }
}

void PostOrder(struct TreeNode * ptr){
    if(ptr!=NULL){
        PostOrder(ptr->lChild);
        PostOrder(ptr->rChild);
        printf("%3d",ptr->data);
    }
}
void InOrder(struct TreeNode * ptr){
    if(ptr!=NULL){
        InOrder(ptr->lChild);
        printf("%3d",ptr->data);
        InOrder(ptr->rChild);
    }
}
