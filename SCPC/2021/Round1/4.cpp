/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct group {
	int cost, advantage, odd, trans;
};

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		vector<group> g;
		int N, M, num_odds = 0;
		cin >> N >> M;
		for(int i=0; i<N; i++) {
			int t;
			cin >> t;
			vector<int> v;
			for(int j=0,x; j<t; j++) {
				cin >> x;
				v.push_back(x);
			}
			sort(v.begin(), v.end());
			int cost, advantage;
			cost = (1+t%2)*v[0] + v[1] + v[2] + v[3];	
			advantage = v[2] + v[3];
			if(t%2)
				g.push_back({cost, advantage, t%2, 0});
			else
				g.push_back({cost, advantage, t%2, cost+v[0]+v[1]});
			num_odds += t%2;
		}
		sort(g.begin(), g.end(), [](group& g1, group& g2) {
			return g1.advantage > g2.advantage;
		});
		ll ans = 0;
		for(auto& gr: g) {
			// cout << "gr" << " " << gr.cost << " " << gr.advantage << '\n';
			ans += (ll)gr.cost;
		}
		if(num_odds == 2 && g[0].odd && g[1].odd && g.size() > 2) {
			ll cand1, cand2 = 0;
			cand1 = ans - (ll)(g[0].advantage + g[2].advantage);
			for(auto& gr: g) {
				if(!gr.odd) {
					cand2 += (ll)gr.trans;
				}
				else {
					cand2 += (ll)gr.cost - (ll)gr.advantage;
				}
			}
			ans = min(cand1, cand2);
		}
		else {
			ans -= (ll)(g[0].advantage + g[1].advantage);
		}
		cout << "Case #" << test_case+1 << '\n';
		cout << ans << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}