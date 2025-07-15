#include <stdio.h>

int matrix1[10][10];
int sparse1[10][3];
int matrix2[10][10];
int sparse2[10][3];
int sum[10][3];
int trans[3][10];
int m, n, i, j;
int k1 = 1;
int k2 = 1;
int k3 = 1;

void add()
{
    k1 = 1;
    k2 = 1;
    k3 = 1;

    printf("Enter the number of rows\n=>");
    scanf("%d", &m);
    printf("Enter the number of columns\n=>");
    scanf("%d", &n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the element for row:%d and column:%d for matrix A\n=>", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the element for row:%d and column:%d for Matrix B\n=>", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix1[i][j] != 0)
            {
                sparse1[k1][0] = i;
                sparse1[k1][1] = j;
                sparse1[k1][2] = matrix1[i][j];
                k1++;
            }
        }
    }

    sparse1[0][0] = m;
    sparse1[0][1] = n;
    sparse1[0][2] = k1 - 1;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matrix2[i][j] != 0)
            {
                sparse2[k2][0] = i;
                sparse2[k2][1] = j;
                sparse2[k2][2] = matrix2[i][j];
                k2++;
            }
        }
    }

    sparse2[0][0] = m;
    sparse2[0][1] = n;
    sparse2[0][2] = k2 - 1;

    for (i = 0; i < k1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sparse1[i][j]);
        }
        printf("\n");
    }

    printf(" +  \n");

    for (i = 0; i < k2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sparse2[i][j]);
        }
        printf("\n");
    }

    i = j = 1;

    while (i < k1 && j < k2)
    {
        if (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] == sparse2[j][1])
        {
            sum[k3][0] = sparse1[i][0];
            sum[k3][1] = sparse1[i][1];
            sum[k3][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
            k3++;
        }
        else if ((sparse1[i][0] < sparse2[j][0]) || (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1]))
        {
            sum[k3][0] = sparse1[i][0];
            sum[k3][1] = sparse1[i][1];
            sum[k3][2] = sparse1[i][2];
            i++;
            k3++;
        }
        else
        {
            sum[k3][0] = sparse2[j][0];
            sum[k3][1] = sparse2[j][1];
            sum[k3][2] = sparse2[j][2];
            j++;
            k3++;
        }
    }

    while (i < k1)
    {
        sum[k3][0] = sparse1[i][0];
        sum[k3][1] = sparse1[i][1];
        sum[k3][2] = sparse1[i][2];
        i++;
        k3++;
    }

    while (j < k2)
    {
        sum[k3][0] = sparse2[j][0];
        sum[k3][1] = sparse2[j][1];
        sum[k3][2] = sparse2[j][2];
        j++;
        k3++;
    }

    sum[0][0] = m;
    sum[0][1] = n;
    sum[0][2] = k3 - 1;

    printf(" =  \n");

    for (i = 0; i < k3; i++)
    {
        for (j = 0; j < 3; j++)
           {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void transpose()
{int rows=sum[0][2]+1;
    int cols=3;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = sum[i][j];
        }
    }
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int opt = 1;
    int added = 0;

    while (opt == 1)
    {
        int a;
        printf("Enter which operation you wished to do:\n[1]Addition of two sparse matrix\n[2]Transpose of the resultant matrix\n[3]Exit\n");
        scanf("%d", &a);
        if (a == 1)
        {
            add();
            added = 1;
        }
        else if (a == 2)
        {
            if (added)
                transpose();
            else
                printf("Please perform addition first before transposing.\n");
        }
        else if (a == 3)
        {
            opt = 0;
        }
        else
        {
            printf("Enter a valid option\n");
        }
    }

    return 0;
}
