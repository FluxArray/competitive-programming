#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

vector<int> res;
set<int> ele;

void backtrack(int n) {
	if ((int)res.size() == n) {
		for (int x : res)
		cout << x << " \n"[x == res.back()];
		exit(0);
	}

	for (auto it = ele.begin(); it != ele.end(); ) {
    int x = *it;
    ++it; // move first so iterator stays valid

    if (res.empty() || abs(res.back() - x) > 1) {
        res.pb(x);
        ele.erase(x);
        backtrack(n);
        ele.insert(x);
        res.pop_back();
    }
}


}

void solve() {
	int n;
	cin >> n;

	if (n == 2 || n == 3) {
		cout << "NO SOLUTION" << endl;
		return;
	}

	for (int i = 1; i <= n; i++) 
		ele.insert(i);

	backtrack(n);
}

int32_t main() {
    fast
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}