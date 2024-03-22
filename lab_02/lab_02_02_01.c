#include <stdio.h>
#include <math.h>

#define SIZE 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define NO_ERRORS 0

int scan(int*, int*);
void print(int*, int);
int is_simple(int);

int main(void)
{
    int list_1[SIZE];
    int list_2[SIZE];
    int n, mistake;
    n = 0;
    mistake = scan(list_1, &n);
    if (!mistake)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (is_simple(list_1[i]))
            {
                list_2[j] = list_1[i];
                j += 1;
            }
        }
        if (j == 0)
        {
            printf("Error: No simple numbers");
            mistake = WRONG_VALUE;
        }
        else
            print(list_2, j);
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

void print(int *list, int j)
{
    for (int i = 0; i < j; i++)
        printf("%d ", list[i]);
}

int is_simple(int x)
{
    int vid = 1;
    if (x > 2)
    {
        for (int i = 2; i < sqrt(x) + 1; i++)
        {
            if (x % i == 0)
            {
                vid = 0;
                break;
            }
        }
    }
    else if (x == 2)
        vid = 1;
    else
        vid = 0;
    return vid;
}