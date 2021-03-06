#include <bits/stdc++.h>
using namespace std;

#define pb push_back
//#define mp make_pair
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
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

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
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

unordered_map<char, char> mp;

bool IsCorrect(string s1, string s2, int h, int m)
{
	for (auto &c : s1) {
		if (mp.find(c) == mp.end()) {
			return false;
		}

		c = mp[c];
	}

	for (auto &c : s2) {
		if (mp.find(c) == mp.end()) {
			return false;
		}

		c = mp[c];
	}

	string s = s1 + s2;
	reverse(all(s));

	s1 = s.substr(0, 2), s2 = s.substr(2, 2);

	return (stoi(s1) < h && stoi(s2) < m);
}

void solve()
{
	int h, m;
	string s;

	cin >> h >> m >> s;

	mp = {{'0', '0'}, {'1', '1'}, {'2', '5'}, {'5', '2'}, {'8', '8'}};
	string s1 = s.substr(0, 2), s2 = s.substr(3, 2);

	while (1) {
		if (IsCorrect(s1, s2, h, m)) {
			cout << s1 << ":" << s2 << '\n';
			return;
		}

		int new_h = 0, new_m = 0;

		if ((stoi(s2) + 1) % m == 0) {
			new_h = (stoi(s1) + 1) % h;
			new_m = (stoi(s2) + 1) % m;
		}
		else {
			new_h = stoi(s1);
			new_m = stoi(s2) + 1;
		}

		s1 = to_string(new_h);
		s2 = to_string(new_m);

		if (s1.length() == 1) {
			s1.pb('0');
			reverse(all(s1));
		}

		if (s2.length() == 1) {
			s2.pb('0');
			reverse(all(s2));
		}
	}
}

int main()
{
	fastio;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}