/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> lis[520];
vector<int> visited(520, 0);

void dfs(int i) {
	visited[i] = 1;
	for(auto k: lis[i]) {
		if(!visited[k]) {
			dfs(k);
		}
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

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		vector<int> ans;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		int N, M, K;
		cin >> N >> M >> K;
		for(int i=0, x, y; i<M; i++) {
			cin >> x >> y;
			lis[x].push_back(y);
		}
		for(int i=0, x, y; i<K; i++) {
			cin >> x >> y;
			fill(visited.begin(), visited.end(), 0);
			dfs(y);
			if(visited[x]) {
				lis[y].push_back(x);
				ans.push_back(1);
			}
			else {
				lis[x].push_back(y);
				ans.push_back(0);
			}
		}

		cout << "Case #" << test_case+1 << endl;
		for(auto i: ans) {
			cout << i;
		}
		cout << endl;
		for(int i=1; i<=N; i++) {
			lis[i].clear();
			visited[i] = 0; // ?????????
		}
	}

	return 0;//Your program should return 0 on normal termination.
}