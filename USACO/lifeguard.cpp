#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> time(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i].first >> time[i].second;
	}
	int sum = 0;
	sort(all(time));
	vector<int> timer(1000);
	vector<int> tempo(1000);
	for (int i = 0; i < n; i++) {
		for (int j = time[i].first; j < time[i].second; j++) {
			timer[j - 1]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int temp = 0;
		tempo = timer;
		for (int j = time[i].first; j < time[i].second; j++) {
			tempo[j - 1]--;
		}
		for (int k = 0; k < 1000; k++) {
			if (tempo[k] > 0)
				temp++; 
		}
		sum = max(temp, sum);
	}
	cout << sum << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}