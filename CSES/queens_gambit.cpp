#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;
const int sq = 8;

void solve() {
	vector<vector<bool>> blocked(sq, vector<bool>(sq));
	for (int i = 0; i < sq; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < sq; j++) 
			if (row[j] == '*')
				blocked[i][j] = true;
	}

	vector<int> queens(sq);
	iota(all(queens), 0);

	int valid_num = 0;
	do {
		bool works = true;

		for (int i = 0; i < sq; i++) {
			if (blocked[queens[i]][i]) {
				works = false;
				break;
			}
		}

		vector<bool> taken(sq * 2 - 1);

		for (int i = 0; i < sq; i++) {
			if (taken[i + queens[i]]) {
				works = false;
				break;
			}
			taken[i + queens[i]] = true;
		}

		taken = vector<bool>(sq * 2 - 1);
		for (int i = 0; i < sq; i++) {
			if (taken[queens[i] - i + sq - 1]) {
				works = false;
				break;
			}
			taken[queens[i] - i + sq - 1] = true;
		}

		if (works)
			valid_num++;
	} while(next_permutation(all(queens)));

	cout << valid_num << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}