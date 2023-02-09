#include <iostream>

using namespace std;

int zag = 0, wyn = 0;
string ciag;

int main()
{
    // O(N)
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> ciag;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == '(')
            zag++;
        else
        {
            if (zag == 0)
                wyn++;
            else
                zag--;
        }
    }
    cout << wyn + zag << '\n';
    return 0;
}