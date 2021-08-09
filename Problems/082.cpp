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

unsigned long long l, r;
unsigned long long power10[22];

void init()
{
	power10[0] = 1;
	for (int i = 1; i <= 19; i++)
		power10[i] = (10ULL * power10[i - 1]);
}

ll solve(ll x)
{
	ll v1, v2;
	if (x % 2LL == 0)
	{
		v1 = (x / 2LL) % MOD;
		v2 = (x + 1LL) % MOD;
	}
	else
	{
		v1 = ((x + 1LL) / 2LL) % MOD;
		v2 = x % MOD;
	}
	return v1 * v2 % MOD;
}

int main()
{
	init();
	cin >> l >> r;
	ll ans = 0;
	for (int i = 1; i<= 19; i++)
	{
		unsigned long long vl = max(l, power10[i - 1]);
		unsigned long long vr = min(r, power10[i] - 1ULL);
		if (vl > vr) continue;
		ll val = (solve(vr) - solve(vl - 1) + MOD) % MOD;
		ans += 1LL * i * val;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
