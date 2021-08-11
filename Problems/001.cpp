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

ll n, k, l;
ll a[100100];

bool isOK(ll m)
{
	ll cnt = 0, pre = 0;
	rep(i,n)
	{
		if (a[i] - pre >= m && l - a[i] >= m)
		{
			cnt++;
			pre = a[i];
		}
	}
	if (cnt >= k) return true;
	return false;

}

ll binary_search()
{
	ll left = -1;
	ll right = l;

	while (abs(right - left) > 1) {
		ll mid = left + (right - left) / 2;
		if (isOK(mid) == false) right = mid;
		else left = mid;
	}
	return left;
}

int main()
{
	cin >> n >> l >> k;
	rep(i,n) cin >> a[i];

	ll ans = binary_search();
	cout << ans << endl;
	return 0;
}
