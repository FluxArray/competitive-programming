#include <algorithm>
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
	int n;
	cin >> n;
	vector<pair<char, int>> baby(n);
	for (int i = 0; i < n; i++) {
		cin >> baby[i].first >> baby[i].second;
	}
	int ans = 1e18;
	for (int i = 0; i < n; i++) {
		int liar = 0;
		for (int j = 0; j < n; j++) {
			if((baby[j].first=='L'&&baby[i].second>baby[j].second)||(baby[j].first=='G'&&baby[i].second<baby[j].second)) {
				liar++;
			}
		}
		ans = min (ans, liar);
	}
	cout << ans << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}