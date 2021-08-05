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

vector<pair<ll, ll>> prime_factorize(ll n)
{
	vector<pair<ll, ll>> res;
	for (ll a = 2; a * a <= n; a++)
	{
		if (n % a != 0) continue;
		ll ex = 0; //指数
		while (n % a == 0)
		{
			ex++;
			n /= a;
		}
		res.push_back({a, ex});
	}
	if (n != 1) res.push_back({n, 1});
	return res;
}

int main()
{
	ll n;
	cin >> n;
	int ex_sum = 0, ans = 0;
	vector<pair<ll, ll>> res = prime_factorize(n);
	for (auto p: res)
		ex_sum += p.second;
	while (ex_sum > 1)
	{
		ans++;
		if (ex_sum % 2 == 1) ex_sum++; // 奇数の場合は階層を一個増やす
		ex_sum /= 2; // 木構造で2ずつ分かれていく
	}
	cout << ans << endl;
	return 0;
}
