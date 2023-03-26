#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int k = 0, n = 0, wczytana_liczba = 0, poprzednia_wartosc = 0;
vector<int> liczby;
vector<bool> czy_pasuje_sufix;

inline bool czy_pasuje()
{
    cin >> n;
    liczby.assign(n,-1);
    czy_pasuje_sufix.assign(n,false);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];
    for (int i = n-1; i >= 0; --i)
    {
        if (liczby[i] < (n-i-1))
            break;
        czy_pasuje_sufix[i] = true;
    }
    for (int i = 0; i < n-1; ++i)
    {
        if (liczby[i] < i)
            return false;
        if (czy_pasuje_sufix[i+1] == true and liczby[i] >= n-i-1)
            return true;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    while(k--)
    {
        if (czy_pasuje() == true)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}