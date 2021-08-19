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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	map<int,int> mp;
	set<int> st;

	int j = 0, ans = 0;
	bool flag = true;
	rep(i,n)
	{
		st.insert(a[i]);
		mp[a[i]]++;
		if (st.size() > k) // 要素数がkを超えた場合
		{
			chmax(ans, i - j); // ansには要素が超えるまでに進めた数の最大値
			while (flag)
			{
				mp[a[j]]--;
				if (mp[a[j]] == 0) // 要素数が0になったらsetから消す
				{
					st.erase(a[j]);
					flag = false;
				}
				j++;
			}
			flag = true;
		}
	}
	if (ans == 0) ans = n; // ansが0の場合はすべての要素が条件を満たす場合
	cout << ans << endl;
	return 0;
}

