#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define read(i, a, b) for (int i = a; i < b; i++)
#define rread(i, a, b) for (int i = a; i >= b; i--)
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define printvec(x) for(auto it: v) cout << it << " "

vector<vector<int>> adj;
vector<int> leaf;

void dfs(int node, int parent){
    bool is_leaf = true;
    leaf[node] = 0;

    for(int child : adj[node]){
        if(child != parent){
            is_leaf = false;
            dfs(child, node);
            leaf[node] += leaf[child];
        }
    }
    if(is_leaf){
        leaf[node] = 1;
    }
}

void solve(){
    int n; cin >> n;
    adj.assign(n+1, vector<int>());
    leaf.assign(n+1, 0);

    read(i, 0, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int q; cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << leaf[x] * leaf[y] << "\n";
    }
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