#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	char grid[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> grid[i][j];

	set<char> single;
	set<string> teams;

	vector<vector<char>> lines;

	for (int i = 0; i < 3; i++) {
	    vector<char> row = {grid[i][0], grid[i][1], grid[i][2]};
	    lines.push_back(row);
	}

	for (int j = 0; j < 3; j++) {
	    vector<char> col = {grid[0][j], grid[1][j], grid[2][j]};
	    lines.push_back(col);
	}

	lines.push_back({grid[0][0], grid[1][1], grid[2][2]});
	lines.push_back({grid[0][2], grid[1][1], grid[2][0]});

	for (auto &ln : lines) {
	    set<char> s(ln.begin(), ln.end());
	    if (s.size() == 1) {
	        single.insert(*s.begin());
	    } else if (s.size() == 2) {
	        string t;
	        for (char c : s) t += c;
	        sort(t.begin(), t.end());
	        teams.insert(t);
	    }
	}

	cout << single.size() << endl;
	cout << teams.size() << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}