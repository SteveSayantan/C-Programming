/* 
    AVL or Adelson-Velskii and Landis Trees are height balanced binary trees where the height difference between heights of left and right subtree for each node is less than or equal to 1.

    If we don't plan our tree properly, the height can get as high as n where n is the number of nodes in a BST (skewed tree)

    To guarantee an upper bound of O(log n) for all these operations, we use balanced trees.

    Balance Factor = Height of right subtree - Height of left subtree

    Balance Factor can be -1,0 or 1 for all nodes of an AVL tree

    Height of a subtree of a node = No of edges from the origin node to the deepest node along that subtree
*/

/*  
    Basic Rotation Operation (wrt a node):

    1. Left Rotation --> Node is moved towards the left

    2. Right Rotation --> Node is moved towards the right

                9                                      15 
              /  \      -Left Rotation wrt 9-->       /  \
             8    15    <--Right Rotation wrt 15-    9   20
                 /  \                               / \      
                11   20                            8  11  


*/

/* 
    1. After insertion of a node, we will move upwards to the first imbalanced node along the path of insertion.

    2. From the first imbalanced node, we will consider the direction of the two consecutive edges towards the inserted node.

    3. Cases:

        left and left --> LL insertion
        left and right --> LR insertion
        right and left --> RL insertion
        right and right --> RR insertion


*/

/* 
    LL insertion: For a LL insertion - Right rotate once wrt the first imbalanced node

    RR insertion: For a RR insertion - Left rotate once wrt the first imbalanced node. Similar to the following example

    Here, we are inserting 4 . 11 is the first imbalanced node and the two consecutive edges from 11 towards 4 are left-left. So it is a case of LL insertion.

               11                                        9 
              /  \      -Right Rotation wrt 11-->       /  \
             9    18                                   5    11
            /  \                                      /    /  \      
           5   10                                    4    10  18   
          /
         4


*/

/* 
    RL insertion: For a RL insertion - Right rotate once wrt the child (present along the path of insertion) of first imbalanced node. After that, left rotate wrt first imbalanced node. 

    Here, we are inserting 16 . 10 is the first imbalanced node and the two consecutive edges from 10 towards 16 are right-left. So it is a case of RL insertion. 17 is the child of the first imbalanced node (i.e. 10), present along the path of insertion

    N.B. The resultant tree is not balanced as it needs further rotation wrt 7. 

                7                                        7                                                  7
              /  \      -Right Rotation wrt 17-->       /  \       -Left Rotation wrt 10-->                / \
             1    10                                   1    10                                            1   16 
                   \                                       /  \                                               / \
                   17                                     8    16                                           10  17 
                  /                                              \                                         
                  16                                              17                                       

    LR insertion: For a LR insertion - Left rotate once wrt the child (present along the path of insertion) of first imbalanced node. After that, right rotate wrt first imbalanced node.
*/




