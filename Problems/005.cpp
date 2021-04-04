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

/* (小課題1) 余りを持って桁DP
    ex) n = 8, b = 7, c = {1, 4, 9}, k = 3
        dp[3][0] = 3 (7 で割りきれる 3 桁整数が {119, 441, 994} の3つであるため)
        dp[i + 1][(10j + k) mod b] -> dp[3 + 1][(10j + 3) mod 7]
    このように遷移させていくことでO(nbk)で解ける。
*/

int main()
{
    ll n, b, k;
    cin >> n >> b >> k;
    vector<ll> c(k + 1);
    for (int i = 1; i <= k; i++) cin >> c[i];

    // dp[上から何桁目][現時点での b で割った余り] = 通り数
    ll dp[10010][33];   

    dp[0][0] = 1;
    rep(i,n) {
        rep(j,b) {
            for (int m = 1; m <= k; m++) {
                int tmp = (10 * j + c[m]) % b;
                dp[i + 1][tmp] += dp[i][j];
                dp[i + 1][tmp] %= MOD;
            }
        }
    }

    cout << dp[n][0] << endl;
    return 0;
}