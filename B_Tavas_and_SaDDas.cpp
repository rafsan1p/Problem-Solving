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
    string s; cin >> s;
    int l = s.size();
    int val1 = (1LL << l) - 2;
    int val2 = 0;
    for(char c : s){
        val2 = val2*2 + (c == '7' ? 1 : 0);
    }
    cout << val1 + val2 + 1 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}

/*
 * MATHEMATICAL PROOF FOR: ans = (1LL << L) - 2
 * ---------------------------------------------
 * To find the total number of lucky numbers with length less than L, 
 * we sum the possible lucky numbers for each length from 1 to L-1:
 * Sum = 2^1 + 2^2 + 2^3 + ... + 2^{L-1}
 * This is a Geometric Progression (GP) where:
 * First term (a) = 2, Common ratio (r) = 2, Number of terms (n) = L - 1
 * GP Sum Formula: S = a(r^n - 1) / (r - 1)
 * Sum = 2 * (2^{L-1} - 1) / (2 - 1)
 * Sum = (2 * 2^{L-1}) - (2 * 1)
 * Sum = 2^L - 2
 * Conclusion: Instead of a O(L) loop, we compute this in O(1) 
 * using bitwise left shift: (1LL << L) - 2
 */
