#include <stdio.h>

int main() {
    int n, x, a;
    int sum = 0;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        sum += a;
        if ((i % 2) == 0) {
            sum--;
        }
    }
    if (x >= sum) {
        printf("Yes");
    } else {
        printf("No");
    }
}
