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
bool seen[100100], color[100100];
vector<ll> G[100100];
int paints = 0;

// 木の深さの偶奇で色を分ける
void dfs(ll v)
{
	for (auto u : G[v])
	{
		if (seen[u]) continue;
		seen[u] = true;
		if (color[v] == false) // 親の色が塗られてなかったら子を塗る
		{
			color[u] = true;
			paints++;
		}
		dfs(u); // 子でdfsする
	}
}

int main()
{
	cin >> n;
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	seen[0] = true;
	color[0] = true;
	paints++; // 1番頂点は塗った状態でスタートする
	dfs(0);
	bool flag = true;
	if (paints < n / 2) flag = false; // 色が塗られた回数が多い方から取る。
	int cnt = n / 2;
	rep(i, n) // n/2個出力する
	{
		if (cnt == 0) break;
		if (color[i] == flag)
		{
			if (i) cout << " ";
			cout << i + 1;
			cnt--;
		}
	}
	cout << endl;
	return 0;
}
