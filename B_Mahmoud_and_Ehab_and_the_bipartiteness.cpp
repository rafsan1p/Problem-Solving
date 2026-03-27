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

const int mx = 1e5 + 5;
vector<int> g[mx], color(2, 0);

void dfs(int node, int parent, int c){
    color[c]++;
    for(int child : g[node]){
        if(child != parent){
            dfs(child, node, !c);
        }
    }
}

void solve(){
    int n; cin >> n;
    read(i, 0, n-1){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    int max_edges = color[0] * color[1];
    int ans = max_edges - (n-1);
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}