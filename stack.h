#include <cstdlib>
#include <stdio.h>
#include <assert.h>
#include <cstdlib>
#include <cstring>


#define INFORMATION __FILE__, __LINE__, __PRETTY_FUNCTION__
#define printInformation printf("\x1b[32mFilename: %s, line of program: %d, function: %s\x1b[0m", INFORMATION);

#define CAT(x,y) x##y
#define CATSTR(x,y) #x#y

#define myStack(x) CAT(myStack_, x)
#define myStackStr(x) CATSTR(myStack_, x)

#define getName(name) #name

struct myStack(TYPE) {
  TYPE* ptrOnStack = nullptr;
  size_t sizeOfStack = -1;

  const size_t maxSizeOfStack = 100;
};

void stackConstructor(struct myStack(TYPE)* Stack);
void stackDestructor(struct myStack(TYPE)* Stack);

void stackAssert(struct myStack(TYPE)* Stack, const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake);
int stackIsGood(const struct myStack(TYPE)* Stack);

void stackDump(struct myStack(TYPE)* Stack,     int keyOfMistake,
               const char* fileOfMistake, int stringOfMistake,
               const char* functionOfMistake);


void stackPush(struct myStack(TYPE)* Stack, const TYPE value);
void stackPop(struct myStack(TYPE)* Stack);
void stackResize(struct myStack(TYPE)* Stack, size_t newSize);
void printStack(struct myStack(TYPE)* Stack);

void stackConstructor(struct myStack(TYPE)* Stack) {
    Stack->ptrOnStack = (TYPE*) calloc(Stack->maxSizeOfStack, sizeof(Stack->maxSizeOfStack));
    Stack->sizeOfStack = 0;

    stackAssert(Stack, INFORMATION);
}

void stackDestructor(struct myStack(TYPE)* Stack) {
    stackAssert(Stack, INFORMATION);

    free(Stack->ptrOnStack);
}

void stackPush(struct myStack(TYPE)* Stack, const TYPE value) {
    stackAssert(Stack, INFORMATION);

    if(Stack->sizeOfStack + 1 > Stack->maxSizeOfStack) {
        Stack->ptrOnStack = (TYPE*) realloc(Stack->ptrOnStack, Stack->sizeOfStack * 2);
    }

    *(Stack->ptrOnStack + Stack->sizeOfStack++) = value;

    stackAssert(Stack, INFORMATION);
}

void stackPop(struct myStack(TYPE)* Stack) {
    stackAssert(Stack, INFORMATION);

    if(Stack->sizeOfStack <= 0) {
        stackDump(Stack, negativeSize, INFORMATION);
    }

    *(Stack->ptrOnStack + Stack->sizeOfStack--) = 0;

    stackAssert(Stack, INFORMATION);
}

void stackAssert(struct myStack(TYPE)* Stack, const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake) {
    int keyOfMistake = 0;

    if((keyOfMistake = stackIsGood(Stack)) == nullStackPtr   ||
       (keyOfMistake = stackIsGood(Stack)) == nullPtrOnStack ||
       (keyOfMistake = stackIsGood(Stack)) == negativeSize) {
        stackDump(Stack, keyOfMistake, fileOfMistake, stringOfMistake, functionOfMistake);
    }
}

int stackIsGood(const struct myStack(TYPE)* Stack) {
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

void stackDump(struct myStack(TYPE)* Stack, int keyOfMistake,
               const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake) {
    printf("\x1b[32m  Filename: %s, line of program: %d, function: %s  \x1b[0m\n",
            fileOfMistake, stringOfMistake, functionOfMistake);
    printf("Stack type: %s\n", myStackStr(TYPE));

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

    printf("\n");

    printf("Pointer on stack(array) = %p\n", Stack->ptrOnStack);
    printf("Stack size = %zd\n", Stack->sizeOfStack);
    printf("Pointer on Stack: %p\n", Stack);

    printStack(Stack);

   // exit(1);
}

void stackResize(struct myStack(TYPE)* Stack, size_t newSize) {
    stackAssert(Stack, INFORMATION);

    Stack->ptrOnStack = (TYPE*) realloc(Stack->ptrOnStack, newSize);

    stackAssert(Stack, INFORMATION);
}

void printStack(struct myStack(TYPE)* Stack) {
    size_t index = 0;

    while(index < Stack->sizeOfStack) {
        if(strcmp(myStackStr(TYPE), "myStack_int") == 0) {
            printf("%d ", *((Stack->ptrOnStack) + index));
        }

        if(strcmp(myStackStr(TYPE), "myStack_char") == 0) {
            printf("%c ", *((Stack->ptrOnStack) + index));
        }

        if(strcmp(myStackStr(TYPE), "myStack_long long") == 0) {
            printf("%ld ", *((Stack->ptrOnStack) + index));
        }

        ++index;
    }

    printf("\n");
}

void stackCopy(struct myStack(TYPE)* stackTo, struct myStack(TYPE)* stackFrom) {

}
