#include <stdio.h>
#include <stdlib.h>
#include "../include/conversion.h"
#include "conversion.c"
int main() {
    int code1, code2, code3;
    int A, B;

    printf("========= Programme de Conversion =========\n");
    do {
        printf("Choisir le systeme soit :\n 1- Valeur absolue (ecrire le code 1)\n 2- Complement a 2 (ecrire le code 2)\n");
        scanf("%d", &code1);
    } while (code1 != 1 && code1 != 2);

    printf("Choisir la base :\n");
    do {
        printf("1. Decimal Base 10 (choisir nombre 1)\n");
        printf("2. Binaire Base 2 (choisir nombre 2)\n");
        scanf("%d", &code2);
    } while (code2 != 1 && code2 != 2);

    printf("Donner le premier nombre :\n ");
    scanf("%d", &A);
    printf("Donner le deuxieme nombre :\n ");
    scanf("%d", &B);


    do {
        printf("Choisir l'operateur :\n'+': avec le code num 1.\n'-': avec le code num 2.\n'*': avec le code num 3.\n'/': avec le code num 4.\n");
        scanf("%d", &code3);
    } while (code3 != 1 && code3 != 2 && code3 != 3 && code3 != 4);


    if (code2 == 1) {

        decimal(code1, code3, A, B);
    } else if (code2 == 2) {

    }

    return 0;
}



















