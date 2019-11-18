#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <bitset>

using namespace std;

#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64 
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16) 
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) };

int reverse(unsigned int n, int l) {
    int r = 0;
    
    int size = l / 8;
    for (int i = 0; i < size; i++) {
        r |= lookuptable[(n >> (i * 8)) & 0xff] << ((size - i) * 8);
    }
    
    int remainder = (8- (l % 8)) - (l % 2);
    
    r >>= (remainder + (l % 2));
    r |= lookuptable[(n << (remainder/2)) & 0xff] >> (remainder/2);
    
    return r; 
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    char str[N];
    scanf("%s", str);
    string s = str;
    unsigned int b = strtol(str, 0, 2);
    
    for (int j = 0, q, i, l; j < Q; j++) {
        scanf("%d %d %d", &q, &i, &l);
        if (q == 1) {
            int val = strtol(s.substr(i, l).c_str(), 0, 2);
            string bits = bitset<32>(reverse(val, l)).to_string();
            string end = (i+l<N) ? s.substr(i+l) : "";
            s = s.substr(0, i) + bits.substr(32-i) + end;
            b = strtol(s.c_str(), 0, 2);
        } else {
            int count = 0;
            while (b != 0) {
                b = b & (b << 1);
                count++;
            }
            printf("%d\n", count);
        }
    }
}