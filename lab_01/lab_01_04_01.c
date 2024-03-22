#include <stdio.h>

void getanswer(int);

int main()
{
    int x;
    printf("Input number of flat: ");
    scanf("%d", &x);
    getanswer(x);
    return 0;
}

void getanswer(int x)
{
    int floor = (x + 3) / 4;
    int entrance = (floor + 8) / 9;
    floor = floor - 9 * (entrance - 1);
    printf("Entrance is %d\n", entrance);
    printf("Floor is %d", floor);
}