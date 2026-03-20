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
    int x; cin >> x;
    
    vector<int> v;
    while(x > 0){
        if(x % 2 == 0){
            v.push_back(0);
            x /= 2;
        }
        else{
            if(x % 4 == 1){
                v.push_back(1);
                x = (x - 1) / 2;
            }else{
                v.push_back(-1);
                x = (x + 1) / 2;
            }
        }
    }
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
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