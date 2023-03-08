#include <stdio.h>
#include <math.h>


int main()
{
    float x, y, x2, y2, a, b, c, dist;
    char input1, input2;
    scanf("%c", &input1);
    if (input1 == 'P')
    {
        scanf("%f", &x);
        scanf("%f", &y);
        scanf(" %c", &input2);
        if (input2 == 'P')
        {
            scanf("%f", &x2);
            scanf("%f", &y2);
            dist = sqrt((pow(x2 - x, 2) + pow(y2 - y, 2)));
        }
        else if (input2 == 'R')
        {
            scanf("%f", &a);
            scanf("%f", &b);
            scanf("%f", &c);
            dist = sqrt(pow(((a * x) + (b * y) + c), 2)) / sqrt(pow(a, 2) + pow(b, 2));
        }
    }
    else if (input1 == 'R')
    {
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);
        do
        {
            scanf(" %c", &input2);
        } while (input2 != 'P');
        scanf("%f", &x);
        scanf("%f", &y);
        dist = sqrt(pow(((a * x) + (b * y) + c), 2)) / sqrt(pow(a, 2) + pow(b, 2));
    }
    printf("%.2lf", dist);
    return 0;
}

