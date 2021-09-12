#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(int argc, char** argv) {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int T;
	cin >> T;

	for(int i=0; i<T; i++) {
		ll x;
		scanf("%lld",&x);
		ll ans = 0;
		for(ll j=1; j<x; j++) {
			ll target = x*x - j*j;
			ll lo = 0, hi = x;
			while(lo!=hi) {
				ll mid = (lo+hi+1) >> 1;
				if(mid*mid < target) {
					lo = mid;
				}
				else {
					hi = mid-1;
				}
			}
			ans += 2*lo+1;
		}
		ans *= 2;
		ans += 2*x-1;
		cout << "Case #" << i+1 << '\n';
		cout << ans << '\n';
	}
}