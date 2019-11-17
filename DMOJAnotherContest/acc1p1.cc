#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>

using namespace std;

#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64 
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16) 
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) };

int reverse(unsigned int n) {
    int r = 0;
    
    r = lookuptable[ n & 0xff ]<<24 |  
   lookuptable[ (n >> 8) & 0xff ]<<16 |  
   lookuptable[ (n >> 16) & 0xff ]<< 8 | 
   lookuptable[ (n >> 24) & 0xff ];
    
    return r; 
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    char str[N];
    scanf("%s", str);
    string c = str;
    unsigned int b = strtol(str, 0, 2);
    
    size_t i, l;
    for (int j = 0, q; j < Q; j++) {
        scanf("%d %d %d", &q, &i, &l);
        if (q == 1) {
            int toRev = reverse(strtol(c.substr(i, l).c_str(), 0, 2));
            c = c.substr(0, i) + bitset<l>(toRev).to_string() + c.substr(i+l);
            b = strtol(c.c_str(), 0, 2);
        } else {
            int count = 0;
            while (b != 0) {
                b = b & (b << 1);
                count++;
            }
            printf("%d\n", count);
        }
        b = strtol(str, 0, 2);
    }
}