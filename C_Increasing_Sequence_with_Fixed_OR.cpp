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
#define printdq() for(auto it: dq) cout << it << " "


void solve(){
    int n; cin >> n;
    deque<int> dq;
    for(int k = 0; k <= __lg(n); k++){
        if((n >> k) & 1){
            int val = n - (1LL << k);
            if(val > 0){
                dq.push_front(val);
            }
        }
    }
    dq.push_back(n);
    cout << dq.size() << "\n";
    printdq();
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