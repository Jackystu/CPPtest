#include <iostream>
using namespace std;

int main()
{
    double a1, a2, b1, b2, x, y;
    cin >> a1 >> a2 >> b1 >> b2;
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        cin >> x >> y;
        double det = a1 * b2 - a2 * b1;
        if (det == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
