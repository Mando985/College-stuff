#include <stdio.h>

struct term {
    int coeff;
    int exp;
};

int main() {
    struct term pol1[10], pol2[10], result[20];
    int i, j, k, n1, n2;

    printf("Enter the highest exponent of polynomial_1 \n=>");
    scanf("%d", &n1);

    printf("Enter the highest exponent of polynomial_2 \n=>");
    scanf("%d", &n2);

    for (i = 0; i <= n1; i++) {
        printf("Enter the coeff of x^%d of polynomial_1\n=>", n1 - i);
        scanf("%d", &pol1[i].coeff);
        pol1[i].exp = n1 - i;
    }

    for (i = 0; i <= n2; i++) {
        printf("Enter the coeff of x^%d of polynomial_2\n=>", n2 - i);
        scanf("%d", &pol2[i].coeff);
        pol2[i].exp = n2 - i;
    }

    i = j = k = 0;


    while (i <= n1 && j <= n2) {
   
        if (pol1[i].exp == pol2[j].exp) {
            result[k].exp = pol1[i].exp;
            result[k].coeff = pol1[i].coeff + pol2[j].coeff;
            i++; j++; k++;
        }
       
        else if (pol1[i].exp > pol2[j].exp) {
            result[k] = pol1[i];
            i++; k++;
        }
       
        else {
            result[k] = pol2[j];
            j++; k++;
        }
    }


    while (i <= n1) {
        result[k] = pol1[i];
        i++; k++;
    }
    while (j <= n2) {
        result[k] = pol2[j];
        j++; k++;
    }


    printf("\nPolynomial 1: ");
    for (i = 0; i <= n1; i++)
    {
        printf("%dx^%d", pol1[i].coeff, pol1[i].exp);
        if (i != n1) printf(" + ");
    }

    printf("\nPolynomial 2: ");
    for (i = 0; i <= n2; i++)
    {
        printf("%dx^%d", pol2[i].coeff, pol2[i].exp);
        if (i != n2) printf(" + ");
    }

    printf("\nResult: ");
    for (i = 0; i < k; i++)
     {
        printf("%dx^%d", result[i].coeff, result[i].exp);
        if (i != k - 1) printf(" + ");
     }

    return 0;
}

