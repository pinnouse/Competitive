///CREDIT: https://dmoj.ca/problem/ccc15s3/editorial
#include <cstdio>

using namespace std;

int G, P;
int main() {
    scanf("%d%d", &G, &P);
    
    //Binary tree
    set<int> gates;

    //Initialize binary tree of gates
    for(int i = 1; i <= G; i++)
      gates.insert(-i);

    //Planes loop
    for(int i = 0, p; i < P; i++) {
      scanf("%d", &p);
      //Reached the lower limit of gates
      if (gates.lower_bound(-p) == gates.end()) {
        printf("%d\n", i);
        return 0;
      }

      //Erase gates larger than p
      gates.erase(gates.lower_bound(-p));
    }

    //Reach the end - all planes have found a gate
    printf("%d", P);
    return 0;
}