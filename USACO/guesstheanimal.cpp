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
	int n;
	cin >> n;
	vector<pair<string, vector<string>>> animal(n);
	for (int i = 0; i < n; i++) {
		cin >> animal[i].first;
		int k;
		cin >> k;
		while(k--)
			cin >> animal[i].second[k];
	}
	

}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}