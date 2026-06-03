#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

int n;

int apple(int index, int sum1, int sum2, vector<int>& weight) {
	if (index == n)
		return (abs(sum1 - sum2));

	return min(
		apple(index + 1, sum1 + weight[index], sum2, weight),
		apple(index + 1, sum1, sum2 + weight[index], weight)
	);
}

void solve() {
	cin >> n;
	vector<int> weight(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	cout << apple(0, 0, 0, weight) << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}