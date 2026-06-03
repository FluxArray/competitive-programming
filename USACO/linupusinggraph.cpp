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
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella",  "Blue", "Betsy", "Sue"};
	sort(all(cows));
	map<string, int> cow_i;
	for (int i = 0; i < 8; i++) 
    	cow_i[cows[i]] = i;

	vector<vector<int>> neighbours(cows.size());
	for (int r = 0; r < n; r++) {
		string cow1; 
		string cow2;
		string trash;
		cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

		int c1 = cow_i[cow1];
		int c2 = cow_i[cow2];
		neighbours[c1].pb(c2);
		neighbours[c2].pb(c1);
	}

	vector<int> order;
	vector<bool> added(cows.size());
	for (int i = 0; i < cows.size(); i++) {
		if (!added[i] && neighbours[i].size() <= 1) {
			added[i] = true;
			order.pb(i);

			if (neighbours[i].size() == 1) {
				int prev = i;
				int at = neighbours[i][0];
				while(neighbours[at].size() == 2) {
					added[i] = true;
					order.pb(at);

					int a = neighbours[at][0];
					int b = neighbours[at][1];
					int temp_at = a == prev ? b : a;
					prev = at;
					at = temp_at; 
				}
				added[at] = true;
				order.pb(at);
			}
		}
	}

	for (int c : order) {
		cout << cows[c] << endl; 
	}
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}