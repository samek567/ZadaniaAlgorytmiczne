#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Patyczek
{
    int wartosc;
    int kolor;

    bool operator < (const Patyczek &patyczek) const
    {
        if (wartosc == patyczek.wartosc)
        {
            return kolor < patyczek.kolor;
        }
        return wartosc > patyczek.wartosc;
    }
};

int k = 0, n = 0, wczytany_patyczek = 0;
vector<vector<int>> patyczki;
Patyczek najwiekszy = {-1,-1},drugi_najwiekszy = {-1,-1};

void aktualizuj_maxy(int &wartosc, int &kolor)
{
    if (najwiekszy.wartosc == -1)
    {
        najwiekszy = {wartosc,kolor+1};
    }
    else if (drugi_najwiekszy.wartosc == -1)
    {
        if (najwiekszy.wartosc > wartosc)
        {
            drugi_najwiekszy = {wartosc,kolor+1};
        }
        else
        {
            drugi_najwiekszy = najwiekszy;
            najwiekszy = {wartosc,kolor+1};
        }
    }
    else
    {
        if (wartosc > najwiekszy.wartosc)
        {
            drugi_najwiekszy = najwiekszy;
            najwiekszy = {wartosc, kolor + 1};
        }
        else if (wartosc > drugi_najwiekszy.wartosc)
        {
            drugi_najwiekszy = {wartosc,kolor+1};
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        cin >> n;
        patyczki.push_back({});
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytany_patyczek;
            patyczki[i].push_back(wczytany_patyczek);
        }
        sort(patyczki[i].begin(),patyczki[i].end());
    }

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < patyczki[i].size(); ++j)
        {
            najwiekszy = {-1,-1};
            drugi_najwiekszy = {-1,-1};
            for (int f = 0; f < k; ++f)
            {
                // Szukamy binarnie
                if (i == f)
                {
                    continue;
                }
                int poczatek = -1;
                int koniec = patyczki[f].size();
                int srodek = 0;
                while (koniec - poczatek != 1)
                {
                    srodek = (poczatek + koniec) / 2;
                    if (patyczki[f][srodek] <= patyczki[i][j])
                    {
                        poczatek = srodek;
                    }
                    else
                    {
                        koniec = srodek;
                    }
                }
                if (poczatek != -1)
                {
                    if (patyczki[f][poczatek] <= patyczki[i][j])
                    {
                        aktualizuj_maxy(patyczki[f][poczatek],f);
                    }
                }
                if (najwiekszy.wartosc != -1 && drugi_najwiekszy.wartosc != -1)
                {
                    if (najwiekszy.wartosc + drugi_najwiekszy.wartosc > patyczki[i][j])
                    {
                        printf("%d %d %d %d %d %d",najwiekszy.kolor,najwiekszy.wartosc,drugi_najwiekszy.kolor,drugi_najwiekszy.wartosc,i+1,patyczki[i][j]);
                        return 0;
                    }
                }
            }
        }
    }

    printf("NIE");

    return 0;
}
