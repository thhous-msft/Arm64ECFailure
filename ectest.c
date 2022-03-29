#include "functions.h"
#include <stdio.h>


int main() {
    printf("Calling 1 arg From Exe\n");
    ECTest1Argument(NULL);
    printf("Calling 2 arg From Exe\n");
    ECTest2Arguments(NULL, NULL);
    printf("Calling 3 arg From Exe\n");
    ECTest3Arguments(NULL, NULL, NULL);
}
