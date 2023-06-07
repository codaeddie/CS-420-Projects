/* Decimal to Binary Conversion and Two's Complement Representation
 * Author: Eddie Coda
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Dynamic memory allocation */
    int* inum= (int*) malloc(sizeof(int));
    int* bitsize = (int*) malloc(sizeof(int));
    int* inputdec = (int*) malloc(sizeof(int));

    /* Get Decimal input value */
    do {
        printf("Please input a decimal number: ");
        *inputdec = scanf("%d", inum);

        if(*inputdec != 1){
            printf("Input must be a decimal, please try again: ");
            while(getchar() != '\n'); // clear input buffer
        }
    } while(*inputdec != 1);

    /* Get bit size from user */
    do {
        printf("In what bit system do you want to output our number? (i.g. 4/8/16/32/64): ");
        scanf("%d", bitsize);

        if(*bitsize !=4 && *bitsize!=8 && *bitsize != 16 && *bitsize != 32 && *bitsize != 64){
            printf("Please select from the following bit systems for output: (4/8/16/32/64): ");
            while(getchar() != '\n'); // clear input buffer
        }

        if(*inum >= (1<< *bitsize)){
            printf("Error, input size would result in overflow, try again (4/8/16/32/64): ");
            scanf("%d", bitsize);
        }
    } while(*bitsize !=4 && *bitsize!=8 && *bitsize != 16 && *bitsize != 32 && *bitsize != 64);

    /* allocating memory for output ptr */
    int* binaryoutput = (int*) malloc(sizeof(int) * (*bitsize));
    int index = 0;

    /* Dec to Bin */
    while (*inum > 0) {
        binaryoutput[index++] = *inum % 2;
        *inum /= 2;
    }
    /* Reallocate memory for output ptr */
    binaryoutput = (int*) realloc(binaryoutput, index * sizeof(int));

    /* Perform 1's complement */
    int* onescomp = (int*) malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        onescomp[i] = binaryoutput[i] == 0 ? 1 : 0;
    }

    /* Perform 2's complement */
    int* twoscomp = (int*) malloc(sizeof(int) * index);
    int carry = 1;
    for (int i = index - 1; i >= 0; i--) {
        twoscomp[i] = binaryoutput[i] ^ 1;
        if (carry) {
            twoscomp[i] ^= 1;
            carry = binaryoutput[i];
        }
    }

    /* Print binary, 1's, and 2's complement */
    printf("Your number in Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryoutput[i]);
    }
    printf("\n");

    printf("Your number in One's complement: ");
    for (int i = 0; i < index; i++) {
        printf("%d", onescomp[i]);
    }
    printf("\n");

    printf("Your number in Two's complement: ");
    for (int i = 0; i < index; i++) {
        printf("%d", twoscomp[i]);
    }
    printf("\n");

    /* Free memory */
    free(binaryoutput);
    free(onescomp);
    free(twoscomp);
    free(inum);
    free(bitsize);
    return 0;
}