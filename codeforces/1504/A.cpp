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

	int n = s.length();

	if (n == 1) {
		if (s[0] == 'a') {
			cout << "NO" << '\n';
		}
		else {
			s += "a";
			cout << "YES" << '\n';
			cout << s << '\n';
		}

		return;
	}

	bool ok = false;
	rep(i, 0, n) {
		if (s[i] != 'a') {
			ok = true;
			break;
		}
	}

	if (!ok) {
		cout << "NO" << '\n';
		return;
	}

	if (s[0] == s[n - 1]) {
		if (s[0] == 'a') {
			int cnt1 = 0, cnt2 = 0;
			rep(i, 0, n) {
				if (s[i] != 'a') break;
				cnt1++;
			}
			repR(i, n - 1, 0) {
				if (s[i] != 'a') break;
				cnt2++;
			}

			if (cnt1 >= cnt2) {
				s.insert(0, "a");
			}
			else {
				s.insert(n - 1, "a");
			}
		}
		else s.insert(0, "a");
	}
	else {
		if (s[0] == 'a') {
			s.insert(1, "a");
		}
		else s.insert(n - 1, "a");
	}

	cout << "YES" << '\n';
	cout << s << '\n';
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