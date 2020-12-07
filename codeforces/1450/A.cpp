#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all v.begin(),v.end()
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

	int T;
	cin >> T;

	while (T-- > 0)
	{
		int n;
		cin >> n;

		string s;
		cin >> s;

		int count = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'b') {
				s.erase(s.begin() + i);
				count++;
				i = -1;
			}
		}

		string s2 = "";

		for (int i = 0; i < count; i++) {
			s2 += 'b';
		}

		s2 += s;

		cout << s2 << '\n';
	}

	return 0;
}