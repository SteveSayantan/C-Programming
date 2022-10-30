/* 
    Binary Search Tree:

    It is a special type of Binary Tree.

    Properties:

        1. All nodes of the left subtree are lesser than the node being considered.

        2. All nodes of the right subtree are greater than the node being considered.

        3. Left and right subtress are BST as well.

        4. No duplicate node is present.

        5. InOrder Traversal of a Binary Search Tree gives an ascending sorted array (E.g. 2,4,5,7,8,9,11,14,15 in this case)

    Example of Binary Search Tree: (https://www.freecodecamp.org/news/data-structures-101-binary-search-tree-398267b6bff0/)

              9
            /  \
          4     11
         / \     \
        2  7      15
          / \    /  
        5   8   14

    All the nodes to the left of 9 must be smaller

    All the nodes to the right of 9 must be greater
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




int main(){
    struct TreeNode * root;
    struct TreeNode * child2;
    struct TreeNode * child3;
    struct TreeNode * child4;
    struct TreeNode * child5;
    struct TreeNode * child6;
    struct TreeNode * child7;

    root= createNode(7);
    child2=createNode(5);
    child3=createNode(9);
    child4=createNode(4);
    child5=createNode(6);
    child6=createNode(8);
    child7=createNode(11);


    root->lChild=child2;
    root->rChild=child3;

    child2->lChild= child4;
    child2->rChild= child5;
    
    child3->lChild= child6;
    child3->rChild= child7;
    

/* 
    Our Binary Search Tree looks like this:
               7
              / \
            5    9
           /\    /\
          4  6  8  11           
*/  

   
    // InOrder Traversal
    InOrder(root);    
    return 0;
}



