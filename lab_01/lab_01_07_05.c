#include<stdio.h>
#include<math.h>

#define NO_ERRORS 0
#define WRONG_TYPE 1
#define WRONG_VALUE 2

double get_f(double);
double get_s(double, double);

int main()
{
    setbuf(stdout, NULL);
    double x, eps, f, s, abs_error, rel_error;
    int error_code = NO_ERRORS;

    int check_1 = scanf("%lf", &x);

    int check_2 = scanf("%lf", &eps);
    if (check_1 != 1 || check_2 != 1)
    {
        printf("Error: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else if (fabs(x) >= 1 || 0 >= eps || eps > 1)
    {
        printf("Error: Incorrect value");
        error_code = WRONG_VALUE;
    }
    else
    {
        f = get_f(x);
        s = get_s(x, eps);
        abs_error = fabs(f - s); // Абсолютная погрешность
        rel_error = abs_error / fabs(f); // Относительная погрешность
        printf("s(x) = %.6lf\n", s);
        printf("f(x) = %lf\n", f);
        printf("absolute error = %.6lf\n", abs_error);
        printf("relative error = %.6lf", rel_error);
    }
    return error_code;
}

// Функция находит f
double get_f(double x)
{
    double f;
    f = 1.0 / (sqrt(1.0 - x * x));
    return f;
}

// Функция находит s
double get_s(double x, double eps)
{
    double s, s_temp;
    s = 1.0; // Сумма последовательности
    s_temp = (x * x) / 2.0; // Элемент последовательности
    double n = 1.0; // Целое число в элементе последовательности
    while (fabs(s_temp) >= eps)
    {
        s += s_temp;
        n += 2.0;
        s_temp *= x * x * n / (n + 1.0);
    }
    return s;
}