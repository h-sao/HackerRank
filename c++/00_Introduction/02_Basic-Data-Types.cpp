#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int x0;
    long x1;
    char x2;
    float x3;
    double x4;
    scanf("%d %ld %c %f %lf", &x0, &x1, &x2, &x3, &x4);

    printf("%d\n%ld\n%c\n%.03f\n%.09lf", x0, x1, x2, x3, x4);

    return 0;
}
