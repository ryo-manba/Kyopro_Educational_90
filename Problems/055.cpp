#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
const int INF = (int)1e9;
const ll INFL = (ll)1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
int dx[]={0, 0, -1, 1};
int dy[]={1, -1, 0, 0};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	int n, p, q, ans = 0;
	cin >> n >> p >> q;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				for (int l = 0; l < k; l++) {
					for (int m = 0; m < l; m++) {
						if (a[i] * a[j] % p * a[k] %p * a[l] %p * a[m] % p == q)
							ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
