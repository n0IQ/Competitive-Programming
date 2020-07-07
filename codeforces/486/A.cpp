#include <iostream>

using namespace std;

int main()
{
    long long n,sum=0;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2;
    }
    else
    {
        sum = -((n + 1) / 2);
        cout << sum;
    }

    return 0;
    
}

