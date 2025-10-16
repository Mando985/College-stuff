#include <stdio.h>
#include <stdlib.h>

void binsearch(int min, int max, int num, int list[5])
{
    char flag = 'f';
    while (min <= max)
    {
        int mid = (min + max) / 2;

        if (list[mid] == num)
        {
            printf("The index of the number is: %d \n", mid);
            flag = 't';
            break;
        }
        else if (list[mid] < num)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    if (flag == 'f')
    {
        printf("Your number doesnt exist in the list\n");
    }
}

void linearsearch(int num, int list[5], int len)
{
    int i;
    char flag = 'f';

    for (i = 0; i < len; i++)
    {
        if (list[i] == num)
        {
            printf("The position of the number is %d\n", i);
            flag = 't';
            break;
        }
    }
    if (flag == 'f')
    {
        printf("Your number doesnt exist in the list\n");
    }
}

int main()
{
    int len = 5;
    int i;
    int list[5];
    for (i = 0; i < len; i++)
    {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &list[i]);
    }

    int num;
    printf("Given list:{");
    for (i = 0; i < len; i++)
    {
        printf(" %d ", list[i]);
    }
    printf("}\nWhich of the element's num do you wish to find?\n=>");
    scanf("%d", &num);

    int opt;
    printf("Which algorithm would you like to chose?\n[1]Binary Search\n[2]Linear Search\n=>");
    scanf("%d", &opt);
    if (opt == 1)
    {
        int temp;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - i - 1; j++)
            {
                if (list[j] > list[j + 1])
                {
                    temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }

        printf("Sorted list for Binary Search: {");
        for (i = 0; i < len; i++)
        {
            printf(" %d ", list[i]);
        }
        printf("}\n");

        int min = 0;
        int max = len - 1;
        binsearch(min, max, num, list);
    }
    else
    {
        linearsearch(num, list, len);
    }

    return 0;
}
