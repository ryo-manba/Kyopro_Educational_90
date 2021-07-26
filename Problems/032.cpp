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

int	a[10][10] = {};
vector<int> x(50), y(50);

int main()
{
	int n, m, ans = INF;
	cin >> n;
	rep(i,n) rep(j,n) cin >> a[i][j];
	cin >> m;
	rep(i,m) cin >> x[i] >> y[i];

	vector<int> vec;
	rep(i,n) vec.push_back(i);

	do {
		int tmp = 0;
		bool flag = true;
		rep(i,m)
		{
			rep(j,n - 1)
			{
				if ((vec[j] == x[i] - 1 && vec[j + 1] == y[i] - 1)
					|| (vec[j] == y[i] -1 && vec[j + 1] == x[i] - 1))
				{
					flag = false;
					break ;
				}
			}
		}
		if (flag)
		{
			rep(i,n) tmp += a[vec[i]][i];
			chmin(ans,tmp);
		}
	} while (next_permutation(vec.begin(), vec.end()));

	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}
