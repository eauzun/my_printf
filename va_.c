#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

int toplama (int a, ...)
{
    int res = 0;
    int i = 0;
    va_list args;
    va_start(args, a);
    while(i < a)
    {
        res += va_arg(args, int);
        i++;
    }
    return (res);
    va_end(args);

}
#include <stdio.h>

int main()
{
    printf("%d", toplama(5, 2,4,6,8,10));
}