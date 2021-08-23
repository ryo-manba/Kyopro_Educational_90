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

ll n, k;
const ll mod = 100000;
vector<int> num(mod), seen(mod, -1);

// 前処理で100000通りのパターンを求めておく
void digit_sum()
{
	for (int i = 0; i < mod; i++)
	{
		int j = i;
		int	tmp = 0;
		while (j > 0)
		{
			tmp += j % 10;
			j /= 10;
		}
		num[i] = (tmp + i) % mod;
	}
}

int main()
{
	ll n, k;
	cin >> n >> k;

	digit_sum();
	int cnt = 0;
	while (seen[n] == -1) // 二回目の周期に入ったら抜ける
	{
		seen[n] = cnt;
		n = num[n];
		cnt++;
	}
	int cycle = cnt - seen[n]; // 周期までの数からその先頭の値を引く
	if (k >= seen[n])
	{
		k = (k - seen[n]) % cycle + seen[n];
	}
	int ans = -1;
	rep(i,mod)
	{
		if (seen[i] == k)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}
