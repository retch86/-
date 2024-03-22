#include <stdio.h>

#define SIZE 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define NO_ERRORS 0

int scan(int*, int*);

int main(void)
{
    int list[SIZE];
    int n, mistake, res, count;
    n = 0;
    mistake = scan(list, &n);
    if (!mistake)
    {
        res = 1;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if ((list[i] % 2 == 1) || (list[i] % 2 == -1))
            {
                res *= list[i];
                count += 1;
            }
        }
        if (count == 0)
        {
            printf("Error: No odd numbers");
            mistake = WRONG_VALUE;
        }
        else
            printf("%d", res);
    }
    return mistake;
}

int scan(int *list, int *n)
{
    int check, error_code;
    error_code = NO_ERRORS;
    printf("Input size of list: ");
    check = scanf("%d", n);
    if (check != 1)
    {
        printf("Error: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else if ((*n > 10) || (*n < 1))
    {
        printf("Error: Incorrect value");
        error_code = WRONG_VALUE;
    }
    else
    {
        printf("Input elements: \n");
        for (int i = 0; i < *n; i++)
        {
            check = scanf("%d", list + i);
            if (check != 1)
            {
                printf("Error: Incorrect type");
                error_code = WRONG_TYPE;
                break;
            }
        }
    }
    return error_code;
}