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
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	cin >> q;
	vector<int> b(q);
	rep(i,q) cin >> b[i];
	sort(a.begin(), a.end());

	rep(i,q)
	{
		auto it = lower_bound(a.begin(), a.end(), b[i]);
		int over  = abs(b[i] - *it);
		if (it != a.begin()) it--;
		int under = abs(b[i] - *it);
		cout << min(over, under) << endl;
	}
	return 0;
}
