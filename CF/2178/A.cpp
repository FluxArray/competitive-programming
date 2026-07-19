#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    string s;
    cin >> s;
    int ncount = 0;
    int ycount = 0;
    for (char c : s) {
        if (c == 'N')
            ncount++;
        else
            ycount++;
    }

    if (ycount == 1 || ycount == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}