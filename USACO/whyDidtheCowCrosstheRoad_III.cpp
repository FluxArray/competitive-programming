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
	freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> cow(n);
	for (int i = 0; i < n; i++)
		cin >> cow[i].first >> cow[i].second;
	sort(all(cow));
	int wait = 0;
	for (int i = 0; i < n - 1; i++) {
		wait = cow[i].first + cow[i].second;
		if (wait > cow[i + 1].first)
			cow[i + 1].first = wait;
	}
	wait = cow[n - 1].first + cow[n - 1].second;
	cout << wait << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
