#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 1;
    scanf("%d", &n);
    char* s = (char *) malloc(sizeof(char) * n);
    scanf("%s", s);
    char name[][255] = {"Takahashi", "Aoki"};
    for (int i = 0; i < n; i++){
        if (s[i] == '1') {
            if (i % 2 == 0) {
                printf("%s", name[0]);
            } else {
                printf("%s", name[1]);
            }
            break;
        }
    }
    return 0;
}
