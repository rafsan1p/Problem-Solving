#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define read(i, a, b) for (int i = a; i < b; i++)
#define rread(i, a, b) for (int i = a; i >= b; i--)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define printvec(x) for(auto it: v) cout << it << " "


const int mx = 1000000;
vector<bool> prime(mx+1, true);

void sieve(){
    prime[0] = false, prime[1] = false;
    for(int i = 2; i*i <= mx; i++){
        if(prime[i]){
            for(int j = i*i; j <= mx; j += i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    int x; cin >> x;
    int root = round(sqrt(x));

    if(root * root == x && prime[root]) yes;
    else no;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}