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
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> ashu(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		ashu[--u]++;
	}

	int ans = 0;
	int store_ans = 0;
	for (int i = 0; i < n; i++) {
		if (ashu[i] == 0) {
			ans++;
			store_ans = i+1;
		}
	}

	if (ans == 1){
		cout << store_ans << '\n';
	} else {
		cout << -1 << endl;
	}
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}