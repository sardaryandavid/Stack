#include <stdio.h>
#include <iostream>

#define TYPE char
#include "stack.h"

#define TYPE int
#include "stack.h"

int main()
{
    struct myStack_int stack3, stack4;
    stackConstructor(&stack3);
    stackConstructor(&stack4);

    stackPush(&stack3, 4);
    stackPush(&stack3, 6);
    stackPush(&stack3, 2);
    stackPush(&stack3, 1);

    stackPop(&stack3);

    stackDump(&stack3, noMistake, INFORMATION);

    struct myStack_char stack1, stack2;
    stackConstructor(&stack1);
    stackConstructor(&stack2);

    stackPush(&stack1, 'a');
    stackPush(&stack1, 'b');
    stackPush(&stack1, 'd');
    stackPush(&stack1, 'f');

    stackPop(&stack1);

    stackDump(&stack1, noMistake, INFORMATION);

    return 0;
}


