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
    int n;
    string s;
    cin >> n >> s;

    int diff = 0;
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n - i - 1]){
            diff++;
        }
    }

    string ans = "";
    for (int i = 0; i <= n; i++){
        int extra_flips = i - diff;
        int max_extra = (n / 2 - diff) * 2 + (n % 2);

        if(extra_flips >= 0 && extra_flips <= max_extra) {
            if(n % 2 != 0 || extra_flips % 2 == 0){
                ans += '1';
            }else{
                ans += '0';
            }
        }else{
            ans += '0';
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