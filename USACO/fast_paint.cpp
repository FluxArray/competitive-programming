#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int total = a - b + c - d;
	int intersection = max(min(b, d) - max(a, c), 0LL);
	int ans = total - intersection; 
	cout << ans << '\n';
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}