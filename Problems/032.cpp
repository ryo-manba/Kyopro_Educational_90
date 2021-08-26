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

int n, m;
int a[20][20];
int x[100], y[100];
bool naka[100][100];

int main()
{
	cin >> n;
	rep(i,n) rep(j,n) cin >> a[i][j];
	cin >> m;
	rep(i,m) cin >> x[i] >> y[i];

	vector<int> vec;
	rep(i,n) vec.push_back(i+1); // 順列全探索用の配列
	rep(i,m) // バトンを渡せないところをチェックする
	{
		naka[x[i]][y[i]] = true;
		naka[y[i]][x[i]] = true;
	}

	int ans = INF;
	do
	{
		int sum = 0;
		bool flag = true;
		rep(i,n - 1)
		{
			if (naka[vec[i]][vec[i + 1]] == true) // バトンが渡せないところがあればその数列は満たさない
			{
				flag = false;
				break;
			}
		}
		if (flag == true) // ゴールにたどり着けたらそれまでのコストを計算する
		{
			rep(i,n) sum += a[vec[i]- 1][i];
			chmin(ans, sum);
		}
	} while(next_permutation(vec.begin(), vec.end()));

	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}
