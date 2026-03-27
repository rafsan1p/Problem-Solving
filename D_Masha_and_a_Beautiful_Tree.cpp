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


int ans = 0;

int dfs(int l, int r, vector<int> &v){
    if(l == r) return v[l];

    int mid = l + (r-l) / 2;
    int max_l = dfs(l, mid, v);
    int max_r = dfs(mid+1, r, v);

    if(max_l == -1 && max_r == -1){
        return -1;
    }

    int half_size = mid - l + 1;
    if(max_r - max_l == half_size){
        return max_r;
    }
    else if(max_l - max_r == half_size){
        ans++;
        return max_l;
    }
    else{
        return -1;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n+1);

    read(i, 1, n+1){
        cin >> v[i];
    }
    ans = 0;
    int res = dfs(1, n, v);
    if(res == -1){
        cout << "-1\n";
    }else{
        cout << ans << "\n";
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