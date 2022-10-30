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

struct TreeNode * searchEle(struct TreeNode * ptr, int key){ //Recursive Approach
    if(ptr==NULL){
        return NULL;
    }
    else if(ptr->data==key){
        return ptr;
    }
    else if(ptr->data<key){
        searchEle(ptr->rChild,key);
    }
    else{
        searchEle(ptr->lChild,key);
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

   
    // Recursive Search     (Time Complexity lies between logN (usually) and N (in case of skewed tree) )
    if(searchEle(root,8)!=NULL){
        printf("Target %d Found\n",searchEle(root,8)->data);
    }
    else{
         printf("Not Found\n");
    }


    return 0;
}