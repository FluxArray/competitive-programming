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
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> hooves(n + 1), paper(n + 1), scissors(n + 1);

 	for (int i = 1; i <= n; i++) {
 		hooves[i] += hooves[i - 1];
		paper[i] += paper[i - 1];
		scissors[i] += scissors[i - 1];
		char c;
		cin >> c;
		if (c == 'H')
			hooves[i]++;
		else if (c == 'P') 
			paper[i]++;
		else
			scissors[i]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int before_switch = max({hooves[i], paper[i], scissors[i]});
		int h_after = hooves[n] - hooves[i];
        int p_after = paper[n] - paper[i];
        int s_after = scissors[n] - scissors[i];
        int after_switch = max({h_after, p_after, s_after});
        ans = max(ans, before_switch + after_switch);
	}
	cout << ans << '\n';
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}