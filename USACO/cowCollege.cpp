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
	vector<int> fee(n);
	for (int i = 0; i < n; i++) 
		cin >> fee[i];
	sort(all(fee));

	int ans = 0;
	int store = 0;

	for (int i = 0; i < n; i++) {
		int money = fee[i];
		int temp = money * (n - i);
		if (temp > ans) {
			ans = temp;
			store = fee[i];
		}
	}
	cout << ans << " " << store << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
