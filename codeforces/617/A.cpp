#include <iostream>

using namespace std;

int main()
{
	int x, i = 0;
	cin >> x;
	int count = 0;

	while (i < x)
	{
		if (i <= x)
		{
			i += 5;
		}
		else if (i <= x)
		{
			i += 4;
		}
		else if (i <= x)
		{
			i += 3;
		}
		else if (i <= x)
		{
			i += 2;
		}
		else if (i <= x)
		{
			i += 1;
		}
		count++;
	}

	cout << count;
}
