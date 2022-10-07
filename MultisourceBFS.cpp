#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<int> *gr;
    int n;
    vector<int> viz; ///vector de vizitati pentru graf
    vector<int> dist; ///vector de distante pentru graf
    
public:
    Graph(vector<int> *gr_, int n_): gr(gr_), n(n_) {
        viz.resize(n + 1, 0);
        dist.resize(n + 2, 0);
    }

    ///parcurgere basic BFS, cu retinerea distantei
    void Multisource_BFS(queue<int>q) {
        while(!q.empty()) {
            int k = q.front();
            q.pop();
            for(auto i:gr[k]) {
                if(!viz[i]) {
                    q.push(i);
                    dist[i] = dist[k] + 1;
                    viz[i] = true;
                }
            }
        }
    }

    ///functia pentru rezolvarea problemei
    vector<int> nearestTown(int n,int *sources,int s) {
        queue<int> q;
        for(int i = 0;i < s; i++) {
            ///punem in queue punctele de start date
            q.push(sources[i]);
            viz[sources[i]]=true;
        }
        ///incepem BFS-ul din punctele respective
        Multisource_BFS(q);
        return dist;
    }
};

int main() {
    ifstream f("graf.in");
    ofstream g("graf.out");

    int n, m;
    cin >> n >> m;
    ///citirea datelor

    vector<int> graph[n + 1];
    vector<int> dist(n + 1, 0);
    ///intializarea tipurilor de date necesare

    for(int x, y, i = 1; i <= m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        ///citirea grafului sub forma de lista de adiacenta
    }

    Graph graf(graph, n);
    ///crearea obiectului de tip Graph
    int sources[] = {8, 9};

    int S = sizeof(sources) / sizeof(sources[0]);

    dist = graf.nearestTown(n, sources, S);
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}
