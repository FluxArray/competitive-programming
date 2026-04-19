#include <bits/stdc++.h>
#include <climits>
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
	vector<int> weight(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	int ans = INF;
	for (int mask = 0; mask < (1 << n); mask++) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				sum1 += weight[i];
			else
				sum2 += weight[i];
		}
		ans = min(ans, abs(sum1 - sum2));
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