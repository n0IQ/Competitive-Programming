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
	int k;
	cin >> s >> k;

	int cnt = 0, candies = 0, flakes = 0, n = sz(s);
	rep(i, 0, n) {
		if (s[i] == '?') candies++, cnt++;
		else if (s[i] == '*') flakes++, cnt++;
	}

	int len = n - cnt;
	if (len == k) {
		for (int i = 0; i < n; ) {
			if (s[i] == '?' || s[i] == '*') s.erase(s.begin() + i);
			else i++;
		}

		cout << s << '\n';
		return;
	}
	else if (len > k) {
		int rem = len - k;
		if (rem > cnt) {
			cout << "Impossible";
			return;
		}
		else {
			for (int i = 0; i < n; ) {
				if (rem == 0) break;
				if (s[i] == '?' || s[i] == '*') {
					s.erase(s.begin() + i - 1);
					rem--;
				}
				else i++;
			}

			n = sz(s);

			for (int i = 0; i < n; ) {
				if (s[i] == '?' || s[i] == '*') s.erase(s.begin() + i);
				else i++;
			}

			cout << s << '\n';
			return;
		}
	}
	else {
		if (flakes <= 0) {
			cout << "Impossible";
			return;
		}

		int rem = k - len;

		for (int i = 0; i < n; ) {
			if (s[i] == '*') {
				s.insert(i, rem, s[i - 1]);
				break;
			}
			else i++;
		}

		n = sz(s);

		for (int i = 0; i < n; ) {
			if (s[i] == '?' || s[i] == '*') s.erase(s.begin() + i);
			else i++;
		}

		cout << s << '\n';
		return;
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
	//cin >> t;
	while (t--) solve();

	return 0;
}