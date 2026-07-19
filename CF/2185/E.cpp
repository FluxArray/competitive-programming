#include <algorithm>
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(all(a));
    sort(all(b));

    string s;
    cin >> s;
    
    int max_l = 0;
    int max_r = 0;
    int pos = 0;

    vector<vector<int>> rd(k + 2);
    vector<vector<int>> ld(k + 2);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(b), a[i]);

        if (it != b.end()) {
            int d_right = *it - a[i];
            if (d_right <= k) {
                rd[d_right].pb(i);
            }
        }

        if (it != b.begin()) {
            int d_left = a[i] - *(it - 1);
            if (d_left <= k) {
                ld[d_left].pb(i);
            }
        }
    }

    int alive = n;
    vector<int> death(n, false);

    for (int i = 0; i < k; i++) {
        if (s[i] == 'L')
            pos--;
        else
            pos++;


        if (-pos > max_l) {
            max_l = -pos;
            if (max_l <= k) {
                for (int i : ld[max_l]) {
                    if (!death[i]) {
                        death[i] = true;
                        alive--;
                    }
                }
            }
        }

        if (pos > max_r) {
            max_r = pos;
            if (max_r <= k) {
                for (int i : rd[max_r]) {
                    if (!death[i]) {
                        death[i] = true;
                        alive--;
                    }
                }
            }
        }

        cout << alive << ' ';
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