#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve()
{
	string s;
	cin >> s;

	int n = s.length(), cap = 0, small = 0, digit = 0;
	bool ok1 = 0, ok2 = 0, ok3 = 0;

	rep(i, 0, n) {
		if ((int)s[i] >= 65 && (int)s[i] <= 90) ok1 = 1, cap++;
		if ((int)s[i] >= 97 && (int)s[i] <= 122) ok2 = 1, small++;
		if ((int)s[i] >= 48 && (int)s[i] <= 57) ok3 = 1, digit++;
	}

	if (ok1 && ok2 && ok3) {
		cout << s << '\n';
		return;
	}

	if (ok1) {
		if (!ok2) {
			rep(i, 0, n) {
				if (((int)s[i] >= 65 && (int)s[i] <= 90) && (cap >= 2)) {
					s.replace(i, 1, "a");
					break;
				}
				if (((int)s[i] >= 48 && (int)s[i] <= 57) && (digit >= 2)) {
					s.replace(i, 1, "a");
					break;
				}
			}
		}

		if (!ok3) {
			rep(i, 0, n) {
				if (((int)s[i] >= 65 && (int)s[i] <= 90) && (cap >= 2)) {
					s.replace(i, 1, "1");
					break;
				}
				if (((int)s[i] >= 97 && (int)s[i] <= 122) && (small >= 2)) {
					s.replace(i, 1, "1");
					break;
				}
			}
		}


		cout << s << '\n';
	}
	else if (ok2) {
		if (!ok1) {
			rep(i, 0, n) {
				if (((int)s[i] >= 97 && (int)s[i] <= 122) && (small >= 2)) {
					s.replace(i, 1, "A");
					break;
				}
				if (((int)s[i] >= 48 && (int)s[i] <= 57) && (digit >= 2)) {
					s.replace(i, 1, "A");
					break;
				}
			}
		}

		if (!ok3) {
			rep(i, 0, n) {
				if (((int)s[i] >= 65 && (int)s[i] <= 90) && (cap >= 2)) {
					s.replace(i, 1, "1");
					break;
				}
				if (((int)s[i] >= 97 && (int)s[i] <= 122) && (small >= 2)) {
					s.replace(i, 1, "1");
					break;
				}
			}
		}


		cout << s << '\n';
	}
	else {
		if (!ok1) {
			rep(i, 0, n) {
				if (((int)s[i] >= 97 && (int)s[i] <= 122) && (small >= 2)) {
					s.replace(i, 1, "A");
					break;
				}
				if (((int)s[i] >= 48 && (int)s[i] <= 57) && (digit >= 2)) {
					s.replace(i, 1, "A");
					break;
				}
			}
		}

		if (!ok2) {
			rep(i, 0, n) {
				if (((int)s[i] >= 65 && (int)s[i] <= 90) && (cap >= 2)) {
					s.replace(i, 1, "a");
					break;
				}
				if (((int)s[i] >= 48 && (int)s[i] <= 57) && (digit >= 2)) {
					s.replace(i, 1, "a");
					break;
				}
			}
		}


		cout << s << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}