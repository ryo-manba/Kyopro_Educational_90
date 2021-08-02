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
	ll n, q, ans = 0;
	cin >> n >> q;
	vector<ll> a(n + 1), l(q + 1), r(q + 1), v(q + 1), diff(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) cin >> l[i] >> r[i] >> v[i];
	for (int i = 1; i <= n - 1; i++)
	{
		diff[i] = a[i + 1] - a[i];
		ans += abs(diff[i]);
	}
	for (int i = 1; i <= q; i++)
	{
		ll before, after;
		before = abs(diff[l[i] - 1]) + abs(diff[r[i]]);
		if (l[i] >= 2)
			diff[l[i] - 1] += v[i];
		if (r[i] <= n - 1)
			diff[r[i]] -= v[i];
		after = abs(diff[l[i] - 1]) + abs(diff[r[i]]);
		ans += (after - before);
		cout << ans << endl;
	}
	return 0;
}


/*
10
41
192
11
24
24
25
10
81
80
89
53
90
11
113
86
59
38
37
1074
*/
