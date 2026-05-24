#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fast ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> s(n);
    map<string, int> m;
    map<string, string> name;
    
    m["Ox"] = 1; m["Tiger"] = 2; m["Rabbit"] = 3; m["Dragon"] = 4;
    m["Snake"] = 5; m["Horse"] = 6; m["Goat"] = 7; m["Monkey"] = 8;
    m["Rooster"] = 9; m["Dog"] = 10; m["Pig"] = 11; m["Rat"] = 12;

    for (int i = 0; i < n; i++){
        string a, born, in, dir, animal, year, from, b;
        cin >> a >> born >> in >> dir >> animal >> year >> from >> b;
        s[i] = {a, dir, animal, b};
        name[s[i][0]] = s[i][2];
    }

    unordered_map<string, int> ans;
    ans["Bessie"] = 0;
    name["Bessie"] = "Ox";
    for (int i = 0; i < n; i++) {
        string cowA = s[i][0];
        string dir = s[i][1];
        string animalA = s[i][2];
        string cowB = s[i][3];

        int ref_year = ans[cowB];
        int idx_a = m[animalA];
        int idx_b = m[name[cowB]];

        if (dir == "previous") {
            int diff = idx_b - idx_a;
            if (diff <= 0) diff += 12; 
            ans[cowA] = ref_year - diff;
        }
        else {
            int diff = idx_a - idx_b;
            if (diff <= 0) diff += 12;
            ans[cowA] = ref_year + diff;
        }
    }
    cout << abs(ans["Elsie"]) << endl;
}

int32_t main() {
    fast
    int t = 1;
    while (t--) solve();
    return 0;
}
