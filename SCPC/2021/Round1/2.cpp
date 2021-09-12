/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Answer;
char str[50020];
int ans[50020];

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

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		int N, t;
		cin >> N >> t;
		cin >> str;
		fill(ans, ans+N, -1);
		for(int i=0; i<N; i++) {
			if(i < t && i+t < N) {
				ans[i+t] = str[i] - '0';
			}
			else if(i >= t && i+t >= N) {
				ans[i-t] = str[i] - '0';
			}
			else if(i >= t && i+t < N) {
				if(str[i] == '0') {
					ans[i-t] = 0;
					ans[i+t] = 0;
				}
				else {
					if(ans[i+t] == 0) {
						ans[i-t] = 1;
					}
					else {
						if(ans[i-t] != 1 && ((i+2*t < N && str[i+2*t] == '1')||i+2*t >=N)) {
							ans[i+t] = 1;
							ans[i-t] = 0;
						}
						else {
							ans[i-t] = 1;
						}
					}
				}
			}
		}

		cout << "Case #" << test_case+1 << endl;
		for(int i=0; i<N; i++) {
			if(ans[i] < 0) {
				ans[i] = 0;
			}
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}