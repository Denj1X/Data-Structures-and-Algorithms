#include <bits/stdc++.h>

#include <utility>

using namespace std;

class Graph {
private:
    vector<vector<int>> gr;
    int n;
    vector<int> viz; ///vector de vizitati pentru graf

public:
    Graph(vector<vector<int>> gr_, int n_) : gr(std::move(gr_)), n(n_) {
        viz.resize(n + 1, 0);
    }

    void dfs(int node, int& level, vector<int>& initialLevel, vector<int>& minLevel,
             stack<int>& st, vector<bool>& isInStack,
             vector<vector<int>>& ctc) {
        if(minLevel[node] >= 0){
            return;
        }
        level += 1;
        initialLevel[node] = level;
        minLevel[node] = level;
        st.push(node);
        isInStack[node] = true;
        for(int child: gr[node]){
            dfs(child, level, initialLevel, minLevel, st, isInStack, ctc);
            if(isInStack[child]){
                minLevel[node] = min(minLevel[node], minLevel[child]);
            }
        }

        if(initialLevel[node] == minLevel[node]){
            ctc.push_back({});
            int x = -1;
            do{
                x = st.top();
                st.pop();
                isInStack[x] = false;
                ctc.back().push_back(x);
            }while(x != node);
        }
    }
};

int main() {
//    ifstream f("ctc.in");
//    ofstream g("ctc.out");
    int n, m;
    cin >> n >> m;

    vector<vector<int>> gr(n + 1);
    for(int x, y, i = 1; i <= m; i++) {
        cin >> x >> y;
        gr[x].push_back(y);
    }
    Graph grf(gr, n);

    int level = 0;
    vector<int> initialLevel(n + 1, -1);
    vector<int> minLevel(n + 1, -1);
    stack<int> st;
    vector<bool> isInStack(n + 1, false);
    vector<vector<int>> ctc;

    for(int node = 1; node <= n; ++node){
        if(minLevel[node] < 0){
            grf.dfs(node, level, initialLevel, minLevel, st, isInStack, ctc);
        }
    }

    cout << ctc.size() << "\n";
    for(vector<int>& nodes: ctc){
        for(int node: nodes){
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}
