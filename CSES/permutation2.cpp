#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	string s;
	cin >> s;
	sort(all(s));

	vector<string> perms;
	do { perms.push_back(s); } while (next_permutation(all(s)));

	cout << perms.size() << endl;
	for (int i = 0; i < perms.size(); i++)
		cout << perms[i] << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}