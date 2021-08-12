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

int	n;
int	a[100100], b[100100], dist[100100];
vector<int> G[100100]; // グラフ

void getdist(int start) // bfsで最短距離を求める
{
	for (int i = 1; i <= n; i++) dist[i] = INF;
	queue<int> que;
	que.push(start);
	dist[start] = 0;
	while (!que.empty())
	{
		int pos = que.front();
		que.pop();
		for (int to : G[pos])
		{
			if (dist[to] == INF)
			{
				dist[to] = dist[pos] + 1;
				que.push(to);
			}
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a[i] >> b[i];
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}

	getdist(1); // 頂点1からの最短距離を求める
	int maxi = -1, maxid = -1;
	for (int i = 1; i <= n; i++)
	{
		if (maxi < dist[i])
		{
			maxi = dist[i];
			maxid = i;
		}
	}
	getdist(maxid); // 頂点maxidからの最短距離を求める
	maxi = -1;
	for (int i = 1; i <= n; i++)
	{
		chmax(maxi, dist[i]);
	}
	cout << maxi + 1 << endl;
	return 0;
}
