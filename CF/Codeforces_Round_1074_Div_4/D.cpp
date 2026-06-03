#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> a(n);
    vector<int> copy(n);
    vector<int> last(n, -1);
    
    int reset = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        copy[i] = a[i];
    }

    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        b--;

        if (last[b] < reset)
            copy[b] = a[b];

        int border = copy[b] + c;

        if (border > h) {
            reset = i;
        } else {
            copy[b] = border;
            last[b] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (last[i] < reset) {
            cout << a[i] << ' ';
        } else {
            cout << copy[i] << ' ';
        }
    }
    cout << '\n';
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}