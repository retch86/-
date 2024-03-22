#include<stdio.h>
#define NO_ERRORS 0
#define WRONG_TYPE 1
#define WRONG_VALUE 2

int get_coordinates(int, int);
int intersection(int, int, int, int, int, int);
int vector_type(int, int, int, int);
void getanswer(int, int, int, int, int, int, int, int);

int main()
{
    setbuf(stdout, NULL);
    // Координаты точек и результат
    int x1, x2, x3, x4, y1, y2, y3, y4;
    int error_code = NO_ERRORS;
    printf("Input coordinates of point P: ");
    int check_1 = scanf("%d%d", &x1, &y1);
    printf("Input coordinates of point Q: ");
    int check_2 = scanf("%d%d", &x2, &y2);
    printf("Input coordinates of point R: ");
    int check_3 = scanf("%d%d", &x3, &y3);
    printf("Input coordinates of point S: ");
    int check_4 = scanf("%d%d", &x4, &y4);
    // Проверка ввода
    if (check_1 != 2 || check_2 != 2 || check_3 != 2 || check_4 != 2)
    {
        printf("Error: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else if (vector_type(x1, x2, y1, y2) || vector_type(x3, x4, y3, y4))
    {
        printf("Error: Incorrect coordinates");
        error_code = WRONG_VALUE;
    }
    else
    {
        getanswer(x1, x2, x3, x4, y1, y2, y3, y4);
    }
    return error_code;
}

// Функция получает координаты вектора
int get_coordinates(int n1, int n2)
{
    return n1 - n2;
}

// Функция проверяет пересекаются ли отрезки
// Используется косое произведение, условие выполнится, если точки
// Одного отрезка лежат по разные стороны относительно другого
int intersection(int pq_x, int ps_y, int ps_x, int pq_y, int pr_y, int pr_x)
{
    return (pq_x * ps_y - ps_x * pq_y) * (pq_x * pr_y - pr_x * pq_y) < 0;
}

// Проверяется на нулевой отрезок
int vector_type(int x1, int x2, int y1, int y2)
{
    return (x1 == x2 && y1 == y2);
}

void getanswer(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
    int res;    // Резульат
    // Получаем координаты нужных нам векторов
    int pq_x = get_coordinates(x1, x2);
    int pq_y = get_coordinates(y1, y2);
    int rs_x = get_coordinates(x3, x4);
    int rs_y = get_coordinates(y3, y4);
    int ps_x = get_coordinates(x1, x4);
    int ps_y = get_coordinates(y1, y4);
    int pr_x = get_coordinates(x1, x3);
    int pr_y = get_coordinates(y1, y3);
    int rp_x = get_coordinates(x3, x1);
    int rp_y = get_coordinates(y3, y1);
    int rq_x = get_coordinates(x3, x2);
    int rq_y = get_coordinates(y3, y2);
    // Если вектор нулевой выводим сообщение об ошибке
    // Проверяется наличие пересечения, если есть результат 1
    if (intersection(pq_x, ps_y, ps_x, pq_y, pr_y, pr_x) \
        && intersection(rs_x, rp_y, rp_x, rs_y, rq_y, rq_x))
        res = 1;
        // Если отрезки ненулевые и нет пересечения результат 0
    else
        res = 0;
    printf("%d", res);
}