#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <string.h>
double PI = 3.141592;
int error_code(char str[])
{
    char* figure = strstr(str, "circle");
    if (figure == NULL) {
        printf("Error at column 0: expected 'circle'\n\n");
    } else {
        return 1;
    }
}

double pars_strok(char str[])
{
    double x = 0, y = 0, rad;
    char probel_x, probel_y, probel_radius;
    for (int i = 0; i < 100; i++) {
        if (str[i - 1] == '(')
            probel_x = &str[i];
        if (str[i - 1] == ',')
            probel_radius = &str[i];
        if (str[i + 1] == '\0')
            break;
    }
    x = strtod(probel_x, &probel_y);
    y = strtod(probel_y, NULL);
    rad = strtod(probel_radius, NULL);
    return rad;
}
int main()
{
    char str[100];
    double n = 0, perimeter = 0, area = 0;
    gets(str);
    if (error_code(str) == 1) {
        n = pars_strok(str);
        perimeter = 2 * PI * n;
        area = PI*pow(n, 2);
        printf("perimeter = %f\n", perimeter);
        printf("area = %f", area);
    }
}
