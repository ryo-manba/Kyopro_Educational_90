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

ll dp[100100];

int main()
{
	ll k;
	cin >> k;
	if (k % 9 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	dp[0] = 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			dp[i + j] = (dp[i + j] + dp[i]) % MOD;
		}
	}
	cout << dp[k] << endl;
	return 0;
}
