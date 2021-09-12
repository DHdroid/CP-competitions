#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

char str[2000020];
int last[30];

char kstr[30020];
int klastptr[30020];
int klast[30];

int fail[30020];

void calculate_fail(char* arr) {
    int length = strlen(arr);
    fail[0] = 0;
	for(int j=0; j<=26; j++)
		klast[j] = -1e7;
	fill(klastptr, klastptr+length+2, -1e7);
  	klast[arr[0]-'a'] = 0;
    for(int i=1, j=0; i<length; i++) {
    	klastptr[i] = klast[arr[i]-'a'];
    	klast[arr[i]-'a'] = i;
        while(j>0 && (klastptr[i] - i != klastptr[j] - j)) {
        	if(i - klastptr[i] <= j || klastptr[j] >=0)
            	j = fail[j-1];
            else
            	break;
        }
        if((klastptr[i] - i == klastptr[j] - j) || (i - klastptr[i] > j && klastptr[j] < 0))
            fail[i] = ++j;
    }
}
void KMP(char *A, char *B, int& ans, int i) {
    // find B from A
    int pt1 = 0, pt2 = 0, lenA = strlen(A), lenB = strlen(B);
    for(int i=0; i<=26; i++)
    	last[i] = -1e7;
    for(pt1 = 0; pt1 < lenA; pt1++) {
    	if(pt1 > 0)
    		last[A[pt1-1]-'a'] = pt1-1;
        while(pt2 > 0 && pt1-last[A[pt1]-'a']!=pt2-klastptr[pt2]) {
        	if(pt1 - last[A[pt1]-'a'] <= pt2 || klastptr[pt2] >= 0)
            	pt2 = fail[pt2-1];
            else
            	break;
        }
        if((pt1-last[A[pt1]-'a']==pt2-klastptr[pt2])|| (pt1 - last[A[pt1]-'a'] > pt2 && klastptr[pt2] < 0)) {
            if(pt2 == lenB-1) {
                ans+=(i+1);
                pt2 = fail[pt2];
            }
            else {
                pt2++;
            }
        }
    }
}


int main(int argc, char** argv) {

	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++) {
		int N, K;
		cout << "Case #" << test_case << '\n';
		cin >> N >> K;
		cin >> str;
		int ans = 0;
		for(int i=0; i<K; i++) {
			cin >> kstr;
			calculate_fail(kstr);
			// for(int i=0; i<strlen(kstr); i++) {
			// 	cout << fail[i] << ' ';
			// }
			// cout << endl;
			KMP(str, kstr, ans, i);
			// cout << "ans: " << ans << endl;
		}
		
		cout << ans << '\n';
	}
}