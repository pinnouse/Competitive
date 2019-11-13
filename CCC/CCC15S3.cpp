///CREDIT: https://dmoj.ca/problem/ccc15s3/editorial
#include <cstdio>

using namespace std;

int G, P;
int main() {
    scanf("%d%d", &G, &P);
    
    //Initialize a set of ints to store our gates
    set<int> gates;

    //Initialize set with gate values
    for(int i = 1; i <= G; i++)
      gates.insert(-i);

    //Planes loop
    for(int i = 0, p; i < P; i++) {
      scanf("%d", &p);
      //The plane cannot find a gate or is the last gate
      if (gates.lower_bound(-p) == gates.end()) {
        printf("%d\n", i);
        return 0;
      }

      //Erase gates larger than p from our gates so no
      //planes can get to those gates
      gates.erase(gates.lower_bound(-p));
    }

    //Reach the end - all planes have found a gate
    printf("%d", P);
    return 0;
}
