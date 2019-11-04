#include <stdio.h>

using namespace std;

int n;
bool map[1000][1000];
int limit;

int lowest = -1;

void test(int tester) {
    if (tester > 0 && (tester < lowest || lowest < 0))
        lowest = tester;
}

int cost(int d, int l, int r) {
    return (d * d) + (l * l) + (r * r);
}

int lowestCost(int x, int y, int d, int l, int r, bool wasleft, bool wasright) {

    if (cost(d, l, r) > lowest && lowest > 0) return 0;

    if (x == n - 1 && y == n - 1) return cost(d, l, r);

    if (l > limit || r > limit) return 0;

    //down
    if (y < n - 1 && map[x][y+1]) test(lowestCost(x, y++, d++, l, r, false, false));

    //right
    if (x < n - 1 && map[x+1][y] && !wasleft) test(lowestCost(x++, y, d, l, r++, false, true));

    //left
    if (x > 1 && map[x-1][y] && !wasright) test(lowestCost(x--, y, d, l++, r, true, false));

    return 0;
}

int main() {

    scanf("%d", &n);

    limit = (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        int j = 0;
        char c;
        do {
            scanf("%c", &c);
            map[i][j] = c == '.';
            j++;
        } while (j < n);
    }

    lowestCost(1, 1, 0, 0, 0, false, false);

    printf("%d\r\n", lowest);

    return 0;
}