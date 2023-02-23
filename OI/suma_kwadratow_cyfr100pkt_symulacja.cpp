#include <iostream>

using namespace std;

int t = 0, liczba = 0;
string wczytany_ciag;

inline int suma_cyfr(int x)
{
    int wyn = 0;
    while (x > 0)
    {
        wyn += (x % 10) * (x % 10);
        x /= 10;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        liczba = 0;
        cin >> wczytany_ciag;
        if (wczytany_ciag == "1" || wczytany_ciag == "4")
        {
            cout << wczytany_ciag << '\n';
            continue;
        }
        for (int i = 0; i < wczytany_ciag.size(); ++i)
        {
            if (wczytany_ciag[i] == '1')
                liczba += 1;
            else if (wczytany_ciag[i] == '2')
                liczba += 4;
            else if (wczytany_ciag[i] == '3')
                liczba += 9;
            else if (wczytany_ciag[i] == '4')
                liczba += 16;
            else if (wczytany_ciag[i] == '5')
                liczba += 25;
            else if (wczytany_ciag[i] == '6')
                liczba += 36;
            else if (wczytany_ciag[i] == '7')
                liczba += 49;
            else if (wczytany_ciag[i] == '8')
                liczba += 64;
            else if (wczytany_ciag[i] == '9')
                liczba += 81;
        }
        if (liczba == 1 || liczba == 4)
        {
            cout << wczytany_ciag << " " << liczba << '\n';
            continue;
        }
        cout << wczytany_ciag << " ";
        while(liczba != 1 && liczba != 4)
        {
            cout << liczba << " ";
            liczba = suma_cyfr(liczba);
        }
        cout << liczba << '\n';
    }
    return 0;
}
