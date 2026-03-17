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
    int n; cin >> n;
    vector<int> v(n);

    read(i, 0, n){
        cin >> v[i];
    }
    int ans = 1;
    read(b, 0, 20){
        int last = -1, max_gap = 0, has_bit = false;

        read(i, 0, n){
            if((v[i] >> b) & 1){
                max_gap = max(max_gap, i - last);
                last = i;
                has_bit = true;
            }
        }
        if(has_bit){
            max_gap = max(max_gap, n - last);
            ans = max(ans, max_gap);
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