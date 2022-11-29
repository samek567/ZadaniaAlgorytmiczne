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
        return wartosc < patyczek.wartosc;
    }
};

int k = 0, n = 0, wczytany_patyczek = 0;
vector<Patyczek> patyczki;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;

    for (int i = 1; i <= k; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytany_patyczek;
            patyczki.push_back({wczytany_patyczek, i});
        }
    }

    sort(patyczki.begin(),patyczki.end());

    for (int i = 0; i < patyczki.size(); ++i)
    {
        for (int j = i+1; j < patyczki.size(); ++j)
        {
            for (int f = j + 1; f < patyczki.size(); ++f)
            {
                if (patyczki[i].wartosc + patyczki[j].wartosc > patyczki[f].wartosc && patyczki[i].kolor != patyczki[j].kolor && patyczki[i].kolor != patyczki[f].kolor && patyczki[j].kolor != patyczki[f].kolor)
                {
                    printf("%d %d %d %d %d %d",patyczki[i].kolor,patyczki[i].wartosc,patyczki[j].kolor,patyczki[j].wartosc,patyczki[f].kolor,patyczki[f].wartosc);
                    return 0;
                }
            }
        }
    }

    printf("NIE");

    return 0;
}