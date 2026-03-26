#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n, m;
    cin >> n >> m;
    map<int, set<int>> g;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int leaf = -1, parentOfLeaf= -1;
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 1){
            leaf = i;
            break;
        }
    }
    int x, y;
    for(int i = 1; i <= n; i++){
        if(g[i].find(leaf) != g[i].end()){
            y = g[i].size() - 1;
            parentOfLeaf = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(g[i].find(parentOfLeaf) != g[i].end() && g[i].size() > 1){
            x = g[i].size();
            break;
        }
    }
    cout << x << " " << y << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}