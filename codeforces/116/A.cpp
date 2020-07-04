#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int max1 = 0, max2 = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        max1 -= a;
        max1 += b;

        if (max2 < max1)
        {
            max2 = max1;
        }
    }

    cout << max2 << endl;
    
    return 0;
}

