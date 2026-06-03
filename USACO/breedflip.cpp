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
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<string> ans;
	string s = "";
	for (int i = 0; i < n; i++) {
		if (b[i] != a[i])
			s += b[i];
		
		else if (b[i] == a[i] && s != "") {
			ans.pb(s);
			s = "";
		}
	}
	cout << ans.size() << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}