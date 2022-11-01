#include <iostream>
#include <vector>

using namespace std;

int n = 0;
char wczytany_znak;
vector<int> ciag;
vector<int> statystyki;

bool czy_fragment_pasuje()
{
    for (int i = 1; i < 4; ++i)
    {
        for (int j = i+1; j < 4; ++j)
        {
            if (statystyki[i] != 0 && statystyki[j] != 0 && statystyki[i] == statystyki[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool czy_mozemy_zbudowac(int dlugosc_fragmentu)
{
    statystyki = {0,0,0,0};

    for (int i = 0; i < dlugosc_fragmentu; ++i)
    {
        statystyki[ciag[i]]++;
    }

    if (czy_fragment_pasuje() == true)
    {
        return true;
    }

    for (int i = dlugosc_fragmentu; i < n; ++i)
    {
        statystyki[ciag[i]]++;
        statystyki[ciag[i-dlugosc_fragmentu]]--;
        if (czy_fragment_pasuje() == true)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'B')
        {
            ciag.push_back(1);
        }
        else if (wczytany_znak == 'C')
        {
            ciag.push_back(2);
        }
        else
        {
            ciag.push_back(3);
        }
    }

    for (int i = n; i >= 0; --i)
    {
        if (czy_mozemy_zbudowac(i) == true)
        {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}