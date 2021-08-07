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
	int h, w, i, j;
	cin >> h >> w;
	vector<vector<ll>> a(h + 1,vector<ll>(w + 1)), b(h + 1,vector<ll>(w + 1));
	for (i = 1; i <= h; i++) for (j = 1; j <= w; j++) cin >> a[i][j];
	for (i = 1; i <= h; i++) for (j = 1; j <= w; j++) cin >> b[i][j];

	ll ans = 0;
	for (i = 1; i < h; i++)
	{
		for (j = 1; j < w; j++)
		{
			ll diff = b[i][j] - a[i][j];
			a[i][j] += diff;
			a[i + 1][j] += diff;
			a[i][j + 1] += diff;
			a[i + 1][j + 1] += diff;
			ans += abs(diff);
		}
	}
	if (a == b)
	{
		cout << "Yes" << endl;
		cout << ans << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}
