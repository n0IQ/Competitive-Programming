#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

#define fo(i,n) for(int i=0; i<n; i++)
#define vsort sort(v.begin(),v.end())
#define ll long long int

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	if (s1 > s2)
	{
		cout << 1 << endl;
	}
	else if (s1 < s2)
	{
		cout << -1 << endl;
	}
	else if (s1 == s2)
	{
		cout << 0 << endl;
	}

	return 0;
}


