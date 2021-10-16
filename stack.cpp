#include "stack.h"

#include <cstdlib>
#include <cstring>

#include <stdio.h>
#include <assert.h>

enum keyOfMistake {nullStackPtr = -100, nullPtrOnStack, negativeSize, noMistake};

void stackConstructor(struct myStack* Stack) {
    Stack->ptrOnStack = (int*) calloc(Stack->maxSizeOfStack, sizeof(Stack->maxSizeOfStack));
    Stack->sizeOfStack = 0;

    stackAssert(Stack, INFORMATION);
}

void stackDestructor(struct myStack* Stack) {
    stackAssert(Stack, INFORMATION);

    free(Stack->ptrOnStack);
}

void stackPush(struct myStack* Stack, const int value) {
    stackAssert(Stack, INFORMATION);

    if(Stack->sizeOfStack + 1 > Stack->maxSizeOfStack) {
        printf("It is too big stack\n");
        assert(Stack->sizeOfStack + 1 < Stack->maxSizeOfStack);
    }

    *((Stack->ptrOnStack)++) = value;
    ++Stack->sizeOfStack;

    stackAssert(Stack, INFORMATION);
}

void stackPop(struct myStack* Stack) {
    stackAssert(Stack, INFORMATION);

    if(Stack->sizeOfStack <= 0) {
        printf("Stack is empty");
        assert(Stack->sizeOfStack > 0);
    }

    *((Stack->ptrOnStack)--) = 0;

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
    printf("\x1b[32mFilename: %s, line of program: %d, function: %s\x1b[0m\n",
            fileOfMistake, stringOfMistake, functionOfMistake);

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

    exit(1);
}

void stackResize(struct myStack* Stack, size_t newSize) {
    stackAssert(Stack, INFORMATION);

    Stack->ptrOnStack = (int*) realloc(Stack->ptrOnStack, Stack->sizeOfStack * 2);

    stackAssert(Stack, INFORMATION);
}

void printStack(struct myStack* Stack) {
    size_t index = 0;

    while(index++ < Stack->sizeOfStack) {
        printf("%d ", *((Stack->ptrOnStack) + index));
    }

    printf("\n");
}

