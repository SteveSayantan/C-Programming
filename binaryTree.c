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
    root->lChild=child2;
    root->rChild=child3;

    child2=createNode(1);
    child2->lChild= child4;
    child2->rChild= child5;
    
    child3=createNode(4);
    child3->lChild= child6;
    child3->rChild= child7;
    
    child4=createNode(11);
    child5=createNode(12);
    child6=createNode(9);
    child7=createNode(3);


    return 0;
}