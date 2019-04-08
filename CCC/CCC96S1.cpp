#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);
        int total = 0;
        for(int j = 1; j < number; j++) {
            if (number % j == 0) {
                total = total + j;
            }
        }

        if (total > number) {
            printf("%d is an abundant number.\n", number);
        } else if (total < number) {
            printf("%d is a deficient number.\n", number);
        } else {
            printf("%d is a perfect number.\n", number);
        }
    }

    return 0;
}