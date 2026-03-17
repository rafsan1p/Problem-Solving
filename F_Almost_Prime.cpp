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
    vector<int> v(n+1, 0);
    vector<bool> is_prime(n+1, true);

    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            for(int j = i; j <= n; j += i){
                is_prime[j] = false;
                v[j]++;
            }
        }
    }
    int ans = 0;
    read(i, 0, n+1){
        if(v[i] == 2) ans++;
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}