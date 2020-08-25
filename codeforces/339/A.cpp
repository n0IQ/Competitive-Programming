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

	string s;
	cin >> s;

	vector<int> v;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != '+')
		{
			v.push_back(s[i]-'0');
		}
	}

	vsort; // 1 2 3

	ostringstream ss;

	for (int i = 0, j = 0; i < s.length(); i++)
	{
		if (i % 2 == 0)
		{
			ss << v[j];
			j++;
		}
		else
		{
			ss << '+';
		}
	}

	string s1 = ss.str();

	cout << s1 << endl;

	return 0;
}


