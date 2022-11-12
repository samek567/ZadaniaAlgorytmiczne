#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P
{
    int mod;
    string ciag;
};

int n = 0, wczytana_liczba = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;

        if (wczytana_liczba == 1)
        {
            cout << "1" << "\n";
            continue;
        }

        queue<P> Q;
        Q.push({1,"1"});

        vector<bool> czy_mamy_reszte;
        czy_mamy_reszte.assign(wczytana_liczba, false);
        czy_mamy_reszte[1] = true;

        while(!Q.empty())
        {
            P spr = Q.front();
            if (spr.ciag.size() > 100)
            {
                cout << "BRAK" << "\n";
                break;
            }

            P przedluzenie_zero = {(spr.mod * 10) % wczytana_liczba,spr.ciag + '0'};
            P przedluzenie_jeden = {(spr.mod * 10 + 1) % wczytana_liczba,spr.ciag + '1'};

            if (przedluzenie_zero.mod == 0)
            {
                cout << przedluzenie_zero.ciag << "\n";
                break;
            }
            if (przedluzenie_jeden.mod == 0)
            {
                cout << przedluzenie_jeden.ciag << "\n";
                break;
            }

            if (czy_mamy_reszte[przedluzenie_zero.mod] == false)
            {
                Q.push(przedluzenie_zero);
                czy_mamy_reszte[przedluzenie_zero.mod] = true;
            }
            if (czy_mamy_reszte[przedluzenie_jeden.mod] == false)
            {
                Q.push(przedluzenie_jeden);
                czy_mamy_reszte[przedluzenie_jeden.mod] = true;
            }

            Q.pop();
        }
    }

    return 0;
}
