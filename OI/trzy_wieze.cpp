#include <iostream>
#include <vector>

using namespace std;

int n = 0, wynik = 0;
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

    for (int i = 0; i <= 2 && i < n; ++i)
    {
        statystyki = {0,0,0,0};
        for (int j = i; j < n; ++j)
        {
            statystyki[ciag[j]]++;
            if (czy_fragment_pasuje() == true)
            {
                wynik = max(wynik,j-i+1);
            }
        }
    }

    for (int i = n-1; i >= n - 3 && i >= 0; --i)
    {
        statystyki = {0,0,0,0};
        for (int j = i; j >= 0; --j)
        {
            statystyki[ciag[j]]++;
            if (czy_fragment_pasuje() == true)
            {
                wynik = max(wynik,i-j+1);
            }
        }
    }

    cout << wynik << "\n";

    return 0;
}