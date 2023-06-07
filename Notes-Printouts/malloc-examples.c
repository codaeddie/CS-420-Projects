#include <stdio.h>  //printf
#include <string.h> //strcat, strcpy
#include <stdlib.h> //malloc, calloc, realloc, free

void staticMallocExample();

void dynamicMallocExample();

void mallocExample2();

int main() {
    staticMallocExample();
//    dynamicMallocExample();
    mallocExample2();

    return 0;
}

void staticMallocExample() {
    char v1[] = {'a', 'b', '\0'};
    int v2[100] = {1};
    float v3;
    long v4;

    printf("Char %lu\n", sizeof(v1));
    printf("Int %lu\n", sizeof(v2));
    printf("Float %lu\n", sizeof(v3));
    printf("Long %lu\n", sizeof(v4));

    char v5[50];
    strcpy(v5, "12345");
    printf("v5 %s\n", v5);
}

void dynamicMallocExample() {
    //// malloc
    int n;
    char *text;

    printf("Enter limit of the text: ");
    scanf("%d", &n);

    text = (char *) malloc(n * sizeof(char));
    if (text == NULL) printf("FAILED");

    printf("Enter text: ");
    scanf("%s", text);

    printf("Inputted text is: %s\n", text);

    //// realloc
    text = (char*)realloc(text, 50 * sizeof(char));
    if (text == NULL) printf("FAILED");

    free(text);
}

void mallocExample2() {
    char *text = (char *) malloc(sizeof(char));
    int i = 0;
    printf("Enter text: ");

    while (*(text + i - 1) != '\n') {
        scanf("%c", (text + i));
        i++;
        text = (char*)realloc(text, ((i + 1) * sizeof(char)));
    }

    printf("Inputted text is: %s\n", text);
}