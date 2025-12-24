#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
	int n;
	cin >> n;
	map<pair<string, string>, int> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		string city, state; 
		cin >> city >> state;
		string swty = city.substr(0, 2);

		if (swty != state) {
			count += m[{state, swty}];
			m[{swty, state}]++;
		}
	}
	cout << count << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}