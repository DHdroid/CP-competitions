#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

void solve() {
    int M, K, Q;
    int mini,medi,maxi;
    cin >> M >> K >> Q;
    cin >> mini >>medi >> maxi;
    vector<int> A, V;
    for(int i=0; i<2*M*K+1; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for(int i=0; i<Q; i++) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
    }
    sort(A.begin(), A.end());

    for(auto v: V) {
        int idx = lower_bound(A.begin(), A.end(), v) - A.begin();
        int upp_idx = upper_bound(A.begin(), A.end(), v) - A.begin() -1;
        // cout << endl <<"?: "<< idx << " " << upp_idx <<endl;
        if(idx == 2*M*K+1 || A[idx] != v) {
            cout << -1 << " ";
            continue;
        }
        else if(M==1) {
            int min_cost = 10;
            if(idx <= K && upp_idx >=K) {
                min_cost = min(min_cost, medi);
            }
            if(idx == 0) {
                min_cost = min(min_cost, mini);
            }
            if(upp_idx == 2*K)
                min_cost = min(min_cost, maxi);

            if(min_cost==10)
                cout << -1 << " ";
            else
                cout << min_cost << " ";
            continue;
        }
        else {
            int base_cost = min(min(mini, maxi), medi);
            int ans = base_cost * (M-2);
            int min_cost = 20;
            if(upp_idx >= K && idx < 2*K*M+1-K) {
                min_cost = min(min_cost,  medi + base_cost);
            }
            if(upp_idx >= 2*K ) {
                if(upp_idx == 2*K*M) {
                    min_cost = min(min_cost, maxi + base_cost);
                }
                else {
                    min_cost = min(min_cost, maxi + min(mini, medi));
                }
            }
            if(idx < 2*K*M + 1 - 2*K) {
                if(idx == 0) {
                    min_cost = min(min_cost, mini + base_cost);
                }
                else {
                    min_cost = min(min_cost, mini + min(maxi, medi));
                }
            }

            cout << ans + min_cost << " ";
        }
    }
    cout <<"\n";
}

int main() {
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cout << "Case #" << test_case << "\n";
        solve();
    }
}