#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull n = 0, max_wyn_roznica = 1e9, ile = 0;
string ciag, sprawdzany, max_wyn;

bool sprawdzaj_mniejsza(int l, int p, char val)
{
    char lewy_przed = sprawdzany[l], prawy_przed = sprawdzany[p];
    sprawdzany[l] = val;
    sprawdzany[p] = val;
    if (stoull(sprawdzany) < stoull(ciag))
        return true;
    else
    {
        sprawdzany[l] = lewy_przed;
        sprawdzany[p] = prawy_przed;
        return false;
    }
}

bool czy_palindromniczna(string ciag)
{
    for (int i = 0; i < ile; ++i)
        if (ciag[i] != ciag[n-i-1])
            return false;
    return true;
}

int main()
{
    // O(log n), 100pkt.
    // Najpierw szukamy najwiekszej liczby palindromniczej, ktora jest < wczytana, potem najmniejszej liczby palindromniczej ktora jest > niz szukana.
    // Korzystamy z obserwacji, ze np jesli wczytana liczba to 53562, to liczby palindromnicze musza byc parami - i, n-i-1 to szukamy jak najwiekszej
    // liczby, zeby byly same zera w srodku i to co mamy juz ustawione, bo jak chcemy miec jak najwieksza liczba, to chcemy na pierwszych pozycjach miec
    // jak najwieksze.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    n = ciag.size();
    if (n % 2 == 0)
        ile = n / 2;
    else
        ile = n / 2 + 1;
    for (int i = 0; i < n; ++i)
        sprawdzany.push_back('0');

    if (czy_palindromniczna(ciag) == true)
    {
        cout << ciag;
        return 0;
    }

    // Mniejsza
    if (sprawdzaj_mniejsza(0,n-1,'1') == false)
    {
        for (int i = 0; i < n-1; ++i)
            sprawdzany[i] = '9';
        sprawdzany.pop_back();
        if (stoull(ciag) - stoull(sprawdzany) < max_wyn_roznica)
        {
            max_wyn_roznica = stoull(ciag) - stoull(sprawdzany);
            max_wyn = sprawdzany;
        }
    }
    else
    {
        for (int i = 0; i < ile; ++i)
        {
            for (char j = '9'; j >= '1'; --j)
            {
                if (sprawdzaj_mniejsza(i,n-i-1,j) == true)
                {
                    break;
                }
            }
        }
        if (stoull(ciag) - stoull(sprawdzany) < max_wyn_roznica)
        {
            max_wyn_roznica = stoull(ciag) - stoull(sprawdzany);
            max_wyn = sprawdzany;
        }
    }

    // Wieksza
    sprawdzany.clear();
    for (int i = 0; i < n; ++i)
        sprawdzany.push_back('0');
    sprawdzany[0] = '1';
    sprawdzany.push_back('1');
    if (stoull(sprawdzany) - stoull(ciag) < max_wyn_roznica)
    {
        max_wyn_roznica = stoull(sprawdzany) - stoull(ciag);
        max_wyn = sprawdzany;
    }

    sprawdzany.clear();
    for (int i = 0; i < n; ++i)
        sprawdzany.push_back('0');

    for (int i = 0; i < ile; ++i)
    {
        for (char j = '1'; j <= '9'; ++j)
        {
            if (j >= ciag[i])
            {
                if (j != '9')
                {
                    char zap_l = sprawdzany[i], zap_p = sprawdzany[n-i-1];
                    sprawdzany[i] = char(j + 1);
                    sprawdzany[n-i-1] = char(j + 1);
                    if (stoull(sprawdzany) - stoull(ciag) < max_wyn_roznica)
                    {
                        max_wyn_roznica = stoull(sprawdzany) - stoull(ciag);
                        max_wyn = sprawdzany;
                    }
                    sprawdzany[i] = zap_l;
                    sprawdzany[n-i-1] = zap_p;
                }
                sprawdzany[i] = j;
                sprawdzany[n-i-1] = j;
                if (stoull(sprawdzany) > stoull(ciag))
                {
                    if (stoull(sprawdzany) - stoull(ciag) < max_wyn_roznica)
                    {
                        max_wyn_roznica = stoull(sprawdzany) - stoull(ciag);
                        max_wyn = sprawdzany;
                    }
                    cout << max_wyn;
                    return 0;
                }
                break;
            }
        }
    }

    cout << max_wyn;

    return 0;
}