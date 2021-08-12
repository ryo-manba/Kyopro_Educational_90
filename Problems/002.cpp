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

	if (n % 2 == 1) return 0;
	string s;
	rep(i,n / 2) s.push_back('(');
	rep(i,n / 2) s.push_back(')');

	do
	{
		int cnt = 0;
		rep(i,n)
		{
			if (s[i] == '(') cnt++;
			if (s[i] == ')') cnt--;
			if (cnt == -1) break;
		}
		if (cnt == -1) continue;
		cout << s << endl;
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}
