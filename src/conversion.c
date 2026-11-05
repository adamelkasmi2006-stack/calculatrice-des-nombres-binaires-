#include <stdio.h>
#include <stdlib.h>
#include "../include/conversion.h"

void decimal(int code1, int code3, int A, int B) {
    int res = 0;
    int T[8];
    int i, val, retenue, somme;

    if (code3 == 1) {
        res = A + B;
    } else if (code3 == 2) {
        res = A - B;
    } else if (code3 == 3) {
        res = A * B;
    } else if (code3 == 4) {
        // Verification de la division par zero
        if (B == 0) {
            printf("Erreur : Division par zero impossi !\n");
            return;
        }
        res = A / B;
    }

    // Affichage du resultat en base 10 (Decimal)
    printf("\nResultat en Decimal = %d\n", res);

    // On prend la valeur positive du resultat pour diviser par 2
    if (res < 0) {
        val = -res;
    } else {
        val = res;
    }

    for (i = 7; i >= 0; i--) {
        T[i] = val % 2; // Reste de la division par 2 (0 ou 1)
        val = val / 2;  // Quotient de la division par 2
    }

    // =========================================================
    // Gestion du signe selon le systeme choisi (code1)
    // =========================================================

    // Cas 1 : Systeme Valeur Absolue (code1 == 1)
    if (code1 == 1) {
        // Le premier bit a gauche (T[0]) represente le signe
        if (res < 0) {
            T[0] = 1; // 1 pour un nombre negatif
        } else {
            T[0] = 0; // 0 pour un nombre positif
        }
        printf("Resultat en Binaire (Valeur Absolue) : ");
    }

    // Cas 2 : Systeme Complement a 2 (code1 == 2)
    else if (code1 == 2) {
        // Si le resultat est negatif, on applique le complement a 2
        if (res < 0) {
            // a) Complement a 1 : on inverse tous les bits (0 devient 1, 1 devient 0)
            for (i = 0; i < 8; i++) {
                if (T[i] == 0) {
                    T[i] = 1;
                } else {
                    T[i] = 0;
                }
            }

            // b) Complement a 2 : on ajoute 1 au bit de droite (T[7])
            retenue = 1;
            for (i = 7; i >= 0; i--) {
                somme = T[i] + retenue;
                if (somme == 2) { // En binaire : 1 + 1 = 0 avec une retenue de 1
                    T[i] = 0;
                    retenue = 1;
                } else {
                    T[i] = somme;
                    retenue = 0;
                }
            }
        }
        printf("Resultat en Binaire (Complement a 2) : ");
    }

    // =========================================================
    //  Affichage du tableau binaire (de gauche a droite)
    // =========================================================
    for (i = 0; i < 8; i++) {
        printf("%d", T[i]);
    }
    printf("\n");
}
