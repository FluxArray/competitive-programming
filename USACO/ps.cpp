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
	string s;
	cin >> s;
	vector<int> simplified;
	for (int i = 0; i < n; i += 2) {
    	if (s[i] == s[i + 1]) continue;
    	if (s[i] == 'H' && s[i + 1] == 'G') {
        	simplified.pb(1);
    	} else {
        	simplified.pb(0);
    	}
	}

	int flips = 0;
	int cur = 1;
	for (int i = simplified.size() - 1; i >=0; i--) {
		if (simplified[i] != cur) {
			flips++;
			cur = simplified[i];
		}
	}
	cout << flips << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}