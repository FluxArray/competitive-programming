#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    int N;
    cin >> N;
    vector<int> count(N);
    for (int i = 0; i < N; i++) {
        cin >> count[i];
    }
    int photos = N;
    for (int i = 0; i < N - 1; i++) {
        int summ = 0;
        for (int j = i + 1; j < N; j++) {
            summ = accumulate(count.begin() + i, count.begin() + j + 1, 0LL);
            int len = j - i + 1;
            if (summ % len != 0)
                continue;
            int avg = summ / len;
            for (int k = i; k <= j; k++) {
                if (count[k] == avg) {
                    photos++;
                    break;
                }
            }
        }
    }
    cout << photos << endl;
}

int32_t main() {
    fast
    int t = 1;
    while (t--) solve();
    return 0;
}