#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Przedzial
{
    int poczatek;
    int koniec;
    int cena;
};

int szerokosc = 0, n = 0, c = 0;
ll wyn = 0, sum = 0;
vector<Przedzial> przedzialy;
vector<int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> szerokosc >> n >> c;

    stat.assign(szerokosc+1,0);
    przedzialy.assign(n, {-1,-1,-1});
    for (int i = 0; i < n; ++i)
        cin >> przedzialy[i].poczatek >> przedzialy[i].koniec >> przedzialy[i].cena;

    for (int i = 1; i <= szerokosc; ++i)
    {
        fill(stat.begin(), stat.end(), 0);
        for (int j = 0; j < n; ++j)
        {
            if (przedzialy[j].koniec < i)
                continue;
            else if (przedzialy[j].poczatek >= i)
                stat[przedzialy[j].poczatek] += przedzialy[j].cena;
            else
                stat[i] += przedzialy[j].cena;
        }
        sum = 0;
        for (int j = i; j <= szerokosc; ++j)
        {
            sum += stat[j];
            wyn = max(wyn, (ll)(j-i+1) * (ll)c - sum);
        }
    }

    cout << wyn << '\n';

    return 0;
}