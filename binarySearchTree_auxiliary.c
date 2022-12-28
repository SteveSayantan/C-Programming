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

void InOrder(struct TreeNode * ptr){
    if(ptr!=NULL){
        InOrder(ptr->lChild);
        printf("%3d",ptr->data);
        InOrder(ptr->rChild);
    }
}

struct TreeNode * insertNodeRecursive(struct TreeNode * ptr, int item){
    if(ptr==NULL){  
        return createNode(item);
    }

    if(item>ptr->data){ // If the item is greater, make changes and update the right subtree
        ptr->rChild= insertNodeRecursive(ptr->rChild,item);
    }
    else if(item<ptr->data){ // If the item is smaller, make changes and update the left subtree
        ptr->lChild= insertNodeRecursive(ptr->lChild,item);
    }

    return ptr;
}

int getTotalNodes (struct TreeNode * ptr){
    if(ptr == NULL){
        return 0;
    }
    return 1+getTotalNodes(ptr->lChild)+ getTotalNodes(ptr->rChild);
}

int countInternalNodes(struct TreeNode * ptr){
    if(ptr == NULL || (ptr->lChild==NULL && ptr->lChild==NULL)){
        return 0;
    }
    return 1+countInternalNodes(ptr->lChild)+ countInternalNodes(ptr->rChild);
}

int getLeafCount(struct node* ptr){
  if(ptr == NULL)       
    return 0;
  if(ptr->lChild == NULL && ptr->rChild==NULL)      
    return 1;            
  else 
    return getLeafCount(ptr->lChild) + getLeafCount(ptr->rChild);      
}

int max(a,b){   // Auxiliary Function to find the maximum number
    return a>b?a:b;
}

int height(struct TreeNode* ptr){
    // base case tree is empty
    if (ptr == NULL)
        return -1;
 
    // If tree is not empty then height = 1 + max of left height and right heights
    return 1 + max(height(ptr->lChild), height(ptr->rChild));
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

    insertNode(root,10); 
    InOrder(root);
    printf("Total Number of Nodes is: %d\n",getTotalNodes(root)); 
    /* 
        After insertion, Binary Search Tree looks like this:
               7
              / \
            5    9
           /\    /\
          4  6  8  11
                   /
                  10           
    */  

   


    return 0;
}