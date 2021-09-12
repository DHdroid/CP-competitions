/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int parent[100020];
int ranks[100020];
int par_dist[100020];
int CF[100020];

pair<int,int> find(int a) {
	if(parent[a] == -1) {
		return {a, 0};
	}
	else {
		auto res = find(parent[a]);
		par_dist[a] += res.second;
		parent[a] = res.first;
		// cout << "a, p, pd: " << a << " " << parent[a] << " " << par_dist[a] << endl;
		return {parent[a], par_dist[a]};
	}
}


void merge(pair<int,int> resa, pair<int,int> resb, int dist) {
	parent[resb.first] = resa.first;
	par_dist[resb.first] = dist + resa.second - resb.second;
	ranks[resa.first] += ranks[resb.first];
	if(CF[resa.first] || CF[resb.first]) {
		CF[resa.first] = 1;
		CF[resb.first] = 1;
	}
}

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		int N, K;
		cin >> N >> K;
		fill(parent, parent+N+1, -1);
		fill(par_dist, par_dist+N+1, 0);
		fill(ranks, ranks+N+1, 1);
		fill(CF, CF+N+1, 0);
		cout << "Case #" << test_case+1 << '\n';
		for(int z=0, tmp; z<K; z++) {
			cin >> tmp;
			if(tmp == 1) {
				int i, j, d;
				cin >> i >> j >> d;
				auto resi = find(i);
				auto resj = find(j);
				if(resi.first == resj.first) {
					if(resi.second - resj.second + d != 0) {
						CF[resi.first] = 1;
					}
				}
				else {
					auto resi = find(i);
					auto resj = find(j);
					
					if (ranks[resj.first] < ranks[resi.first])
						merge(resi, resj, d);
					else
						merge(resj, resi, -d);
				}
			}
			else {
				int i, j;
				cin >> i >> j;
				auto resi = find(i);
				auto resj = find(j);
				if(resi.first == resj.first) {
					if(CF[resi.first]) {
						cout << "CF" << '\n';
					}
					else {
						cout << resj.second - resi.second << '\n';
					}
				}
				else {
					cout << "NC" << '\n';
				}
			}
		}

	}

	return 0;//Your program should return 0 on normal termination.
}