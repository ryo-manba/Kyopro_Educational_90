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

const double PI = acos(-1);
double	t, l, x, y, e, q;

double solve(double d)
{
	double cx, cy, cz, d1, d2, fukaku;
	cx = 0; 											// x座標
	cy = -(l / 2.0) * sin(d / t * 2.0 * PI); 			// y座標
	cz = (l / 2.0) - (l / 2.0) * cos(d / t * 2.0 * PI); // z座標
	d1 = sqrt(pow((cx - x),2)+ pow((cy - y), 2));		// 水平距離
	d2 = cz;											// 観覧車の高さ
	fukaku = atan2(d2, d1);
	return fukaku * 180.0L / PI; 	// atan2(y,x)でラジアンで返す
}

int main()
{
	cin >> t;
	cin >> l >> x >> y;
	cin >> q;
	rep(i,q)
	{
		cin >> e;
		cout << solve(e) << endl;
	}
	return 0;
}
