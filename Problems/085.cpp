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

vector<ll> divisor(ll n)
{
	vector<ll> res;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			res.push_back(i);
			if (n / i != i) res.push_back(n / i); // 重複しないなら n / i も約数として付け足す
		}
	}
	sort(res.begin(),res.end());
	return res;
}

int main()
{
	ll n;
	cin >> n;

	vector<ll> div = divisor(n);
	ll ans = 0;
	for (auto i : div)
	{
		for (auto j : div)
		{
			if (j < i) continue;
			ll k = n / i / j;
			if (k >= j && i * j * k == n) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
