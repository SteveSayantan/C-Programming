/* 
    M-way search tree: 

    1) It is a tree data-structure which can have maximum M-1 keys in each node and each node can have max M children.

    2) Values in a child node to the left of a key are smaller than the key.

    3) Values in a child node to the right of a key are greater than the key.

    4) The keys in a node are in ascending order.


    For example, when M=2, we get Binary Search tree.

    B-Tree:

    1) It is a type of M-way search tree having some extra properties.

    2) It is generally used in DBMS.

    3) In a B-Tree, all the leaf nodes should be at the same level.

    4) Each node must have at least M/2(ceil) keys.

    5) The above rule does not imply for the root node. The root node can have minimum one key and two children.

    6) Adjacent to each key in a node, there is a Record Pointer which points to a record in data table. For the sake of simplicity, we ignore these pointers.

    7) Bottom-up approach is followed while constructing a B-Tree.

    Reference: https://youtu.be/aZjYr87r1b8 , Unacademy DBMS playlist etc.

 */