#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 != x2 && y1 != y2 && abs(x2 - x1) != abs(y2 - y1)) {
		cout << -1 << '\n';
	}
	else if (x1 == x2) {
		cout << x1 + abs(y2 - y1) << " " << y1 << " " << x2 + abs(y2 - y1) << " " << y2 << '\n';
	}
	else if (y1 == y2) {
		cout << x1 << " " << y1 + abs(x2 - x1) << " " << x2 << " " << y2 + abs(x2 - x1) << '\n';
	}
	else {
		cout << x1 << " " << y2 << " " << x2 << " " << y1 << '\n';
	}

	return 0;
}