#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int count = b-a + 1;
    if (count > 0) {
        printf("%d", count);
    } else {
        printf("%d", 0);
    }
}
