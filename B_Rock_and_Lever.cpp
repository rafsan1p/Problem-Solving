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


const int mx = 30;
void solve(){
    int n; cin >> n;
    vector<int> v(mx, 0);

    read(i, 0, n){
        int x; cin >> x;
        v[__lg(x)]++;
    }
    int ans = 0;
    read(i, 0, mx){
        ans += (1LL * v[i] * (v[i] - 1) / 2);
    }
    cout << ans << "\n";
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