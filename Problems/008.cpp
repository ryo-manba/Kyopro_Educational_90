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
	int n;
	string s;
	cin >> n >> s;
	int dp[100100][8] = {};
	string t = "atcoder";
	rep(i, n + 1) dp[i][0] = 1; // 番兵
	rep(i,n) rep(j,7)
	{
		if (s[i] != t[j])
			dp[i + 1][j + 1] = dp[i][j + 1];
		else
			dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
	}
	cout << dp[n][7] << endl;
	return 0;
}
