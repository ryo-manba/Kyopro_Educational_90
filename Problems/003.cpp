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

/*  木の直径は最短距離計算を2回する
    1. 単純パスの長さの最大値を求める。
    2. 頂点1から各頂点までの最短距離を求める。
    3. 最も最短距離が大きかった頂点からの最短距離を求める。
    4. その時に出現した最短距離の最大値が木の直径となる。
*/

int n;
vector<vector<int>> G;
vector<int> dist;

// BFSで最短距離を計算
void getdist(int start)
{
    dist.assign(n, INF);
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
    G.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 1 からの最短距離を求める
    // maxid1: 頂点 1 から最も離れている(最短距離が長い)頂点
    getdist(1);
    int maxn1 = -1, maxid1 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (maxn1 < dist[i])
        {
            maxn1 = dist[i];
            maxid1 = i;
        }
    }

    // 頂点 maxid1 からの最短距離を求める
    // maxn2: 木の直径(最短距離の最大値)
    getdist(maxid1);
    int maxn2 = -1;
    for (int i = 1; i <= n; i++)
        chmax(maxn2, dist[i]);

    cout << maxn2 + 1 << endl;
    return 0;
}