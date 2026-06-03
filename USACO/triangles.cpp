#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<pair<int, int>> cordi(n);
	for (int i = 0; i < n; i++) {
		cin >> cordi[i].first >> cordi[i].second;
	}

	int area = 0;
	vector<int> hori;
	vector<int> verti;
	for (int i = 0; i < n; i++) {
		int x1 = cordi[i].first;
		int y1 = cordi[i].second;

		vector<int> hori;
		vector<int> verti;

		for (int j = 0; j < n; j++) {
			if (cordi[j].first == x1 && cordi[j].second != y1)
				verti.pb(cordi[j].second); 

			if (cordi[j].second == y1 && cordi[j].first != x1)
				hori.pb(cordi[j].first);
		}

		for (int x2 : hori) {
			for (int y2 : verti) {
				int height = abs(y2 - y1);
				int width = abs(x2 - x1);
				int temp = height * width;
				area = max(temp, area);
			}
		}
	}
	cout << area << endl;
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}