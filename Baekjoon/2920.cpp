#include<stdio.h>

int a, b;

int main() {
    for (int i = 0; i < 8; i++) {
        scanf("%d", &a);
        b = b * 10 + a;
    }
    printf("%s", b == 12345678 ? "ascending" : b == 87654321 ? "descending" : "mixed");
}