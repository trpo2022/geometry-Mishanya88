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

void pars_strok(char str[], double arr[])
{
    char *probel_x, *probel_y, *probel_radius;
    for (int i = 0; i < 100; i++) {
        if (str[i - 1] == '(') {
            probel_x = &str[i];
        }
        if (str[i - 1] == ',') {
            probel_radius = &str[i];
        }
        if (str[i + 1] == '\0')
            break;
    }
    arr[0] = strtod(probel_x, &probel_y);
    arr[1] = strtod(probel_y, NULL);
    arr[2] = strtod(probel_radius, NULL);
}
int main()
{
    char str[100];
    double arr[3];
    fgets(str, 100, stdin);
    if (error_code(str) == 5) {
        pars_strok(str, arr);
        printf("circle\n");
        printf("x = %.4f\n", arr[0]);
        printf("y = %.4f\n", arr[1]);
        printf("radius = %.4f\n", arr[2]);
    }
    return 0;
}
