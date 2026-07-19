#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

vector<int> hmm(int n) {
    if (n == 1)
        return {1, 0};
    
    vector<int> ashu = hmm(n - 1);
    vector<int> ans;

    ans.reserve(1 << n);
    for (int x : ashu)
        ans.push_back(2 * x + 1);

    int limit = (1 << (n - 1));
    for (int i = 0; i < limit; i++)
        ans.push_back(2 * i);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> ans = hmm(n);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int32_t main() {
    fast
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}