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


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    read(i, 0, n) {
        cin >> v[i];
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    n = v.size();

    if (n <= 3) {
        cout << 0 << "\n";
        return;
    }

    int low = 0, high = 1e9;
    int ans = 1e9;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cnt = 0, man = 0;
        int i = 0;
        while(i < n && man < 3) {
            man++;
            int curr = v[i] + 2 * mid;
            i = upper_bound(v.begin(), v.end(), curr) - v.begin();
        }
        if (i == n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}