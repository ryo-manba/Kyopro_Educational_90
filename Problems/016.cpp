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
	int n, tmp1, tmp2, ans = INF;
	vector<int> a(3);
	cin >> n;
	rep(i,3) cin >> a[i];
	sort(a.rbegin(), a.rend());

	for (int i = n / a[0]; i >= 0; i--)
	{
		tmp1 = n - a[0] * i;
		if (tmp1 == 0)
		{
			chmin(ans, i);
			break ;
		}
		for (int j = tmp1 / a[1]; j >= 0; j--)
		{
			tmp2 = tmp1 - a[1] * j;
			if (tmp2 == 0)
			{
				chmin(ans, i + j);
				break ;
			}
			if  (tmp2 % a[2] == 0)
			{
				chmin(ans, i + j + tmp2 / a[2]);
				break ;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
