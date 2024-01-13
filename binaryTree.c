#include <stdio.h>
#include <stdlib.h>

/* 
    Properties of a binary tree
    
        1. The maximum number of nodes at level ‘l’ of a binary tree is 2^l (level is 0-indexed)

        2. The Maximum number of nodes in a binary tree of height ‘h’ is 2^(h+1) – 1

        3. In a Binary Tree with N nodes, the minimum number of levels is Log2 (N+1)   // log base 2

        4. A Binary Tree with L leaves has at least |Log2 L|+ 1   levels   // log base 2

        5.  In a Binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children (i.e. internal nodes with two children)

        6. In a non-empty binary tree, if n is the total number of nodes and e is the total number of edges, then e = n-1
 */




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