#include <stdio.h>
#include <string.h>


#define MAX 50

char pfx[MAX], ifx[MAX], stk[MAX], ch;

int pres(char ch) {
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  return 0;
}

int is_opr(char ch) {return pres(ch) > 0; }

int main() {
  int opt, f = 0;

  do {
    char tmp[MAX];
    int j = -1, k = -1;

    printf("\nSelect:\n"
           "[1] Infix to Postfix\t[2] Postfix Evaluation\n"
           "[0] Exit\nEnter: [0-2] ");
    scanf("%d", &opt);
    getchar();

    if (opt > 2 || opt < 0) {
      printf("Invalid option.\n");
      continue;
    } else if (opt == 0)
      break;

    if (opt == 1) {
      memset(ifx, '\0', MAX);
      memset(pfx, '\0', MAX);

      printf("Enter infix: [Single digit numbers/No spaces] ");
      fgets(ifx, MAX, stdin);
      ifx[strcspn(ifx, "\n")] = '\0';

      for (int i = 0; ifx[i] != '\0'; i++) {
        ch = ifx[i];
        
        if (ch == '(') {
          stk[++j] = '(';
        } 
        else if (ch == ')') 
        {
          while (stk[j] != '(')
            pfx[++k] = stk[j--];
          j--;
        } 
        else if (is_opr(ch))
         {
          while (pres(stk[j]) >= pres(ch))
            pfx[++k] = stk[j--];
            stk[++j] = ch;
        } else
          pfx[++k] = ch;
      }

      while (j != -1)
        pfx[++k] = stk[j--];
      pfx[j] = '\0';

      printf("\nPostfix: %s\n", pfx);
      f = 1;
    } else {
      if (f == 0) {
        printf("Enter infix evaluation first.\n");
        continue;
      }

      int a, b, res, istk[MAX];

      for (int i = 0; pfx[i] != '\0'; i++) {
        ch = pfx[i];

        if (is_opr(ch)) {
          b = istk[j--];
          a = istk[j--];

          switch (ch) {
          case '+':
            res = a + b;
            break;
          case '-':
            res = a - b;
            break;
          case '*':
            res = a * b;
            break;
          case '/':
            if (b == 0) {
              res = 0;
              break;
            }
            res = a / b;
            break;
          case '^':
            res = a;
            if (b <= 0) {
              res = 1;
              break;
            }
            for (int i = 0; i < b; i++)
              res *= a;
            break;
          }

          istk[++j] = res;
        } else {
          istk[++j] = ch - '0';
        }
      }

      printf("\nEvaluated postfix: %d\n", istk[0]);
    }

    j = -1;
    k = -1;
  } while (opt != 0);

  return 0;
}
