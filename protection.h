#ifndef PROTECTION_H_INCLUDED
#define PROTECTION_H_INCLUDED

enum keyOfMistake {
        nullStackPtr = -100,
        nullPtrOnStack,
        negativeSize,
        noMistake,
        leftCanary,
        rightCanary,
        arrayLeftCanary,
        arrayRightCanary,
        hashStackMistake,
        hashArrayMistake
    };

char* strOfMistakes[] = {"nullStackPtr"    , "nullPtrOnStack"  ,
                         "negativeSize"    , "noMistake"       ,
                         "leftCanary"      , "rightCanary"     ,
                         "arrayLeftCanary" , "arrayRightCanary",
                         "hashStackMistake", "hashArrayMistake"};

static const unsigned long long CANARY_LEFT  = 117;
static const unsigned long long CANARY_RIGHT = 119;

static FILE* logfile = fopen("logfile.txt", "w");

#endif // PROTECTION_H_INCLUDED
