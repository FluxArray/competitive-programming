#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> E(n);
    for (int i = 0; i < n; i++) {
        cin >> E[i];
    }

    vector<int> G, H;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') G.pb(i);
        else H.pb(i);
    }
    int fG = G[0];
    int lG = G.back();
    int fH = H[0];
    int lH = H.back();

    bool gGlobal = (E[fG] >= lG + 1);
    bool hGlobal = (E[fH] >= lH + 1);
    int ans = 0;

    bool gIsLeader = gGlobal || (fG < fH && E[fG] >= fH + 1);
    bool hIsLeader = hGlobal || (fH < fG && E[fH] >= fG + 1);

    if (gIsLeader && hIsLeader) {
        ans++;
    }

    if (hGlobal) {
        for (int i : G) {
            if (i == fG) continue;
            if (i < fH && E[i] >= fH + 1) {
                ans++;
            }
        }
    }

    if (gGlobal) {
        for (int i : H) {
            if (i == fH) continue;
            if (i < fG && E[i] >= fG + 1) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast
    solve();
    return 0;
}