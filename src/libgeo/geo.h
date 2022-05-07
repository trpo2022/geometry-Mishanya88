#pragma once
typedef struct figure {
    char Name[6];
    char Name_full[15];
    double x, y, r;
} figure;
void pars_strok(char str[], int n, struct figure a[]);
int error_code(char str[], int n, struct figure a[]);
void intersection(int i, struct figure a[], int n);
int input(char str[], struct figure a[]);
double perimeter(struct figure a[], int i);
double area(struct figure a[], int i);