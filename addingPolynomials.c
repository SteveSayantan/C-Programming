/* 
                    ----- --- ---- Addition of Two Polynomials (Algorithm) ---- --- -----

    Suppose, we have two linked lists containing two polynomials arranged in descending order of their exponents. The resultant polynomial is to be stored in a new linked list. For further details, checkout: https://youtu.be/cFHZ-a87Vp4

    Let ptr1 and ptr2 are two pointers pointing to the first node of each list respectively.

    Repeat the following until ptr1 or ptr2 becomes NULL

        if (ptr->expo== ptr2->expo){

            Add the coefficients and insert the newly created node in the resultant linked list and make ptr1 and ptr2 point to the next nodes.

        }
        if (ptr->expo> ptr2->expo){

            Insert the node pointed by ptr1 in the resultant linked list and make ptr1 point to the next node.
            
        }
        if (ptr->expo< ptr2->expo){

            Insert the node pointed by ptr2 in the resultant linked list and make ptr2 point to the next node.

        }

    Repeat until ptr2!=NULL
        Insert the remaining nodes

    Repeat until ptr1!=NULL
        Insert the remaining nodes
 */