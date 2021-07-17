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

ll base_conv1(string s, ll base)
{
	ll n = 0;

	rep(i, s.size())
		n = n * base + (s[i] - '0');

	return (n);
}

string base_conv2(ll n, ll base)
{
	string s;

	if (n == 0)
		return ("0");
	while (n > 0)
	{
		s.push_back(n % base + '0');
		n /= base;
	}
	reverse(s.begin(), s.end());
	return (s);
}

string change_num(string s)
{
	string h = "";

	rep(i,s.size())
	{
		if (s[i] == '8')
			h.push_back('5');
		else
			h.push_back(s[i]);
	}
	return (h);
}

int main()
{
	ll k, ten;
	string s, nine;
	cin >> s >> k;

	rep(i,k)
	{
		ten = base_conv1(s,8);
		nine = base_conv2(ten, 9);
		s = change_num(nine);
	}
	cout << s << endl;
	return 0;
}
