#include <ctype.h>
#include <math.h>
#include <geo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int error_code(char str[], int n, struct figure a[])
{
    char* figur = strstr(str, "circle");
    if (figur == NULL || isalnum(figur[-1])) {
        printf("Error at column 0: expected 'circle'\n\n");
        return 1;
    } else {
        strncpy(a[n].Name, figur, 6);
        strcpy(a[n].Name_full, figur);
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
                    && str[i] != '.' && str[i] != '-') {
                    printf("Error at column %d: expected <double>\n\n", i);
                    printf("Error");
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

void pars_strok(char str[], int n, struct figure a[])
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
    a[n].x = strtod(probel_x, &probel_y);
    a[n].y = strtod(probel_y, NULL);
    a[n].r = strtod(probel_radius, NULL);
}
void intersection(int i, struct figure a[], int n)
{
    for (int j = 0; j < n; j++) {
        if (i != j)
            if ((sqrt(pow((a[i].x - a[j].x), 2) + pow((a[i].y - a[j].y), 2))
                 <= a[i].r + a[j].r)
                && (sqrt(pow((a[i].x - a[j].x), 2) + pow((a[i].y - a[j].y), 2))
                    >= abs(a[i].r - a[j].r)))
                printf("intersects: = %d \n", j + 1);
    }
}