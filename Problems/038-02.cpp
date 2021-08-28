#include <bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

int main()
{
	Bint a, b, ans = 0;
	cin >> a >> b;
	ans = lcm(a, b);
	if (ans > (int64_t)1e18) cout << "Large" << endl;
	else cout << ans << endl;
	return 0;
}
