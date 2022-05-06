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
    n=input(str, a);
    for (int i = 0; i < n; i++) {
        printf("%d. %s", i + 1, a[i].Name_full);
        printf("perimeter = %f\n", perimeter(a, i));
        printf("area = %f\n", area(a, i));
        intersection(i, a, n);
    }
    free(a);
    return 0;
}
