#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    int total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += abs(a[i] - a[i+1]);
    }

    int r = 0;
    for (int i = 1; i < n - 1; i++) {
        int oc = abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]);
        int nc = abs(a[i-1] - a[i+1]);
        int red = oc - nc;
        r = max(r, red);
    }

    r = max(r, abs(a[0] - a[1]));
    r = max(r, abs(a[n-2] - a[n-1]));
    cout << total - r << endl;
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}