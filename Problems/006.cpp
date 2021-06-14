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

/*  辞書順最小は前から貪欲法 */
/*  最終的な文字列が K 文字であることを考えると、TLEので配列にc[i][j] を前計算する */
/*  累積的に計算することで短縮できる */

int nex[100100][26];

int main()
{
    string s;
    int k;
    cin >> s >> k;

    /* 前計算 */
    /* nex[文字の長さ][0] ~ [25] まで文字の長さで埋める */
    rep(i,26) nex[s.size()][i] = s.size();
    for (int i = (int)s.size() - 1; i >= 0; i--)
    {
        rep(j,26)
        {
            /* a(ascii)61 を引くことで 0 ~ 26 の数字に変わる */
            if ((int)(s[i] - 'a') == j)
                nex[i][j] = i;
            else
                nex[i][j] = nex[i + 1][j];
        }
    }

    string  ans = "";
    int     curr = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int nex_pos = nex[curr][j];
            int max_pos =(int)(s.size() - nex_pos - 1) + i;
            if (max_pos >= k)
            {
                ans += (char)('a' + j);
                curr = nex_pos + 1;
                break;
            }
        }
    }

    cout << ans << endl;
    return (0);
}