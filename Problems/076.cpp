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
	int	n, j = 0;
	ll sum = 0, now = 0;
	bool flag = false;
	cin >> n;
	vector<ll> a(n);
	rep(i,n)
	{
		cin >> a[i];
		sum += a[i];
	}
	rep(i,n)
	{
		while (now * 10 < sum)
		{
			now += a[j];
			j++;
			j %= n;
		}
		if (now * 10 == sum)
		{
			flag = true;
			break;
		}
		now -= a[i];
	}
	if (flag == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
