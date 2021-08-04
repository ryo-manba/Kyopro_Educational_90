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

ll mod_pow(ll x, ll n)
{
	ll ret = 1;
	while (n > 0)
	{
		if (n % 2 == 1) ret = ret * x % MOD;
		x = x * x % MOD; // 偶数の場合2冪乗を作る(nの2^x乗 -> nの2^(x+1)乗)
		n /= 2;
	}
	return ret;
}

int main()
{
	ll n, k, ans = 0;
	cin >> n >> k;

	if (k == 1)
	{
		if (n == 1) ans = 1;
		else ans = 0;
	}
	else if (n == 1)
		ans = k % MOD;
	else if (n == 2)
		ans = k * (k - 1) % MOD;
	else
		ans = k * (k - 1) % MOD * mod_pow(k - 2, n - 2) % MOD;
	cout << ans << endl;
	return 0;
}
