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
	int	n, x, y, z;
	ll ans = 0;
	cin >> n;
	map<int, ll> a, b, c;

	rep(i,n)
	{
		cin >> x;
		a[x % 46]++;
	}
	rep(i,n)
	{
		cin >> y;
		b[y % 46]++;
	}
	rep(i,n)
	{
		cin >> z;
		c[z % 46]++;
	}

	for (int i = 0; i < 46; i++) {
		for (int j = 0; j < 46; j++) {
			for (int k = 0; k < 46; k++) {
				if ((i + j + k) % 46 == 0)
					ans += a[i] * b[j] * c[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
