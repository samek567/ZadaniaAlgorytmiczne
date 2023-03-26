#include <iostream>

using namespace std;

string ciag1_wczytany, ciag2_wczytany, ciag1, ciag2;
bool czy_rozne_od_zera = false;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag1_wczytany >> ciag2_wczytany;

    for (int i = 0; i < ciag1_wczytany.size(); ++i)
    {
        if (ciag1_wczytany[i] != '0')
            czy_rozne_od_zera = true;
        if (czy_rozne_od_zera == true)
            ciag1.push_back(ciag1_wczytany[i]);
    }

    czy_rozne_od_zera = false;
    for (int i = 0; i < ciag2_wczytany.size(); ++i)
    {
        if (ciag2_wczytany[i] != '0')
            czy_rozne_od_zera = true;
        if (czy_rozne_od_zera == true)
            ciag2.push_back(ciag2_wczytany[i]);
    }

    if (ciag1.size() > ciag2.size())
        cout << '>' << '\n';
    else if (ciag1.size() < ciag2.size())
        cout << '<' << '\n';
    else
    {
        for (int i = 0; i < ciag1.size(); ++i)
        {
            if (ciag1[i] > ciag2[i])
            {
                cout << '>' << '\n';
                return 0;
            }
            else if (ciag2[i] > ciag1[i])
            {
                cout << '<' << '\n';
                return 0;
            }
        }
        cout << '=' << '\n';
    }

    return 0;
}