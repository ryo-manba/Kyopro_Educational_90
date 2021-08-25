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

int n, q;
int c[100010], p[100010], l[100010], r[100010];
int x[100010], y[100010];

int main()
{
	cin >> n;
	rep(i,n) cin >> c[i] >> p[i];
	cin >> q;
	rep(i,q) cin >> l[i] >> r[i];

	rep(i,n)
	{
		if (c[i] == 1) x[i + 1] = p[i];
		if (c[i] == 2) y[i + 1] = p[i];
		x[i + 1] += x[i];
		y[i + 1] += y[i];
	}
	rep(i,q)
	{
		int ansx = x[r[i]] - x[l[i] - 1];
		int ansy = y[r[i]] - y[l[i] - 1];
		cout << ansx << " " << ansy << endl;
	}
	return 0;
}
