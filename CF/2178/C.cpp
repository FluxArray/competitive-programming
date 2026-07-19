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

    vector<int> ps(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        ps[i] = ps[i + 1] + a[i];
    }

    int x = -INF;
    int rnd = 0;
    for (int k = 0; k < n; k++) {
        int score = 0;

        if (k == 0)
            score = -ps[1];
        else
            score = a[0] + rnd - ps[k + 1];
        
        x = max(x, score);
        if (k > 0) {
            rnd += abs(a[k]);
        }
    }

    cout << x << '\n';
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}