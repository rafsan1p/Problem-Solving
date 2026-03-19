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


void solve(){
    int n, m;
    cin >> n >> m;
    
    int L = max(0LL, n - m);
    int R = n + m;
    
    int ans = 0;
    rread(i, 31, 0){
        if((L & (1LL << i)) == (R & (1LL << i))){
            ans |= (L & (1LL << i));
        }else{
            ans |= ((1LL << (i + 1)) - 1);
            break;
        }
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