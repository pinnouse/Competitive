#include <bits/stdc++.h>

using namespace std;

int G, P;
int main() {
    scanf("%d%d", &G, &P);
    
    vector<bool> docked;
    for(int i = 1; i <= G; i++)
        docked.push_back(false);
    
    for (int i = 1, p; i < P; i++) {
        cin >> &p;
        if (docked[p]) {
            bool couldDock = 0;
            for (int j = p - 1; j > 0; j--) {
                if (!docked[j]) {
                    docked[j] = 1;
                    couldDock = 1;
                    break;
                }
            }
            if (!couldDock) {
                printf("%d\n", i);
                return 0;
            }
        } else
            docked[p] = 1;
    }
    
    return 0;
}