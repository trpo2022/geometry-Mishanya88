#include <ctype.h>
#include <geo.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    int n = 0;
    struct figure* a;
    a = (struct figure*)malloc(1000 * sizeof(struct figure));
    double perimeter, area;
    while (1) {
        if (fgets(str, 100, stdin) == NULL)
            break;
        if (strcmp(str, "\n") == 0)
            break;
        if (error_code(str, n, a) != 5)
            break;
        else
            pars_strok(str, n, a);
        n++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d. %s", i + 1, a[i].Name_full);
        perimeter = 2 * M_PI * a[i].r;
        area = M_PI * pow(a[i].r, 2);
        printf("perimeter = %f\n", perimeter);
        printf("area = %f\n", area);
        intersection(i, a, n);
    }
    free(a);
    return 0;
}
