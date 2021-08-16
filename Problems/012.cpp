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

class UnionFind {
public:
	vector<int> par;

	void init(int sz)
	{
		par.resize(sz, -1);
	}

	int root(int pos)
	{
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return (par[pos]);
	}

	void unite(int u, int v)
	{
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}

	bool same(int u, int v)
	{
		if (root(u) == root(v)) return true;
		return false;
	}
};

int	H, W, Q;
UnionFind UF;
bool used[2010][2010];

void query1(int px, int py)
{
	rep(i,4)
	{
		int sx = px + dx[i], sy = py + dy[i];
		if (used[sx][sy] == false) continue;
		int hash1 = (px - 1) * W + (py - 1);
		int hash2 = (sx - 1) * W + (sy - 1);
		UF.unite(hash1, hash2);
	}
	used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy)
{
	if (used[px][py] == false || used[qx][qy] == false)
		return false;

	int hash1 = (px - 1) * W + (py - 1);
	int hash2 = (qx - 1) * W + (qy - 1);
	if (UF.same(hash1, hash2) == true) return true;
	return false;
}

int main()
{
	cin >> H >> W >> Q;

	UF.init(H * W);
	rep(i,Q)
	{
		int q;
		cin >> q;
		if (q == 1)
		{
			int r, c;
			cin >> r >> c;
			query1(r,c); // 上下左右の赤いマスと連結させる
		}
		if (q == 2)
		{
			int ra, ca, rb, cb;
			cin >> ra >> ca >> rb >> cb;
			bool ans = query2(ra, ca, rb, cb); // 連結判定
			if (ans == true) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
