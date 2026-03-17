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


void solve(){
    int n; cin >> n;
    vector<int> v(n);

    read(i, 0, n){
        cin >> v[i];
    }
    bool flag = false;
    for(int mask = 0; mask < (1 << n); mask++){
        int sum = 0;
        for(int k = 0; k < n; k++){
            if((mask >> k) & 1){
                sum += v[k];
            }
            else{
                sum -= v[k];
            }
        }
        if(sum % 360 == 0){
            flag = true;
            break;
        }
    }
    if(flag) yes;
    else no;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}