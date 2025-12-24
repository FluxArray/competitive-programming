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
	int n, k; 
	cin >> n >> k;
	vector<int> d(n);
	for (int i =0; i < n; i++)	
		cin >> d[i];

	int ans = k+1;
	for (int i =0 ; i < n - 1; i++) {
		int diff = d[i + 1] - d[i];
		int ec = diff;
		int nc = k + 1;
		ans += min(nc, ec);
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