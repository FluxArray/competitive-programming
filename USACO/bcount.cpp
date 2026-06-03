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
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n, q;
	int b1 = 0, b2 = 0, b3 = 0;
	cin >> n >> q;

	vector<int> pref1(n + 1);
	vector<int> pref2(n + 1);
	vector<int> pref3(n + 1);


	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;

		if (n == 1) {
			pref1[i + 1] = pref1[i] + 1;
			pref2[i + 1] = pref2[i];
			pref3[i + 1] = pref3[i];
		}
		if (n == 2) {
			pref2[i + 1] = pref2[i] + 1;
			pref1[i + 1] = pref1[i];
			pref3[i + 1] = pref3[i];
		}
		if (n == 3) {
			pref3[i + 1] = pref3[i] + 1;
			pref1[i + 1] = pref1[i];
			pref2[i + 1] = pref2[i];
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		cout << pref1[r] - pref1[l - 1] << ' ';
		cout << pref2[r] - pref2[l - 1] << ' ';
		cout << pref3[r] - pref3[l - 1] << endl;
	}
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}