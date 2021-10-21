#include "stack.h"

#include <cstdlib>
#include <cstring>

#include <stdio.h>
#include <assert.h>

void stackConstructor(struct myStack* Stack) {
    Stack->ptrOnStack = (TYPE*) calloc(Stack->maxSizeOfStack, sizeof(Stack->maxSizeOfStack));
    Stack->sizeOfStack = 0;

    stackAssert(Stack, INFORMATION);
}

void stackDestructor(struct myStack* Stack) {
    stackAssert(Stack, INFORMATION);

    free(Stack->ptrOnStack);
}

void stackPush(struct myStack* Stack, const TYPE value) {
    stackAssert(Stack, INFORMATION);

    if(Stack->sizeOfStack + 1 > Stack->maxSizeOfStack) {
        Stack->ptrOnStack = (TYPE*) realloc(Stack->ptrOnStack, Stack->sizeOfStack * 2);
    }

    *(Stack->ptrOnStack + Stack->sizeOfStack++) = value;

    stackAssert(Stack, INFORMATION);
}

void stackPop(struct myStack* Stack) {
    stackAssert(Stack, INFORMATION);

    if(Stack->sizeOfStack <= 0) {
        stackDump(Stack, negativeSize, INFORMATION);
    }

    *(Stack->ptrOnStack + Stack->sizeOfStack--) = 0;

    stackAssert(Stack, INFORMATION);
}

void stackAssert(struct myStack* Stack, const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake) {
    int keyOfMistake = 0;

    if((keyOfMistake = stackIsGood(Stack)) == nullStackPtr   ||
       (keyOfMistake = stackIsGood(Stack)) == nullPtrOnStack ||
       (keyOfMistake = stackIsGood(Stack)) == negativeSize) {
        stackDump(Stack, keyOfMistake, fileOfMistake, stringOfMistake, functionOfMistake);
    }
}

int stackIsGood(const struct myStack* Stack) {
    if(!Stack) {
        return nullStackPtr;
    }

    if(!Stack->ptrOnStack){
        return nullPtrOnStack;
    }

    if(Stack->sizeOfStack < 0) {
        return negativeSize;
    }

    return noMistake;
}

void stackDump(struct myStack* Stack, int keyOfMistake,
               const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake) {
    printf("\x1b[32m  Filename: %s, line of program: %d, function: %s  \x1b[0m\n",
            fileOfMistake, stringOfMistake, functionOfMistake);
    printf("Stack type: %s\n", myStack(TYPE));
    switch (keyOfMistake) {
        case nullStackPtr:
            printf("key of mistake: null pointer on struct MyStack\n");
            break;
        case nullPtrOnStack:
            printf("key of mistake: null pointer on stack\n");
            break;
        case negativeSize:
            printf("key of mistake: negative size of stack\n");
            break;
    }
    //name of stack

    printf("\n");

    printf("Pointer on stack(array) = %p\n", Stack->ptrOnStack);
    printf("Stack size = %zu\n", Stack->sizeOfStack);
    printf("Pointer on Stack: %p\n", Stack);

    printStack(Stack);

   // exit(1);
}

void stackResize(struct myStack* Stack, size_t newSize) {
    stackAssert(Stack, INFORMATION);

    Stack->ptrOnStack = (TYPE*) realloc(Stack->ptrOnStack, newSize);

    stackAssert(Stack, INFORMATION);
}

void printStack(struct myStack* Stack) {
    size_t index = 0;

    while(index < Stack->sizeOfStack) {
        if(strcmp(myStack(TYPE), "myStack_int") == 0) {
            printf("%d ", *((Stack->ptrOnStack) + index));
        }

        if(strcmp(myStack(TYPE), "myStack_char") == 0) {
            printf("%c ", *((Stack->ptrOnStack) + index));
        }

        if(strcmp(myStack(TYPE), "myStack_long long") == 0) {
            printf("%ld ", *((Stack->ptrOnStack) + index));
        }

        ++index;
    }

    printf("\n");
}

void stackCopy(struct myStack* stackTo, struct myStack* stackFrom) {

}
