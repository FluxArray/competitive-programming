#include <atomic>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> p(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    if (x + y < sum) {
        cout << "NO" << endl;
        return;
    }

    int nx = 0;
    int ny = 0;
    bool achad = false;
    bool bchad = false;

    for (int i = 0; i < n; i++) {
        int minvotes = (p[i] / 2) + 1; //minimum amount of majority votes for a or b needs to win
        if (s[i] == '0') {
            nx += minvotes;
            achad = true;
        } else {
            ny += minvotes;
            bchad = true;
        }
    }

    if (x < nx || y < ny) {
        cout << "NO" << endl;
        return;
    }

    if (bchad == false) {
        if (x < y + n) {
            cout << "NO" << endl;
            return;
        }
    }
    if (achad == false) {
        if (y < x + n) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}