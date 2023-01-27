/* 
    1. It is a special type of binary tree used to represent expressions. Reference : https://www.youtube.com/watch?v=2Z6g3kNymd0&t=3s

    2. In this type of tree, the leaf nodes contain the operands and the internal nodes contain the operators.

    3. PreOrder,InOrder,PostOrder traversal of this tree would return the Prefix,Infix,Postfix expression respectively 


// Steps to make an expression tree from an infix expression

    a. Find the operator having least value (acc. to precedence and associativity), this is the root.

    b. The left and right part of that operator are the left and right sub-tree respectively.

    c. Repeat this process until we get each operand as leaf node.

    Example: Following is the expression tree of a+b*c-d/e

               -
            /    \
           +      %
          / \    / \
         a  *   a  e
           / \
          b   c

    N.B. '/' has been represented as '%' to distinguish from the edges.

// Steps to make an expression tree from an postfix expression using stack (Reference:https://www.youtube.com/watch?v=WHs-wSo33MM&t=132s )


    A. Start scanning given postfix expression from left to right.

    B. If operand is encountered, push that in stack.

    C. In case of operator,
        1. Pop two elements from stack.
        2. The first one is the *right* child, second one is the *left* child and the operator is the root.
        3. Now push this subtree in the stack.
    
    D. Repeat this process until the expression ends.
 */