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

int	h, w;
int p[10][10010];

int	maxi_w(vector<int> vec)
{
	map<int, int> mp;
	int ret = 0;
	rep(i,vec.size())
	{
		mp[vec[i]]++;
		chmax(ret, mp[vec[i]]);
	}
	return ret;
}

int main()
{
	cin >> h >> w;
	rep(i,h) rep(j,w) cin >> p[i][j];

	int ans = 0;
	for (int i = 1; i < (1 << h); i++)
	{
		vector<int> vec;
		rep(j,w) // 列をビットが立っている部分を全て見ながら横に進む
		{
			int idx = -1;
			bool flag = false;
			rep(k,h)
			{
				if ((i & (1 << k)) == 0) continue; // ビットが立ってなかったらcontinue;
				if (idx == -1) idx = p[k][j]; // 最初のビットが立っている地点で,p[k][j]の値になる
				else if (idx != p[k][j]) flag = true; // 残りのビットが立っている値がidxと違っていたらflagを立てる(同じ数字じゃない場合)
			}
			if (flag == false) vec.push_back(idx); // ビットが立っている値が全て同じ数字だったら配列に追加する。
		}
		int cntH = 0, cntW = maxi_w(vec); // cntWには横で条件を満たしている数
		rep(j,h)
		{
			if ((i & (1 << j)) != 0) cntH += 1; // cntHには縦で条件を満たしている数
		}
		chmax(ans, (cntH * cntW)); // ansは縦横で条件を満たしている個数
	}
	cout << ans << endl;
	return 0;
}


