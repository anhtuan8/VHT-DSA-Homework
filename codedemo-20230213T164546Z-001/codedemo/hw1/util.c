#include "util.h"

void input_string(char *msg, char *str)
{
    printf("%s: ", msg);
    scanf("%[^\n]", str);
    getchar();
}

void input_int(char *msg, int *num)
{
    char str[100];
    printf("%s: ", msg);
    scanf("%s", str);
    getchar();
    *num = atoi(str);
}

void input_float(char *msg, float *num)
{
    char str[100];
    printf("%s: ", msg);
    scanf("%s", str);
    getchar();
    *num = atof(str);
}