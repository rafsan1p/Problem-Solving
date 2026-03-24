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
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    read(i, 0, n){
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> freq;
    for(auto it : mp){
        freq.push_back(it.second);
    }
    sort(all(freq));

    int unique = freq.size();
    for(int x : freq){
        if(k >= x){
            k -= x;
            unique--;
        }
        else break;
    }
    cout << max(1LL, unique) << "\n";
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