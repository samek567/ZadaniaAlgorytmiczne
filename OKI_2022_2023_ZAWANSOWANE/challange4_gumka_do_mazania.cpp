#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n = 0;
bool czy_robimy_dalej = true;
string wczytany_ciag, wyn;
vector<string> wyrazy;
vector<int> od_ktorego_szukamy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_ciag;
        od_ktorego_szukamy.push_back(0);
        wyrazy.push_back(wczytany_ciag);
    }

    for (char i = 'z'; i >= 'a' && czy_robimy_dalej == true; --i)
    {
        int ile_max_mozna = INT_MAX;
        for (int j = 0; j < n; ++j)
        {
            int ile = 0;
            for (int k = od_ktorego_szukamy[j]; k < wyrazy[j].size(); ++k)
            {
                if (wyrazy[j][k] == i)
                {
                    ile++;
                }
            }
            ile_max_mozna = min(ile_max_mozna,ile);
            if (ile_max_mozna == 0)
            {
                break;
            }
        }

        if (ile_max_mozna != 0)
        {
            for (int j = 0; j < ile_max_mozna; ++j)
            {
                wyn += i;
            }

            for (int j = 0; j < n && czy_robimy_dalej == true; ++j)
            {
                int licznik = 0;
                for (int k = od_ktorego_szukamy[j]; k < wyrazy[j].size(); ++k)
                {
                    if (wyrazy[j][k] == i)
                    {
                        licznik++;
                    }
                    if (licznik == ile_max_mozna)
                    {
                        od_ktorego_szukamy[j] = k + 1;
                        if (od_ktorego_szukamy[j] == wyrazy[j].size())
                        {
                            czy_robimy_dalej = false;
                        }
                        break;
                    }
                }
            }
        }
    }

    if (wyn > "bitek")
    {
        printf("%s", wyn.c_str());
    }
    else
    {
        printf("bitek");
    }

    return 0;
}