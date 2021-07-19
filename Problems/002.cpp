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
	cin >> n;
	bool flag;
	vector<char> ans;
	if (n % 2 == 1)
	{
		cout << endl;
		return 0;
	}
	rep(i,n)
	{
		if (i < n / 2)
			ans.push_back('(');
		else
			ans.push_back(')');
	}
	do {
		int t = 0;
		flag = true;
		rep(i,n)
		{
			if (ans[i] == '(')
				t++;
			if (ans[i] == ')')
				t--;
			if (t < 0)
				flag = false;
		}
		if (!flag)
			continue;
		rep(i,n)
		{
			cout << ans[i];
			if (i == n - 1)
				cout << endl;
		}
	} while(next_permutation(ans.begin(), ans.end()));
	return 0;
}
