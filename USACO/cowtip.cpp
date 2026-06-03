#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;
const char TIPPED = '0';

bool flip(int r, int c, vector<vector<bool>> &mat) {
	if (mat[r][c]) {
		for (int ri = 0; ri <= r; ri++) {
			for (int ci = 0; ci <= c; ci++) { mat[ri][ci] = !mat[ri][ci]; }
		}
		return true;
	}
	return false;
}

void solve() {
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	int width; 
	cin >> width;
	vector<vector<bool>> mat(width, vector<bool>(width));
	for (int i = 0; i < width; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < width; j++) {
			mat[i][j] = s[j] != TIPPED;
		}
	}

	int x = width - 1;
	int y = width - 1;
	int min_flips = 0;
	while (x >= 0 && y >= 0) {
		min_flips += flip(x, y, mat);
		if (x != y) {
			min_flips += flip(y, x, mat);
		}

		if (x > 0) {
			x--;
		} else {
			y--;
			x = y;
		}
	}
	cout << min_flips << '\n';
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}