#include <stdio.h>
#include <math.h>
// Yanal Omar
// 1230156
// Lecture Section: 2
// Lab Section: 11;
int sumOfEvenDigits(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            sum += digit;
        }
        n /= 10;
    }
    return sum;
}

int find_z(int x, double y) {
    return pow(x, y) +x*y +pow(y, x);
}

float find_res(int n, int x, double y) {
    return sqrt(sumOfEvenDigits(n) + find_z(x, y));
}

int main() {
    int x, n;
    double y;
    FILE *fptr  = fopen("vals.txt", "r");
    fscanf(fptr, "%d %lf %d", &x, &y, &n);
    float res = find_res(n, x, y);
    printf("Result (res): %.2f\n", res);
    fclose(fptr);
    return 0;
}
