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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    ll hmm = lcm(a, b);
    ll hmmm = lcm(b, c);
    ll hmmmm = lcm(a, c);

    ll hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm = lcm(hmm, hmmm);
    ll a1 = 6 * (m / a) - ((m / hmm) * 3 + (m / hmmmm) * 3) + 2 * (m / hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm);
    ll a2 = 6 * (m / b) - ((m / hmm) * 3 + (m / hmmm) * 3) + 2 * (m / hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm);
    ll a3 = 6 * (m / c) - ((m / hmmm) * 3 + (m / hmmmm) * 3) + 2 * (m / hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm);

    cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
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