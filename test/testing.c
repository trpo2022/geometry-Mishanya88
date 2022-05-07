#include "ctest.h"
#include <geo.h>
#include <math.h>
#include <stdlib.h>

CTEST(geometry_suite, input_0)
{
    struct figure a[2];
    char str[100]
            = "cirlce(2 1,10)\n"
              "circle(3 4, 6)\n"
              "\n";
    int exp = 2;
    int real = input(str, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_suite, pars_1)
{
    struct figure a[1];
    char str[100] = "cirlce(2 1,10)";
    int n = 0;
    int exp = 1;
    int real = 0;
    pars_strok(str, n, a);
    if (a[0].x == 2 && a[0].y == 1 && a[0].r == 10)
        real = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_suite, pars_2)
{
    struct figure a[1];
    char str[100] = "cirlce(-3 9,70)";
    int n = 0;
    int exp = 1;
    int real = 0;
    pars_strok(str, n, a);
    if (a[0].x == -3 && a[0].y == 9 && a[0].r == 70)
        real = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_suite, pars_3)
{
    struct figure a[2];
    char str[100] = "cirlce(  -5      100,1)";
    int n = 1;
    int exp = 1;
    int real = 0;
    pars_strok(str, n, a);
    if (a[1].x == -5 && a[1].y == 100 && a[1].r == 1)
        real = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code1_1)
{
    struct figure a[1];
    char str[100] = "cirl(-5 100,1)";
    int n = 0;
    int exp = 1;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code1_2)
{
    struct figure a[1];
    char str[100] = "xcircle(5 20,1)";
    int n = 0;
    int exp = 1;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code2_1)
{
    struct figure a[1];
    char str[100] = "circle(x 20,1)";
    int n = 0;
    int exp = 2;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code2_2)
{
    struct figure a[1];
    char str[100] = "circle(4 =20,1)";
    int n = 0;
    int exp = 2;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code3_1)
{
    struct figure a[1];
    char str[100] = "circle(8 20,2";
    int n = 0;
    int exp = 3;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code3_2)
{
    struct figure a[1];
    char str[100] = "circle(8 20,2(";
    int n = 0;
    int exp = 3;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code4_1)
{
    struct figure a[1];
    char str[100] = "circle(8 20,2)8454905";
    int n = 0;
    int exp = 4;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code4_2)
{
    struct figure a[1];
    char str[100] = "circle(8 20,2)xixixixi";
    int n = 0;
    int exp = 4;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_error, code5_1)
{
    struct figure a[1];
    char str[100] = "circle(-1 -5,10)";
    int n = 0;
    int exp = 5;
    int real = error_code(str, n, a);
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_suite, intersection_1)
{
    struct figure a[2];
    a[0].x = 1;
    a[0].y = 1;
    a[0].r = 3;
    a[1].x = 5;
    a[1].y = 5;
    a[1].r = 4;
    int n = 2;
    int real = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (i != j)
            if ((sqrt(pow((a[i].x - a[j].x), 2) + pow((a[i].y - a[j].y), 2))
                 <= a[i].r + a[j].r)
                && (sqrt(pow((a[i].x - a[j].x), 2) + pow((a[i].y - a[j].y), 2))
                    >= abs(a[i].r - a[j].r)))
                real = 1;
    }
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_suite, intersection_2)
{
    struct figure a[2];
    a[0].x = 1;
    a[0].y = 1;
    a[0].r = 2;
    a[1].x = 5;
    a[1].y = 5;
    a[1].r = 3;
    int n = 2;
    int i = 0;
    int real = 0;
    for (int j = 0; j < n; j++) {
        if (i != j)
            if ((sqrt(pow((a[i].x - a[j].x), 2) + pow((a[i].y - a[j].y), 2))
                 <= a[i].r + a[j].r)
                && (sqrt(pow((a[i].x - a[j].x), 2) + pow((a[i].y - a[j].y), 2))
                    >= abs(a[i].r - a[j].r)))
                real = 1;
    }
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(geometry_suite, perimite_1)
{
    struct figure a[1];
    a[0].r = 5;
    int i = 0;
    const double exp = 31.415926;
    double real = perimeter(a, i);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(geometry_suite, perimite_2)
{
    struct figure a[2];
    a[1].r = 10;
    int i = 1;
    const double exp = 62.831853;
    double real = perimeter(a, i);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(geometry_suite, area_1)
{
    struct figure a[1];
    a[0].r = 5;
    int i = 0;
    const double exp = 78.539816;
    double real = area(a, i);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(geometry_suite, area_2)
{
    struct figure a[2];
    a[1].r = 8;
    int i = 1;
    const double exp = 201.06193;
    double real = area(a, i);
    ASSERT_DBL_NEAR(exp, real);
}