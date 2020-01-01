
/**
 https://open.kattis.com/problems/orders
 */

#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int MIN = 0xc0c0c0c0;
const int maxn = 1e5 + 5;
int main()
{
    string a, b;
    cin >> a >> b;

    //

    /**
     * delete the same leter from the start of 2 arrays
     */
    while(a[0] == b[0] && a.size() && b.size())
    {
        a.erase(0, 1);
        b.erase(0, 1);
    }
    /**
     * delete the same leter from the end of 2 arrays
     */
    while(a[a.size() - 1] == b[b.size() - 1] && a.size() && b.size())
    {
        a.erase(a.size() - 1, 1);
        b.erase(b.size() - 1, 1);
    }
    cout << b.size() << endl;
}
