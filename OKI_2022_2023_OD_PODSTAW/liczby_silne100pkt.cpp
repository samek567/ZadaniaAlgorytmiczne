#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int q = 0, n = 0, poczatek = 0, koniec = 0, srodek = 0, idx_lewo = 0, idx_prawo = 0;
ll iloczyn = 1, a = 0, b = 0;
vector<ll> silnie;
vector<ll> liczby_silne;
vector<ll> sumy_prefiksowe;

int main()
{
    // O(2^16 + Q * lg(2^16)), maski bitowe, binary search, sumy prefiksowe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n = 16;
    for (ll i = 1; i <= n; ++i)
    {
        silnie.push_back(iloczyn);
        iloczyn *= (i+(ll)1);
    }

    for (int i = 1; i < (1 << n); ++i)
    {
        ll sum = 0;
        for (int j = 0; j < n; ++j)
        {
            auto b = (1 << j) & i;
            if (b)
                sum += silnie[j];
        }
        liczby_silne.push_back(sum);
    }
    sort(liczby_silne.begin(), liczby_silne.end());

    ll sum = 0;
    for (int i = 0; i < liczby_silne.size(); ++i)
    {
        sum += liczby_silne[i];
        sumy_prefiksowe.push_back(sum);
    }

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        poczatek = -1, koniec = liczby_silne.size();
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (liczby_silne[srodek] >= a)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec == liczby_silne.size() or liczby_silne[koniec] > 1e13)
        {
            cout << "0" << '\n';
            continue;
        }
        idx_lewo = koniec;
        poczatek = -1, koniec = liczby_silne.size();
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (liczby_silne[srodek] <= b)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (poczatek == -1 or liczby_silne[poczatek] < a)
            cout << "0" << '\n';
        else
        {
            if (idx_lewo == 0)
                cout << sumy_prefiksowe[poczatek] << '\n';
            else
                cout << sumy_prefiksowe[poczatek] - sumy_prefiksowe[idx_lewo - 1] << '\n';
        }
    }

    return 0;
}