#include <iostream>

using namespace std;

int q = 0, n = 0, m = 0, wsk_wzorzec = 0;
bool czy_pasi = true;
string ciag1, ciag2;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> q;
    for (int z = 0; z < q; ++z)
    {
        cin >> n >> m >> ciag1 >> ciag2;
        wsk_wzorzec = 0;
        czy_pasi = false;
        for (int i = 0; i < ciag2.size(); ++i)
        {
            if (ciag1[wsk_wzorzec] == ciag2[i])
                wsk_wzorzec++;
            if (wsk_wzorzec == n)
            {
                czy_pasi = true;
                break;
            }
        }
        if (czy_pasi == true)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}