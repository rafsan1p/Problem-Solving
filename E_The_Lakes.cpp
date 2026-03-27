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


int n, m;
vector<vector<int>> v;
vector<vector<bool>> vis;

int dfs(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || v[r][c] == 0){
        return 0;
    }
    vis[r][c] = true;
    int vol = v[r][c];

    vol += dfs(r+1, c);
    vol += dfs(r-1, c);
    vol += dfs(r, c+1);
    vol += dfs(r, c-1);

    return vol;
}

void solve(){
    cin >> n >> m;
    v.assign(n, vector<int>(m, 0));
    vis.assign(n, vector<bool>(m, false));

    read(i, 0, n){
        read(j, 0, m){
            cin >> v[i][j];
        }
    }
    int max_volume = 0;
    read(i, 0, n){
        read(j, 0, m){
            if(!vis[i][j] && v[i][j] > 0){
                max_volume = max(max_volume, dfs(i, j));
            }
        }
    }
    cout << max_volume << "\n";
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