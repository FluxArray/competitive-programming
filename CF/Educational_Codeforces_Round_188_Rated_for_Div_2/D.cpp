#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define auto(i, n) for (auto i : n)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    return b < a ? (a = b, true) : false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    return b > a ? (a = b, true) : false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const ll mod = 1000000007;
const ll modd = 998244353;

void solve() {
    ll n, m;
    cin >> n >> m;

    vvi adj(n + 1);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi visi(n + 1, -1);
    ll ans = 0;

    rep1(i, n + 1) {
        if (visi[i] == -1) {
            queue<ll> q;
            q.push(i);
            visi[i] = 0;

            int arr[2] = {0, 0};
            bool hmm = true;

            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                arr[visi[u]]++;

                auto(j, adj[u]) {
                    if (visi[j] == -1) {
                        visi[j] = 1 - visi[u];
                        q.push(j);
                    } else if (visi[j] == visi[u]) {
                        hmm = false;
                    }
                }
            }


            if (hmm) {
                ans += max(arr[0], arr[1]);
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
//hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    rep(i, t) solve();
    return 0;
}