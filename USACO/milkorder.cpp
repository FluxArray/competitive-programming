#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> M(m);
    bool one_in_M = false;
    for (int i = 0; i < m; i++) {
        cin >> M[i];
        if (M[i] == 1) one_in_M = true;
    }

    // fixed_pos[cow_id] = 1-based index (0 if not fixed)
    // occupied[index] = cow_id (0 if empty)
    vector<int> fixed_pos(105, 0); 
    vector<int> occupied(n + 1, 0); 

    for (int i = 0; i < k; i++) {
        int cow, pos;
        cin >> cow >> pos;
        fixed_pos[cow] = pos;
        occupied[pos] = cow;
        if (cow == 1) {
            cout << pos << endl;
            return;
        }
    }

    // === CASE 1: Cow 1 is in the hierarchy ===
    // Strategy: Greedy Forward (Pack Left)
    if (one_in_M) {
        int current_idx = 1;
        for (int i = 0; i < m; i++) {
            int cow = M[i];
            
            if (fixed_pos[cow] != 0) {
                // If cow is fixed, jump to that position
                current_idx = fixed_pos[cow];
                occupied[current_idx] = cow;
                current_idx++;
            } else {
                // Find first empty slot
                while (occupied[current_idx] != 0) {
                    current_idx++;
                }
                occupied[current_idx] = cow;
                if (cow == 1) {
                    cout << current_idx << endl;
                    return;
                }
                current_idx++;
            }
        }
    } 
    // === CASE 2: Cow 1 is NOT in the hierarchy ===
    // Strategy: Greedy Backward (Pack Right)
    else {
        int current_idx = n;
        for (int i = m - 1; i >= 0; i--) {
            int cow = M[i];
            
            if (fixed_pos[cow] != 0) {
                current_idx = fixed_pos[cow];
                // Note: We don't mark occupied[] here, we just use it 
                // to align the hierarchy. We only care about what's LEFT OVER.
                current_idx--; 
            } else {
                // Find first empty slot searching backwards
                while (occupied[current_idx] != 0) {
                    current_idx--;
                }
                // Mark as occupied by hierarchy (using -1 to distinguish)
                occupied[current_idx] = -1; 
                current_idx--;
            }
        }
        
        // Find the very first empty slot for Cow 1
        for (int i = 1; i <= n; i++) {
            if (occupied[i] == 0) {
                cout << i << endl;
                return;
            }
        }
    }
}

int32_t main() {
    fast
    solve();
    return 0;
}