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

int main()
{
    int h, w;
    cin >> h >> w;
    int a[h][w];
    vector<int> x(h), y(w);
    
    rep(i,h) {
        rep(j,w) {
            cin >> a[i][j];
            x[i] += a[i][j];
            y[j] += a[i][j];
        }
    }

    rep(i,h) {
        rep(j,w) {
            if (j) cout << " ";
            cout << (x[i] + y[j] - a[i][j]);
            if (j == w - 1) cout << endl;
        }
    }
    return 0;
}