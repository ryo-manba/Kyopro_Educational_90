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

int n;
int cnt[1010][1010];
int	ans[100100];

int main()
{
	const int limit = 1001;
	cin >> n;
	rep(i,n)
	{
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		cnt[lx][ly]++;
		cnt[lx][ry]--;
		cnt[rx][ly]--;
		cnt[rx][ry]++;
	}
	rep(i,limit)
	{
		for (int j = 1; j < limit; j++)
		{
			cnt[i][j] += cnt[i][j - 1]; // 横に累積和を取る
		}
	}
	for (int i = 1; i < limit; i++)
	{
		rep(j,limit)
		{
			cnt[i][j] += cnt[i - 1][j]; // 縦に累積和を取る
		}
	}
	rep(i,limit)
	{
		rep(j,limit)
		{
			if (cnt[i][j] >= 1) // i番目に重なってるか
				ans[cnt[i][j]]++;
		}
	}
	rep(i,n) cout << ans[i+1] << endl;
	return 0;
}
