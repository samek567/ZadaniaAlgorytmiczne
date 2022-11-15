#include <iostream>
#include <vector>

using namespace std;

int n = 0, wsk_zmian = 0;
long long s = 0, suma_ciagu = 0, suma_szukana = 0, akt_suma = 0, wyn = 0;
vector<long long> mozliwosci;
vector<long long> idx_y_zmiany;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    suma_ciagu = (n-1) * n / 2; // Pierwszy + ostatni / 2 * liczba elementow.


    for (int i = 1; i < n; ++i)
    {
        mozliwosci.push_back((n-i) * 2);
    }

    // Zachlannie szukamy sumy.

    suma_szukana = suma_ciagu - s;

    for (int i = 0; i < n-1; ++i)
    {
        if (akt_suma + mozliwosci[i] == suma_szukana)
        {
            akt_suma += mozliwosci[i];
            idx_y_zmiany.push_back(i+1);
            break;
        }
        if (akt_suma + mozliwosci[i] < suma_szukana)
        {
            idx_y_zmiany.push_back(i+1);
            akt_suma += mozliwosci[i];
        }
    }

    if (akt_suma != suma_szukana)
    {
        cout << "NIE" << '\n';
        return 0;
    }

    cout << "0" << '\n';

    for (int i = 1; i < n; ++i)
    {
        if (wsk_zmian < idx_y_zmiany.size())
        {
            if (idx_y_zmiany[wsk_zmian] == i)
            {
                wyn -= 1;
                wsk_zmian++;
                cout << wyn << '\n';
                continue;
            }
        }
        wyn += 1;
        cout << wyn << '\n';
    }

    return 0;
}
