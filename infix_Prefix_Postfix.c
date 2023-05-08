/* 
    These are nothing but notations to write an expression. 

    Explanation with examples:

        1. Infix : General structure is --> Operand1 <Operator> Operand2 . E.g., a*b ; b/c ; a+b; b-c+d etc. (We use infix expressions in our daily life)

        2. Prefix: Here, the operator is placed before the operands. Therefore, general structure is --> <Operator> Operand1 Operand2 . E.g., *ab ; /bc ; +ab; -b+cd etc. 

        3. Postfix: Here, the operator is placed after the operands. Therefore, general structure is --> Operand1 Operand2 <Operator> . E.g., ab* ; bc/ ; ab+; bcd+- etc. 

    // Computers can not evaluate Infix expressions efficiently, therefore we need to use Prefix and Postfix expressions.

*/

/* 
----Conversion of Infix to Prefix or Postfix: (Reference https://youtu.be/4n3u-4W85RE )

        Step 1: Parenthesize the given expression according to Precedence and Associativity.

        Step 2: Convert each part into postfix or prefix and mark that using square brackets.

    Q1: Convert given infix expression to Prefix and Postfix: p-q-r/a

        // Prefix:
        Step 1: ((p-q)-(r/a))

        Step 2: ([-pq]-[/ra]) => --pq/ra

        // Postfix:
        Step 1: ((p-q)-(r/a))

        Step 2: ([pq-]-[ra/]) => pq-ra/-

    Q2: Convert -b, logx, x!, log x! into prefix and postfix. (Unary Operators)

        Prefix: b-, logx, !x, log!x

        Postfix: b-, xlog, x!, x!log

----Conversion of Prefix or Postfix to Infix:

    Step 1: Everytime start scanning from left (in case of Postfix) or from right (in case of Prefix)

    Step 2: As soon as we encounter an operator, convert its left adjacent (in case of Postfix) or right adjacent(in case of Prefix) two operands using that operator and apply parenthesis. Keep the rest of the expression intact.

    Step 3: Later on,remove some parenthesis if not required.

    For examples watch the video mentioned above @ 50:00


----Algorithm to evaluate Postfix or Prefix expression using Stack (Reference https://youtu.be/BnMLdX30q7M)

    Step 1: Add closing parenthesis ) at the end of expression **Postfix** ,Or, Add opening parenthesis ( at the start of expression **Prefix** 

    Step 2: Scan expression from left to right until ) is encountered: **Postfix** , Or, Scan expression from right to left until ( is encountered: **Prefix**

        I. If an Operand is encountered, PUSH it onto stack
        II. If an operator is encountered:

            A. POP first two elements from stack, a is top element and b is next to top element
            B. Evaluate b op a & PUSH the result onto stack **Postfix** ,Or, Evaluate a op b & PUSH the result onto stack **Prefix**

    Step 3: Set the result = top of stack.

    For examples watch the video mentioned above @ 20:00

    
 */

//Infix to Postfix using Stack (Reference: https://youtu.be/PAceaOSnxQs and Code With Harry's Lecture)