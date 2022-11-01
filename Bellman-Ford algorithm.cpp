#include <bits/stdc++.h>
///complexitate O(n*m)
///n = nr de noduri
///m = nr de muchii
///s-a folosit algoritmul Bellman-Ford
#define NMAX 36005
#define pb push_back

using namespace std;

ifstream f("catun.in"); ofstream g("catun.out");

struct nod {
    int y, cost;
};
vector<nod>graph[NMAX];
queue<int>Q;
int viz[NMAX], dmin[NMAX], indicicetati[NMAX], cetati[NMAX], ecetate[NMAX];

///se va lucra cu coada
void bellman_ford(int st) {
    viz[st] = 1;
    Q.push(st);
    ///parcurgerea asemanatoare cu cea BFS
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for(auto &v:graph[x]) {
            if(ecetate[v.y] == 1) continue;
            ///modificarea pentru gasirea unui cost mai mic
            if(dmin[v.y] > dmin[x] + v.cost) {
                indicicetati[v.y] = st;
                dmin[v.y] = dmin[x] + v.cost;
                if(viz[v.y] == 0)
                    Q.push(v.y);
                viz[v.y] = 1;
            }
        }
        viz[x] = 0;
    }
}

int main() {
    int n, m, k;
    f>>n>>m>>k;
    for(int i=1; i<=n; i++) dmin[i] = 0x3f3f3f3f;
    ///datele de intrare
    ///si partea de citire
    for(int i=1; i<=k; i++) {
        f>>cetati[i];
        dmin[cetati[i]] = 0;
        ecetate[cetati[i]] = 1;
    }
    for(int x, y, c, i=1; i<=m; i++) {
        f>>x>>y>>c;
        graph[x].pb({y, c});
        graph[y].pb({x, c});
    }
    ///sortarea vectorului de cetati
    sort(cetati+1, cetati+k+1);

    ///aplicarea Bellman-Ford pentru orice cetate
    for(int i=1; i<=k; i++)
        bellman_ford(cetati[i]);

    ///partea de afisare pentru problema
    for(int i=1; i<=n; i++)
        g<<indicicetati[i]<<" ";
    return 0;
}
