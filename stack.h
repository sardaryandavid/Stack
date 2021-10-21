#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cstdlib>

#define INFORMATION __FILE__, __LINE__, __PRETTY_FUNCTION__
#define printInformation printf("\x1b[32mFilename: %s, line of program: %d, function: %s\x1b[0m", INFORMATION);

#define CAT(x,y) x#y
#define myStack(x) CAT("myStack_", x) //
#define TYPE char

enum keyOfMistake {nullStackPtr = -100, nullPtrOnStack, negativeSize, noMistake};

struct myStack {
  TYPE* ptrOnStack = nullptr;
  size_t sizeOfStack = -1;

  const size_t maxSizeOfStack = 100;
};

void stackConstructor(struct myStack* Stack);
void stackDestructor(struct MyStack* Stack);

void stackAssert(struct myStack* Stack, const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake);
int stackIsGood(const struct myStack* Stack);
void stackDump(struct myStack* Stack, int keyOfMistake, const char* fileOfMistake, int stringOfMistake, const char* functionOfMistake);

void stackPush(struct myStack* Stack, const TYPE value);
void stackPop(struct myStack* Stack);
void stackResize(struct myStack* Stack, size_t newSize);
void printStack(struct myStack* Stack);

#endif // STACK_H_INCLUDED
