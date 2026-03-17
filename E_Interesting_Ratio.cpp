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


const int mx = 10000005;
vector<int> v;
vector<bool> prime(mx+1, true);

void sieve(){
    prime[0] = false; prime[1] = false;

    for(int i = 2; i <= mx; i++){
        if(prime[i]){
            v.push_back(i);
            for(int j = i*i; j <= mx; j += i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int p : v){
        if(p > n) break;
        ans += (n/p);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}