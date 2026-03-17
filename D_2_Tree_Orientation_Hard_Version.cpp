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
#define printvec(v) for(auto it: v) cout << it << " "

void solve(){
    int n; cin >> n;
    vector<string> v(n);
    vector<int> sz(n, 0);

    read(i, 0, n){
        cin >> v[i];
        read(j, 0, n){
            if(v[i][j] == '1'){
                sz[i]++;
            }
        }
    }

    vector<pair<int, int>> edges;
    vector<int> active(n, 0);

    read(i, 0, n){
        vector<int> reach;
        read(j, 0, n){
            if(i != j && v[i][j] == '1'){
                reach.push_back(j);
                active[j] = 1;
            }
        }
        sort(all(reach), [&](int a, int b){
            return sz[a] > sz[b];
        });

        for(int w : reach){
            if(active[w]){
                edges.push_back({i, w});
                read(x, 0, n){
                    if (v[w][x] == '1'){
                        active[x] = 0;
                    }
                }
            }
        }
        for(int j : reach){
            active[j] = 0;
        }
    }
    if(edges.size() != n - 1){
        no;
        return;
    }

    vector<vector<int>> undirected_adj(n);
    vector<vector<int>> directed_adj(n);

    for(auto e : edges){
        undirected_adj[e.first].push_back(e.second);
        undirected_adj[e.second].push_back(e.first);
        directed_adj[e.first].push_back(e.second);
    }

    vector<int> vis_undirected(n, 0);
    vector<int> q(n);
    int head = 0, tail = 0;
    
    q[tail++] = 0;
    vis_undirected[0] = 1;
    int comp_sz = 1;

    while(head < tail){
        int u = q[head++];
        for(int next : undirected_adj[u]){
            if(!vis_undirected[next]){
                vis_undirected[next] = 1;
                q[tail++] = next;
                comp_sz++;
            }
        }
    }
    if(comp_sz != n){
        no;
        return;
    }

    vector<int> vis(n, 0);
    int curr_vis = 0;

    read(i, 0, n){
        curr_vis++;
        int reached_count = 0;
        bool valid = true;

        auto dfs = [&](auto& self, int u) -> void{
            vis[u] = curr_vis;
            reached_count++;
            for(int nxt : directed_adj[u]){
                if(vis[nxt] != curr_vis){
                    if(v[i][nxt] == '0'){
                        valid = false;
                        return;
                    }
                    self(self, nxt);
                    if(!valid) return;
                }
            }
        };
        if(v[i][i] == '0') {
            no;
            return;
        }
        dfs(dfs, i);

        if(!valid || reached_count != sz[i]){
            no;
            return;
        }
    }
    yes;
    for(auto e : edges){
        cout << e.first + 1 << " " << e.second + 1 << "\n";
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