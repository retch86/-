#include <stdio.h>

#define SIZE 11
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define NO_ERRORS 0

int scan(int*, int*);
int scan_size(int*);
int calc(int*, int*);

int main(void)
{
    int list[SIZE];
    int n, mistake, result;
    n = 0;
    mistake = scan_size(&n);
    if (!mistake)
    {
        int *last = list + n;
        mistake = scan(list, last);
        if (!mistake)
        {
            result = calc(list, last);
            printf("%d", result);
        }
    }
    return mistake;
}

int scan(int *list, int *last)
{
    int error_code = NO_ERRORS;
    int check;
    printf("Input elements: \n");
    for (int *i = list; i != last; i++)
    {
        check = scanf("%d", i);
        if (check != 1)
        {
            printf("Error: Incorrect type");
            error_code = WRONG_TYPE;
            break;
        }
    }
    return error_code;
}

int scan_size(int *n)
{
    int error_code = NO_ERRORS;
    int check;
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
    return error_code;
}

int calc(int *list, int *last)
{
    int sum, res;
    int *i = list;
    sum = 1;
    res = 0;
    do
    {
        sum *= *i;
        res += sum;
        if (*i < 0)
            break;
        i++;
    }
    while (i != last);

    return res;
}
