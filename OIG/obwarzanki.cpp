#include <iostream>
#include <vector>

using namespace std;

struct Obwarzanek
{
    int srednica_w;
    int srednica_z;
};

bool czy_mozna_przewlec (Obwarzanek &obw_1, Obwarzanek &obw_2)
{
    if (obw_1.srednica_w >= obw_2.srednica_z || obw_2.srednica_w >= obw_1.srednica_z)
    {
        return true;
    }
    return false;
}

Obwarzanek polacz(Obwarzanek &obw_1, Obwarzanek &obw_2)
{
    Obwarzanek wyn = {min(obw_1.srednica_w,obw_2.srednica_w),max(obw_1.srednica_z,obw_2.srednica_z)};
    return wyn;
}

int zdejmij_lewo (int &idx_poczatek, Obwarzanek obwarzanki[], int &n)
{
    Obwarzanek polaczony = obwarzanki[idx_poczatek-1];
    int l = 0;
    for (int i = idx_poczatek - 2; i >= 0; --i)
    {
        bool czy_dodajemy = false;
        if (!czy_mozna_przewlec(polaczony,obwarzanki[i]))
        {
            polaczony = polacz(polaczony,obwarzanki[i]);
            l++;
        }
    }

    return l;
}

int zdejmij_prawo (int &idx_poczatek, Obwarzanek obwarzanki[], int &n)
{
    Obwarzanek polaczony = obwarzanki[idx_poczatek-1];
    int l = 0;
    for (int i = idx_poczatek; i < n; ++i)
    {
        bool czy_dodajemy = false;
        if (!czy_mozna_przewlec(polaczony,obwarzanki[i]))
        {
            polaczony = polacz(polaczony,obwarzanki[i]);
            l++;
        }
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;

    cin >> n >> m;
    Obwarzanek obwarzanki[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> obwarzanki[i].srednica_w >> obwarzanki[i].srednica_z;
    }
    cout << min(zdejmij_lewo(m,obwarzanki,n),zdejmij_prawo(m,obwarzanki,n));
    return 0;
}