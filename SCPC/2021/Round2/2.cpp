#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll, ll>;

vector<vector<int>> perms;
vector<pll> offsets;

void init_perms() {
	vector<int> tmp = {0, 1, 2, 3, 4, 5, 6, 7};
	do {
		perms.push_back(tmp);
	} while(next_permutation(tmp.begin(),tmp.end()));
}

ll solve(vector<int>& perm, vector<pii>& points) {
	if(points[perm[0]].first > points[perm[1]].first)
		return 1e18;
	if(points[perm[0]].second > points[perm[5]].second)
		return 1e18;
	vector<ll> x_offsets, y_offsets;
	for(int i=0; i<8; i++) {
		x_offsets.push_back(points[perm[i]].first-offsets[i].first);
		y_offsets.push_back(points[perm[i]].second-offsets[i].second);
	}
	sort(x_offsets.begin(), x_offsets.end());
	sort(y_offsets.begin(), y_offsets.end());
	ll x = x_offsets[3], y = y_offsets[3];
	ll ret = 0;
	for(int i=0; i<8; i++) {
		ret += abs(x_offsets[i] - x) + abs(y_offsets[i] - y);
	}
	return ret;
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	init_perms();
	for(int test_case=1; test_case<=T; test_case++) {
		ll ans = 1e18;
		int K;
		cin >> K;
		offsets = {
			{K, 0},
			{2*K, 0},
			{3*K, K},
			{3*K, 2*K},
			{2*K, 3*K},
			{K, 3*K},
			{0, 2*K},
			{0, K}
		};
		vector<pii> points;
		for(int i=0; i<8; i++) {
			int x,y;
			cin >> x >> y;
			points.push_back({x,y});
		}
		for(auto& perm: perms){
			ans = min(ans, solve(perm, points));
		}
		cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
	}
	return 0;
}