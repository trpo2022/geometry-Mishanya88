#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int error_code(char str[])
{
    char* figure = strstr(str, "circle");
    if (figure == NULL) {
        printf("Error at column 0: expected 'circle'\n\n");
        return 1;
    }
    for (int i = 0; i < 100; i++) {
        if (str[i] == '(') {
            i++;
            while (str[i] != ')') {
                if (str[i + 1] == '\0' && str[i] != ')') {
                    printf("Error at column %d: expected ) \n\n", i);
                    return 3;
                }
                if (isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != ','
                    && str[i] != '.') {
                    printf("Error at column %d: expected <double>\n\n", i);
                    return 2;
                }
                i++;
                if (str[i] == '\0') {
                    break;
                }
            }
        }
        if (str[i + 2] == '\0' && str[i] != ')') {
            printf("Error at column %d: expected ) \n\n", i);
            return 3;
        }

        if (str[i] == ')' && str[i + 2] != '\0') {
            if (str[i + 1] == ' ' && str[i + 3] == '\0') {
                break;
            }
            printf("%c", str[i + 1]);
            printf("Error at column %d: unexpected token \n\n", i);
            return 4;
        }
        if (str[i] == '\0') {
            break;
        }
    }

    return 5;
}

double pars_strok(char str[])
{
    // double x, y, rad;
    double rad;
    // char *probel_x, *probel_y, *probel_radius;
    char* probel_radius;
    for (int i = 0; i < 100; i++) {
        if (str[i - 1] == '(')
            // probel_x = &str[i];
            if (str[i - 1] == ',')
                probel_radius = &str[i];
        if (str[i + 1] == '\0')
            break;
    }
    // x = strtod(probel_x, &probel_y);
    // y = strtod(probel_y, NULL);
    rad = strtod(probel_radius, NULL);
    return rad;
}
int main()
{
    char str[100];
    double n = 0, perimeter = 0, area = 0;
    fgets(str, 100, stdin);
    printf("%s", str);
    if (error_code(str) == 5) {
        n = pars_strok(str);
        perimeter = 2 * M_PI * n;
        area = M_PI * pow(n, 2);
        printf("perimeter = %f\n", perimeter);
        printf("area = %f", area);
    }
}