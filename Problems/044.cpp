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

// rotateの回数でインデックスずらす

int main()
{
	int	n, q;
	cin >> n >> q;
	vector<int> a(n),ans;
	int k = 0;
	rep(i,n) cin >> a[i];
	rep(i,q)
	{
		int	t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
		{
			swap(a[(x - 1 + k) % n], a[(y - 1 + k) % n]);
		}
		if (t == 2) //rotate
			k = (k + n - 1) % n;
		if (t == 3)
			ans.push_back(a[(x - 1 + k) % n]);
	}
	for (auto s : ans)
		cout << s << endl;
	return 0;
}
