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
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	a1--; a2--; b1--; b2--;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);

	set <vector<int>> visited{v};

	while (true) {
		reverse(v.begin() + a1, v.begin() + a2 + 1);
		reverse(v.begin() + b1, v.begin() + b2 + 1);
		if (visited.count(v)) { break; }
		visited.insert(v);
	}

	int cycle_len = visited.size();
	int swaps_left = k % cycle_len;
	for (int s = 0; s < swaps_left; s++) {
		reverse(v.begin() + a1, v.begin() + a2 + 1);
		reverse(v.begin() + b1, v.begin() + b2 + 1);
	}
	for (int c : v) { cout << c << '\n'; }
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}