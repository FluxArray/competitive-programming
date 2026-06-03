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
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n;
	cin >> n;

	int ans = 0;
	int ps = 0;
	vector<int> first (7, -1);
	first[0] = 0;

	for (int i = 1; i < n; i++) {
		int cow;
		cin >> cow;
		ps = (ps + cow) % 7;

		if (first[ps] == -1)
			first[ps] = i;
		else
			ans = max(ans, i - first[ps]);
	}
	cout << ans << '\n';
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}