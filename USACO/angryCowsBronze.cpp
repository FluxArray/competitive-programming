#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

int n;
vector<int> julu;
int exploded(int start, int dir) {
    int radius = 1;
    int prev = start;
    while(true) {
        int next = prev;
        while(next + dir >= 0 && next + dir < n &&
            abs(julu[next + dir] - julu[prev]) <= radius) {
            next += dir;
        }

        if (next == prev) break;
        prev = next;
        radius++;
    }
    return abs(prev - start);
}

void solve() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n;
    julu.resize(n);
    for (int i = 0; i < n; i++)
        cin >> julu[i];
    sort(all(julu));
    int explosion = 0;
    for (int i = 0; i < n; i++)
        explosion = max(explosion, exploded(i, -1) + exploded(i, 1) + 1);
    cout << explosion << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
