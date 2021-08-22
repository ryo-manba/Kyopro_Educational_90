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

int H, W, sx, sy, gx, gy;
int dist[1010][1010][4];
string S[1010];
struct state {
	int x, y, dir;
};
deque<state> deq;

void bfs()
{
	while (!deq.empty())
	{
		state u = deq.front();
		deq.pop_front();
		rep(i,4)
		{
			int tx = u.x + dx[i], ty = u.y + dy[i];
			int cost = dist[u.x][u.y][u.dir];
			if (u.dir != i)	cost += 1;
			if (0 <= tx && tx < H && 0 <= ty && ty < W && S[tx][ty] == '.' && dist[tx][ty][i] > cost) // 範囲内かチェック
			{
				dist[tx][ty][i] = cost;
				if (u.dir != i) deq.push_back({tx, ty, i});
				else deq.push_front({tx, ty, i});
			}
		}
	}
}

int main()
{
	cin >> H >> W;
	cin >> sx >> sy >> gx >> gy;
	sx--, sy--, gx--, gy--;
	rep(i,H) cin >> S[i];

	// 上下左右の状態を初期化する
	rep(i,H)
	{
		rep(j,W)
		{
			dist[i][j][0] = INF;
			dist[i][j][1] = INF;
			dist[i][j][2] = INF;
			dist[i][j][3] = INF;
		}
	}

	rep(i,4)
	{
		dist[sx][sy][i] = 0;
		deq.push_back({sx, sy, i});
	}
	bfs();
	int ans = INF;
	rep(i,4) chmin(ans, dist[gx][gy][i]);
	cout << ans << endl;
	return 0;
}

