#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    string r;
    cin >> r;

    int n = r.length();
    int ops = 0;
    if (r[0] == 'u') {
        r[0] = 's';
        ops++;
    }

    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        ops++;
    }
    
    for (int i = 1; i < n - 1; ++i) {
        if (r[i] == 'u' && r[i - 1] == 'u') {
            r[i] = 's';
            ops++;
        }
    }
    cout << ops << "\n";
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}