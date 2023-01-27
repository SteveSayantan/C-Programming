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

struct TreeNode * deleteNode(struct TreeNode * ptr, int item){ // Using InOrder predecessor

    // Search for the node
    if(ptr==NULL){
        return ptr;
    }
    if(ptr->data>item){
        ptr->lChild= deleteNode(ptr->lChild,item);
        return ptr;
    }
    else if(ptr->data<item){
        ptr->rChild= deleteNode(ptr->rChild,item);
        return ptr;
    }
    //After reaching the desired node,
    // If only one child is present
    if(ptr->lChild==NULL){
        struct TreeNode * temp = ptr->rChild;
        free(ptr);
        return temp;
    }
    else if(ptr->rChild==NULL){
        struct TreeNode * temp = ptr->lChild;
        free(ptr);
        return temp;
    }
    else{   // If both children are present


        struct TreeNode * predParent= ptr;
        struct TreeNode * pred = ptr->lChild;

        while(pred->rChild!=NULL){  // Find the inOrder predecessor and its parent node
            predParent= pred;
            pred=pred->rChild;
        }

        if(predParent!=ptr){  // If the pred is the rChild of any node 

            predParent->rChild= pred->lChild; // Store the lChild of pred as the rChild of the predParent
            // As pred is the rChild of predParent, the elements in pred's left subtree should be placed at the right subtree of predParent   
        }


        else{ // If the predParent is actually the node being deleted and pred is the lChild of it

            predParent->lChild= pred->lChild; // Store the lChild of the pred as the lChild of predParent (the node being deleted).
            // As pred belongs to the left subtree of the predParent, the elements of pred's left subtree should be placed at the left subtree of the predParent. 
        }

        ptr->data= pred->data;
        free(pred);
        return ptr;
    }
}

/* 
    Discussion (Deletion of Node using inOrder predecessor)

    1. The inOrder predecessor has no rChild. It may have lChild.
    2. The inOrder predecessor of an node is the max element in the left subtree of that node.

    3. When we find the inOrder predecessor of a node having both children, there can be two cases:

        Either, The predecessor is the direct left child of the node being deleted.

        or, The predecessor is the rChild of any other node.
 */


struct TreeNode * deleteNodeSuccessor(struct TreeNode * ptr, int item){

    // Find the code https://www.geeksforgeeks.org/deletion-in-binary-search-tree

    // Exactly the opposite approach of the code above
}
/* 
    Discussion (Deletion of Node using inOrder successor)

    1. The inOrder successor has no lChild. It may have rChild.
    2. The inOrder successor of an node is the min element in the right subtree of that node.

    3. When we find the inOrder successor of a node having both children, there can be two cases:

        Either, The successor is the direct right child of the node being deleted. In that case, we move the rChild of the successor at the right subtree of successorParent (i.e. the node being deleted).

        or, The successor is the lChild of any other node.In that case, we move the rChild of the successor at the left subtree of successorParent.
 */





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

 insertNodeRecursive(root,10);  
   


    return 0;
}