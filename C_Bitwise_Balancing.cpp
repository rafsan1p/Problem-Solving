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

bool kth_bit_on(int n, int k){
    return ((n >> k) & 1);
}

int turn_on_kth_bit(int n, int k){
    return (n | (1LL << k));
}

int turn_off_kth_bit(int n, int k){
    return (n & (~(1LL << k)));
}


void solve(){
    int a = 0, b, c, d;
    cin >> b >> c >> d;
    a = b;
    int msb = max({__lg(b), __lg(c), __lg(d)});
    
    for(int k = 0; k <= msb; k++){
        if(!kth_bit_on(b, k) && kth_bit_on(d, k)){
            a = turn_on_kth_bit(a, k);
        }
        if(kth_bit_on(c, k) && kth_bit_on(d, k)){
            a = turn_off_kth_bit(a, k);
        }
    }
    if((a | b) - (a & c) == d){
        cout << a << "\n";
    }else{
        cout << -1 << "\n";
    }
    
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