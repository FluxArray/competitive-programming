#include <bits/stdc++.h>
#include <cassert>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;
const int COLORS = 4;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj.at(max(u, v)).pb(min(u, v));
	}

	vector<int> color(n, 1);
	for (int i = 0; i < n; i++) {
		vector<bool> used(COLORS + 1);
		for (int a : adj.at(i)) { used.at(color.at(a)) = true; }
		while (used.at(color.at(i))) { color.at(i)++; }
		cout << color.at(i);
	}
	cout << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}