#include <stdio.h>

#define SIZE 20
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define NO_ERRORS 0

int scan(int*, int*);
void insert(int*, int*, int, int*, int*, int*);
void print(int*, int);

int main(void)
{
    int list[SIZE];
    int n, mistake;
    n = 0;
    mistake = scan(list, &n);
    if (!mistake)
    {
        int cnt, fib1, fib2;
        int *p_fib1, *p_fib2, *p_cnt, *amount;
        fib1 = 0;
        fib2 = 1;
        cnt = 0;
        p_fib1 = &fib1;
        p_fib2 = &fib2;
        p_cnt = &cnt;
        amount = &n;
        for (int i = 0; i < *amount; i++)
        {
            if (list[i] % 3 == 0)
            {
                insert(list, amount, i, p_cnt, p_fib1, p_fib2);
                i += 1;
            }
        }
        print(list, n);
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

void insert(int *list, int *amount, int i, int *p_cnt, int *p_fib1, int *p_fib2)
{
    *amount += 1;
    for (int j = 0; *amount - j - 1 > i; j++)
        list[(*amount) - j] = list[*(amount) - j - 1];
    if (*p_cnt % 2 == 0)
    {
        list[i + 1] = *p_fib1;
        *p_fib1 += *p_fib2;
        *p_cnt += 1;
    }
    else
    {
        list[i + 1] = *p_fib2;
        *p_fib2 += *p_fib1;
        *p_cnt += 1;
    }
}

void print(int *list, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
}