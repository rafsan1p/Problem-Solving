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
#define printvec(x) for(auto it: ans) {cout << it << " ";} cout << "\n"


void solve(){
    int n, root;
    cin >> n;
    vector<int> g[n+1], bad_child(n+1), a(n+1);
    read(i, 1, n+1){
        int p, c;
        cin >> p >> c;
        int u = p, v = i;
        if(u != -1){
            g[u].push_back(v);
        }else{
            root = i;
        }
        if(c == 1){
            bad_child[u]++;
            a[v] = 1;
        }
    }
    vector<int> ans;
    read(i, 1, n+1){
        if(root == i) continue;

        if(g[i].size() == bad_child[i] && a[i] == 1){
            ans.push_back(i);
        }
    }
    if(ans.empty()){
        cout << "-1\n";
    }
    else printvec(ans);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}