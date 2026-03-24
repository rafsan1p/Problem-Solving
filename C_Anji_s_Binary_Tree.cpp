#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 3e5+5;
vector<vector<int>> g(maxN);
vector<int> op(maxN);
string s;

void dfs(int u){
    if(g[u][0] != 0){
        int v = g[u][0];
        op[v] = op[u] + (s[u - 1] != 'L');
        dfs(v);
    }
    if(g[u][1] != 0){
        int v = g[u][1];
        op[v] = op[u] + (s[u - 1] != 'R');
        dfs(v);
    }
}

void solve(){
    int n; cin >> n;
    cin >> s;
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }
    op.assign(n + 1, 0);

    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        g[i].push_back(l);
        g[i].push_back(r);
    }

    dfs(1);

    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(g[i][0] == 0 && g[i][1] == 0){
            ans = min(ans, op[i]);
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}