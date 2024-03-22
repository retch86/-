#include<stdio.h>
#include<math.h>

#define WRONG_TYPE 1
#define NO_ERRORS 0

int getanswer(double);

int main()
{
    int error_code = NO_ERRORS;
    int check;
    double x;
    check = scanf("%lf", &x);
    if (check != 1 || x < 0)
    {
        printf("Error: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else
    {
        error_code = getanswer(x);
    }
    return error_code;
}

int getanswer(double x)
{
    int check;
    int error_code = NO_ERRORS;
    double g, sum, n;
    n = 1.0; // Целое число в элементе последовательности
    sum = 0; // Сумма последовательности
    // Пока пользователь вводит X > 0 считаем последовательность
    while (x >= 0 && error_code == NO_ERRORS)
    {
        sum += sqrt(x / n);
        n += 1;
        check = scanf("%lf", &x);
        if (check != 1)
            error_code = WRONG_TYPE;
    }
    if (error_code)
        printf("Error: Incorrect type");
    else
    {
        g = sin(sum); // Находим g
        printf("g = %.6lf", g);
    }
    return error_code;
}
