#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;
const int MAX_N = 100;
const int MAX_X = 1000;

int N, cows[MAX_N], cowsPassingTo[MAX_N];

int pass(int cow) {
	int lc = -1;
	int rc = -1;
	int leftrange = MAX_X;
	int rightrange = MAX_X;
	for (int i = 0; i < N; i++) {
		if (cows[i] < cows[cow] && cows[cow] - cows[i] < leftrange) {
			lc = i;
			leftrange = cows[cow] - cows[i];
		}  
		if (cows[i] > cows[cow] && cows[i] - cows[cow] < rightrange) {
			rc = i;
			rightrange = cows[i] - cows[cow];
		}
	}
	if (leftrange <= rightrange) { return lc; }
	else return rc;
}

void solve() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	cin >> N;
	int balls = 0;
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	for (int i = 0; i < N; i++)
		cowsPassingTo[pass(i)]++;
	for (int i = 0; i < N; i++) {
		if (cowsPassingTo[i] == 0) { balls++; }
		if (i < pass(i) && pass(pass(i)) == i && cowsPassingTo[i] == 1 &&
		    cowsPassingTo[pass(i)] == 1) {
			balls++;
		}
	}
	cout << balls << '\n';
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}