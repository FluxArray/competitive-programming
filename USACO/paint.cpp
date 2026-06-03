#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	set <int> ans;
	for (int i = a; i < b; i++)
		ans.insert(i);
	for (int i = c; i < d; i++)
		ans.insert(i);
	cout << ans.size() << endl;
	
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}