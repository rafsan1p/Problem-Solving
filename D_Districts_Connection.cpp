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


void build(int n, vector<int> &v){
    yes;
    int district = -1;
    read(i, 2, n+1){
        if(v[1] != v[i]){
            cout << 1 << " " << i << "\n";
            district = i;
        }
    }
    read(i, 2, n+1){
        if(v[1] == v[i]){
            cout << district << " " << i << "\n";
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n+1);

    read(i, 1, n+1){
        cin >> v[i];
    }
    
    bool flag = false;
    read(i, 2, n+1){
        if(v[1] != v[i]){
            flag = true;
            break;
        }
    }
    if(flag) build(n, v);
    else no;
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