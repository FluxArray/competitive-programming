#include <bits/stdc++.h>
#include <cstdint>
#include <set>
#include <unordered_set>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	int n;
	string l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++){
		bool found = true;
		unordered_map<string, int> freq;
		for (int j = 0; j <= n - i; j++) {
			string temp = l.substr(j, i);
			freq[temp]++;
			if (freq[temp] > 1) found = false;
		}
		if (found) {
			cout << i << endl;
			break;
		}
	}
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}