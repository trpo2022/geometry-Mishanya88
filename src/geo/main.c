#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <geo.h>
int main()
{
    char str[100], buf[100] = {0};
    double arr[3];
    fgets(str, 100, stdin);
    if (error_code(str, buf) == 5) {
        pars_strok(str, arr);
        printf("%s\n", buf);
        printf("x = %.4f\n", arr[0]);
        printf("y = %.4f\n", arr[1]);
        printf("radius = %.4f\n", arr[2]);
    }
    return 0;
}
