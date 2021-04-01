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
    int n;
    cin >> n;
    vector<char> ans;
    if (n % 2 == 1) // n が奇数だった場合はreturn
    {
        cout << endl;
        return 0;
    }
    rep(i, n / 2) ans.push_back('(');
    rep(i, n / 2) ans.push_back(')');

    bool flag = true;
    do {
        rep(i,n) cout << ans[i];
        for (int k = 0; k < n; k += 2)
        {
            if (ans[k] == '(' && ans[k + 1] == ')')  // n 個の () が出来たら終了
                flag = true;
            else
            {
                flag = false;
                break;
            }
        }
        cout << endl;
        if (flag)   break;
    } while(next_permutation(ans.begin(), ans.end()));
    return 0;
}