#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

string x;
int L;
vector<int> group;

bool compare(int s1, int s2, int d) {
    if(d==0)
        return x[s1] < x[s2];
    if(group[s1] == group[s2])
        return group[s1+d] < group[s2+d];
    return group[s1] < group[s2];
}

void update_group(int d, vector<int>& idx) {
    vector<int> new_group(L+1, 0);
    new_group[idx[0]] = 0;
    for(int i=1; i<L; i++) {
        new_group[idx[i]] = new_group[idx[i-1]] + compare(idx[i-1], idx[i], d);
    }
    new_group[L] = -1;
    group = move(new_group);
}

void divide_sequence(vector<int>& ret) {
    group = vector<int>(L+1, 0);
    vector<int> idx;
    for(int i=0; i<L; i++) {
        idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [](int i, int j) {
        return compare(i, j , 0);
    });
    update_group(0, idx);
    for(int d=1; d<L; d*=2) {
        sort(idx.begin(), idx.end(), [&d](int i, int j) {
            return compare(i, j , d);
        });
        update_group(d, idx);
    }
    vector<int> rev_idx(L+1,0);
    for(int i=0; i<L; i++) {
        rev_idx[idx[i]] = i;
    }
    int prev_idx = -1;
    int prev_min = L;
    for(int i=0; i<L; i++) {
        if(prev_min > rev_idx[i]) {
            if(prev_idx != -1) {
                ret.push_back(i-prev_idx);
            }
            prev_min = rev_idx[i];
            prev_idx = i;
        }
    }
    ret.push_back(L-prev_idx);
}

void solve() {
    int N;
    cin >> N;
    cin >> x;
    L = N;
    vector<int> ans;
    divide_sequence(ans);
    cout << ans.size() << "\n";
    for(auto a: ans) {
        cout << a << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cout << "Case #" << test_case << "\n";
        solve();
    }
}