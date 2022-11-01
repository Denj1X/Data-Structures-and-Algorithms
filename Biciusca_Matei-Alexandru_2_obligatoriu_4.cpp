#include <bits/stdc++.h>
///complexitate O (m * log n)
///n = nr de noduri
///m = nr de muchii
using namespace std;
ifstream f("retea2.in");
ofstream g("retea2.out");

int n, m;
vector < pair< long long, long long>> G;
vector <double> dist(4000, 10000000000.0l);
set < pair< double, int>> S;
///functie pentru calcularea distantei euclidiene
double calcDist(int x1, int y1, int x2, int y2) {
    return sqrt(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
}

///vom folosi algoritmul lui Prim pentru a rezolva problema
void algPrim(vector<int> &viz) {
    double distantaTotala = 0.0;
    int nr = 0;
    while (nr < m) {
        ///poate fi implementata cu set
        ///sau cu priority_queue pe min-heap
        auto element = (*S.begin());
        S.erase(S.begin());
        if (viz[element.second]) continue;
        ///daca nodul e deja vizitat
        ///nu e nevoie de overlapping
        nr++;
        viz[element.second] = 1;
        ///marcam nodul ca vizitat
        distantaTotala += element.first;
        for (int i = n; i < n + m; i++) {
            auto x = G[i];
            ///costul = distanta euclidiana dintre nodul x si G[element.second]
            double cost = calcDist(G[element.second].first, G[element.second].second, x.first, x.second);
            if (viz[i] == 0 && dist[i] > cost) {
                ///punerea in set si actualizarea distantei minime
                S.insert(make_pair(cost, i));
                dist[i] = cost;
            }
        }
    }
    ///afisarea
    g << fixed << setprecision(6) << distantaTotala;
}

int main() {
    f >> n >> m;
    vector < int > viz(n + m + 1, 0);
    for (int x,y,i = 0; i < n+m; i++) {
        f >> x >> y;
        G.push_back(make_pair(x, y));
    }
    ///citirea datelor
    for (int i = n; i < n + m; i++) {
        for (int j = 0; j < n; j++) {
            double aux = calcDist(G[i].first, G[i].second, G[j].first, G[j].second);
            if (aux < dist[i]) dist[i] = aux;
            ///aici determinam distanta minima pentru fiecare bloc
            ///pana la cea mai apropiata centrala
        }
        S.insert(make_pair(dist[i], i));
    }
    ///folsirea functiei cu algoritmul lui Prim
    algPrim(viz);
    g.close();
    return 0;
}
