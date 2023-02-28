#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, a = 0, b = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<int> gwozdzie;
vector<pair<int,int>> deski;

inline bool czy_pasuje(int x)
{
    bool stat[1000001] = {false};
    int sumy_prefiksowe[1000001] = {0};
    for (int i = 0; i < x; ++i)
        stat[gwozdzie[i]] = true;
    int sum = 0;
    for (int i = 0; i <= 1e6; ++i)
    {
        if (stat[i] == true)
            sum++;
        sumy_prefiksowe[i] = sum;
    }
    for (int i = 0; i < n; ++i)
    {
        if (sumy_prefiksowe[deski[i].second] - sumy_prefiksowe[deski[i].first - 1] <= 0)
            return false;
    }
    return true;
}

int main()
{
    // O((N+M) * log M)
    // Binary search po wyniku + sumy prefiksowe. Binarnie szukamy najmniejsza liczbe gwozdzi, ktorymi da sie wbic, a dla sprawdzanych X pierwszych
    // gwozdzi sprawdzamy kazda deske sumami prefiksowymi, czy zostanie przybita przez pierwszych X gwozdzi.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        deski.push_back({a,b});
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        gwozdzie.push_back(wczytana_liczba);
    }

    poczatek = 0, koniec = m;
    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            koniec = srodek;
        else
            poczatek = srodek;
    }

    cout << koniec << '\n';

    return 0;
}