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
    vector<int> res(n), primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    map<int, int> mp;
    int cnt = 0;

    read(i, 0, n){
        read(j, 0, 11){
            if(v[i] % primes[j] == 0){
                if(mp.find(primes[j]) == mp.end()){
                    cnt++;
                    mp[primes[j]] = cnt;
                }
                res[i] = mp[primes[j]];
                break;
            }
        }
    }
    cout << cnt << "\n";
    read(i, 0, n){
        cout << res[i] << " ";
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