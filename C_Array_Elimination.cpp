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
    vector<int> v(n), cnt(31, 0);

    read(i, 0, n){
        cin >> v[i];
        read(j, 0, 31){
            if((v[i] >> j) & 1) cnt[j]++;
        }
    }
    
    read(k, 1, n+1){
        bool flag = true;
        read(j, 0, 31){
            if(cnt[j] % k != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << k << " ";
        }
    }
    cout << "\n";
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