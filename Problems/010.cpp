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
	vector<int> c(n), p(n), ans1(n + 1), ans2(n + 1);
	rep(i,n)
	{
		cin >> c[i] >> p[i];
		if (c[i] == 1)
		{
			ans1[i + 1] = ans1[i] + p[i];
			ans2[i + 1] = ans2[i];
		}
		if (c[i] == 2)
		{
			ans1[i + 1] = ans1[i];
			ans2[i + 1] = ans2[i] + p[i];
		}
	}
	cin >> q;
	vector<int> l(q), r(q);
	rep(i,q)
	{
		cin >> l[i] >> r[i];
		cout << (ans1[r[i]])-(ans1[l[i] - 1]) << " ";
		cout << (ans2[r[i]])-(ans2[l[i] - 1]) << endl;
	}
	return 0;
}
