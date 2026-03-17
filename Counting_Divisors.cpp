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

int divisors[1000001];
void compute(){
    int mx = 1000000;
    for(int i = 1; i <= mx; i++){
        for(int j = i; j <= mx; j += i){
            divisors[j]++;
        }
    }
}

void solve(){
    int x; cin >> x;
    cout << divisors[x] << "\n";   
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    compute();
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}