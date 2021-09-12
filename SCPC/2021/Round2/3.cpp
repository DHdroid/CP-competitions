#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int arr[2000][2000]; // 가로세로 N + 2*(K+1)
ll vert_sum[2000][2000]; // 세로 sum sum[i]: 0~i-1까지의 sum. sum[0] = 0, sum[1] = arr[0]
ll cross1[4000][2000]; // /방향 sum x는 j+i로, y는 i로 인덱싱 됨
ll cross2[4000][2000]; // \방향 sum x는 j-i+length-1로, y는 i로 인덱싱 됨

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		ll ans = 0;
		int N, K;
		cin >> N >> K;
		K--;
		int length = N + 2*(K+1);
		for(int i=0; i<length; i++) {
			for(int j=0; j<length; j++) 
				arr[i][j] = 0;
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				cin >> arr[i+K+1][j+K+1];
			}
		}
		// initialize vert_sum
		for(int j=0; j<length; j++) {
			for(int i=0; i<length; i++) {
				vert_sum[j][i+1] = vert_sum[j][i] + (ll)arr[i][j];
			}
		}
		// initialize cross1
		for(int idx=0; idx<2*length-1; idx++) {
			for(int i=0; i<length; i++) {
				if(idx-i < length) 
					cross1[idx][i+1] = cross1[idx][i] + (ll)arr[i][idx-i];
				else 
					cross1[idx][i+1] = cross1[idx][i];
			}
		}
		// initialize cross2
		for(int idx=0; idx<2*length-1; idx++) {
			for(int i=0; i<length; i++) {
				if(idx+i >= length-1 && idx+i-(length-1) <= length-1)
					cross2[idx][i+1] = cross2[idx][i] + (ll)arr[i][idx+i-(length-1)];
				else
					cross2[idx][i+1] = cross2[idx][i];
			}
		}
		for(int i=0; i<length; i++) {
			ll curr = 0, plus = 0, minus = 0;
			for(int j=1; j<length; j++) {
				// 계산
				// i, j+K
				if(i+j+K < 2*length-1)
					plus += cross1[i+j+K][min(length, i+K+1)] - cross1[i+j+K][i+1];
				if(j+K-i+length-1 < 2*length-1)
					plus += cross2[j+K-i+length-1][i+1] - cross2[j+K-i+length-1][max(0, i-K)];

				// i, j-K-2
				if(i+j-K-2 >= 0)
					minus -= cross1[i+j-K-2][i+1] - cross1[i+j-K-2][max(0, i-K)];
				if(j-K-2-i+length-1 >= 0)
					minus -= cross2[j-K-2-i+length-1][min(length,i+K+1)] - cross2[j-K-2-i+length-1][i+1];

				// j-1 column
				plus -= vert_sum[j-1][min(length, i+K+1)] - vert_sum[j-1][max(0, i-K)];
				minus += vert_sum[j-1][min(length, i+K+1)] - vert_sum[j-1][max(0, i-K)];
				// cout << "i: " << i << " j: " << j << " plus: " << plus << " minus: " << minus << '\n';
				curr += plus;
				curr -= minus;
				ans = max(ans, curr);
			}
		}
		cout << "Case #" << test_case << '\n';
		cout << ans << '\n';
	}
}