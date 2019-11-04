#include <stdio.h>

using namespace std;

int main() {
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    
    int least = -1, index = 1;
    for (int i = 0; i < N; i++) {
        int num;
        int howmany = 0;
        int j = 0;
        char temp;
        do {
            scanf("%d%c", &num, &temp);
            if (num == 1 || num == 10)
                howmany++;
            j++;
        } while (temp != '\n');
        
        if (howmany < least || least < 0) {
            least = howmany;
            index = i + 1;
        }
        
    }
    
    printf("%d \r\n", index);
    
    return 0;
}