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
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	vector<int> store(3);
	for (int i = 0; i < 3; i++)
		cin >> store[i];
	sort(all(store));
	int d1 = store[2] - store[1] - 1;
	int d2 = store[1] - store[0] - 1;
	if (d1 == 0 && d2 == 0)
		cout << 0 << endl;
	else if (d1 == 1 || d2 == 1)
		cout << 1 << endl;
	else
		cout << 2 << endl;
	cout << max(d1, d2) << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}