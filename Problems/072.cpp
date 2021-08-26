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

int h, w;
string s[20];
bool seen[20][20];
int ans = 0;

void dfs(int sx, int sy, int gx, int gy, int depth)
{
	if (sx == gx && sy == gy && depth > 0)
	{
		chmax(ans, depth);
		return;
	}

	rep(i,4)
	{
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if (nx < 0 || nx >= h|| ny < 0 || ny >= w) continue;
		if (s[nx][ny] == '#' || seen[nx][ny] == true) continue;
		seen[nx][ny] = true;
		dfs(nx, ny, gx, gy, depth + 1);
		seen[nx][ny] = false; // 復元する
	}
}

int main()
{
	cin >> h >> w;
	rep(i,h) cin >> s[i];
	rep(i,h)
	{
		rep(j,w)
		{
			if (s[i][j] == '#') continue;
			dfs(i, j, i, j, 0);
		}
	}
	if (ans <= 3) ans = -1;
	cout << ans << endl;
	return 0;
}
