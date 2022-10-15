#include <iostream>

using namespace std;

struct Element
{
    int y;
    int x;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int l = 0;
    int p = 0;

    cin >> n >> l >> p;
    int szachownica[n][l+p];
    int prefix[n][l+p];
    int wczytany_znak = 0;
    int suma = 0;
    int max_dodatnie = 0;
    int min_ujemne = 0;

    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytany_znak;
            suma += wczytany_znak;
            if (wczytany_znak > 0)
            {
                max_dodatnie += wczytany_znak;
            }
            else
            {
                min_ujemne += wczytany_znak;
            }
            szachownica[n-j-1][i] = wczytany_znak;
        }
    }

    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytany_znak;
            suma += wczytany_znak * -1;
            szachownica[n-j-1][i+l] = wczytany_znak * -1;
            if (szachownica[n-j-1][i+l] > 0)
            {
                max_dodatnie += szachownica[n-j-1][i+l];
            }
            else
            {
                min_ujemne += szachownica[n-j-1][i+l];
            }
        }
    }

    for (int i = 0; i < l+p; ++i)
    {
        int s = 0;
        for (int j = 0; j < n; ++j)
        {
            s += szachownica[j][i];
            prefix[j][i] = s;
        }
    }

    if (suma == 0)
    {
        cout << "0";
        return 0;
    }

    int statystyki[abs(min_ujemne)+max_dodatnie+1];
    int tymczasowe_min[abs(min_ujemne)+max_dodatnie+1];
    for (int i = 0; i <= max_dodatnie+abs(min_ujemne); ++i)
    {
        statystyki[i] = 0;
        tymczasowe_min[i] = 0;
    }

    for (int j = 0; j < l+p; ++j)
    {
        // Sprawdzamy, gdzie mozemy zrobic kolejne opcje.
        for (int k = max_dodatnie; k >= min_ujemne; --k)
        {
            if (statystyki[k+abs(min_ujemne)] == 0)
            {
                continue;
            }
            for (int i = 0; i < n; ++i)
            {
                if (tymczasowe_min[k+abs(min_ujemne)+prefix[i][j]] == 0)
                {
                    tymczasowe_min[k+prefix[i][j]+abs(min_ujemne)] = statystyki[k+abs(min_ujemne)] + i + 1;
                }
                else
                {
                    tymczasowe_min[k+prefix[i][j]+abs(min_ujemne)] = min(tymczasowe_min[k+prefix[i][j]+abs(min_ujemne)],statystyki[k+abs(min_ujemne)]+i+1);
                }
            }
        }
        // Ustawiamy poczatkowe miejsca statystyk.
        for (int b = 0; b < n; ++b)
        {
            if (tymczasowe_min[prefix[b][j]+abs(min_ujemne)] == 0)
            {
                tymczasowe_min[prefix[b][j]+abs(min_ujemne)] = b+1;
            }
            tymczasowe_min[prefix[b][j]+abs(min_ujemne)] = min(tymczasowe_min[prefix[b][j]+abs(min_ujemne)],b+1);
        }

        // Laczymy tymczasowy min z glownymi statystykami
        for (int c = min_ujemne; c <= max_dodatnie; ++c)
        {
            if (tymczasowe_min[c+abs(min_ujemne)] == 0)
            {
                continue;
            }
            if (statystyki[c+abs(min_ujemne)] == 0)
            {
                statystyki[c+abs(min_ujemne)] = tymczasowe_min[c+abs(min_ujemne)];
            }
            else
            {
                statystyki[c+abs(min_ujemne)] = min(statystyki[c+abs(min_ujemne)],tymczasowe_min[c+abs(min_ujemne)]);
            }
        }
    }

    cout << statystyki[suma+abs(min_ujemne)];
    return 0;
}