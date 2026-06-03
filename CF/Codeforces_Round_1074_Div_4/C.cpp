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
    int n;
    cin >> n;

    set<int> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.insert(temp);
    }
    
    int max_len = 1;
    int cur_len = 1;

    auto it = a.begin();
    int prev_val = *it;
    it++;

    for (; it != a.end(); it++) {
        int cur_val = *it;
        if (cur_val - prev_val == 1) {
            cur_len++;
        } else {
            max_len = max(max_len, cur_len);
            cur_len = 1; 
        }
        prev_val = cur_val;
    }
    max_len = max(max_len, cur_len);

    cout << max_len << '\n';
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}