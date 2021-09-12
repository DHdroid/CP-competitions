#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<pii> ans;
void solve(int source, int obj, int N, int s, int o, int a) {
	int another = 6-source-obj;
	if(N==1) {
		ans.push_back({source, obj});
		return;
	}
	if(N==0) {
		return;
	}
	if(s==0 && o==0 && a==0) {
		solve(source, another, N-1, 1, 0, 0);
		ans.push_back({source, obj});
		solve(another, obj, N-1, 0, 1, 0);
	}
	else if(s==1 && o==0 && a==0) {
		solve(source, another, N-2, 1, 0, 0);
		ans.push_back({source, obj});
		ans.push_back({source, obj});
		solve(another, obj, N-2, 0, 0, 1);
	}
	else if(s==0 && o==1 && a==0) {
		solve(source, another, N-2, 0, 0, 1);
		ans.push_back({source, obj});
		ans.push_back({source, obj});
		solve(another, obj, N-2, 0, 1, 0);
	}
	else if(s==0 && o==0 && a==1) {
		// if(N==5) {
		// 	ans.push_back({source, obj});
		// 	ans.push_back({source, another});
		// 	ans.push_back({obj, another});
		// 	ans.push_back({source, obj});
		// 	ans.push_back({source, obj});
		// 	ans.push_back({another, obj});
		// 	ans.push_back({another, obj});
		// 	return;
		// }
		if(N==4) {
			ans.push_back({source, another});
			ans.push_back({source, obj});
			ans.push_back({another, obj});
			ans.push_back({source, another});
			ans.push_back({source, another});
			ans.push_back({obj, another});
			ans.push_back({obj, source});
			ans.push_back({another, source});
			ans.push_back({another, obj});
			ans.push_back({another, obj});
			ans.push_back({source, another});
			ans.push_back({source, obj});
			ans.push_back({another, obj});
			return;
		}
		solve(source, obj, N-2, 0, 0, 1);
		ans.push_back({source, another});
		ans.push_back({source, another});
		solve(obj, source, N-2, 0, 0, 1);
		ans.push_back({another, obj});
		ans.push_back({another, obj});
		solve(source, obj, N-2, 0, 0, 1);
	}
}

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++) {
		int M;
		cin >> M;
		ans.clear();
		cout << "Case #1" << endl;
		int N = 25;
		cout << N << '\n';
		solve(1, 3, N, 0, 0, 0);
		// solve(1,3,4,0,0,1);
		// cout << ans.size() << endl;
		for(auto v: ans) {
			// cout << v.first << " " << v.second << endl;
			if(v.first == 1 && v.second == 2) {
				cout << 'A';
			}
			if(v.first == 1 && v.second == 3) {
				cout << 'B';
			}
			if(v.first == 2 && v.second == 1) {
				cout << 'C';
			}
			if(v.first == 2 && v.second == 3) {
				cout << 'D';
			}
			if(v.first == 3 && v.second == 1) {
				cout << 'E';
			}
			if(v.first == 3 && v.second == 2) {
				cout << 'F';
			}
		}
		cout << endl;
	}
}