#include <stdio.h>
#include <stdlib.h>

int SumaMenor5(int);
int UltimoDigito(int);

int main() {
    int n = 30;
    printf("sumamenor5 de 891161 = %d", SumaMenor5(891161));
    getchar();getchar();getchar();getchar();
    return 0;
}

int SumaMenor5(int n) {
    if (n <= 9) {
        if (n > 5) {
            return 0;
        } else {
            return n;
        }
    } else {
        if (n%10 > 5) {
            return SumaMenor5(n/10);
        } else {
            return (n%10 + SumaMenor5(n/10));
        }
    }
}