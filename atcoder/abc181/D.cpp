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

bool Solve(string s)
{
	if (s.length() == 1) {
		if (s == "8")
			return true;

		return false;
	}
	else if (s.length() == 2) {
		if (stoi(s) % 8 == 0) {
			return true;
		}

		swap(s[0], s[1]);

		if (stoi(s) % 8 == 0) {
			return true;
		}

		return false;
	}

	vi freq(10, 0);
	for (auto c : s) {
		freq[c - '0']++;
	}

	if (freq[0] >= 3) { // 000 (in last 3 digit) is always divisible by 8
		return true;
	}

	for (int i = 104; i < 1000; i += 8) {
		string temp = to_string(i);

		vi freq2(10, 0);
		for (auto c : temp) {
			freq2[c - '0']++;
		}

		bool flag = false;

		for (int j = 0; j < 10; j++) {
			if (freq[j] < freq2[j]) {
				flag = true;
			}
		}

		if (!flag) {
			return true;
		}
	}

	return false;
}

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	if (Solve(s)) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}

	return 0;
}




