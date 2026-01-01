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

	map<int, int> divi;
	int ps = 0;
	int ans = 0;
	divi[0] = 1;
	for (int i = 0; i < n; i++) {
		ps += a[i];
		int t = ps % n;
		if (t < 0)
			t = n + t;

		ans += divi[t];
		divi[t]++;
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