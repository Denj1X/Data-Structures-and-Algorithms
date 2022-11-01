#include <bits/stdc++.h>

using namespace std;

ifstream fin("disjoint.in"); ofstream fout("disjoint.out");
const int N = 1e6 + 5;
int t[N];
///unifica 2 arbori cu radacini x si y
void Union (int x, int y) {
    t[y] = x;
}
/// afla radacina compenentei conexe a lui x
int Find (int x) {
    int root, y;
    root = x;
    while (t[root] != 0) root = t[root];
    /// comprimare drum
    while (x != root) {
        y = t[x];
        t[x] = root;
        x = y;
    }
    return root;
}

void Solve () {
    int n, m;
    ///partea de citire
    fin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int op, x, y;
        fin >> op >> x >> y;
        x = Find(x);
        y = Find(y);
        ///gaseste root-urile pt x si y
        if (op == 1) {
            if (x != y)
                Union(x, y);
                ///face union-ul intre cele doua
        }
        else {
            if (x == y)
                fout << "DA\n";
            else
                fout << "NU\n";
        }
    }
}

int main() {
    Solve();
    return 0;
}
