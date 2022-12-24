#include <iostream>
#include <stack>

using namespace std;

struct Element
{
    long long wysokosc;
    long long ile_elementow;
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        long long n = 0, wczytana_liczba = 0, wyn = 0;
        stack<Element> S;

        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; ++i)
        {
            cin >> wczytana_liczba;

            if (S.empty())
                S.push({wczytana_liczba,1});
            else if (S.top().wysokosc == wczytana_liczba)
                S.top().ile_elementow++;
            else if (wczytana_liczba > S.top().wysokosc)
                S.push({wczytana_liczba,1});
            else
            {
                long long ile_szerokosc = 0;
                while (!S.empty())
                {
                    if (wczytana_liczba > S.top().wysokosc)
                        break;
                    ile_szerokosc += S.top().ile_elementow;
                    wyn = max(wyn,S.top().wysokosc * ile_szerokosc);
                    S.pop();
                }
                if (wczytana_liczba != 0)
                    S.push({wczytana_liczba,ile_szerokosc+1});
            }
        }
        long long ile_szerokosc = 0;
        while (!S.empty())
        {
            ile_szerokosc += S.top().ile_elementow;
            wyn = max(wyn,S.top().wysokosc * ile_szerokosc);
            S.pop();
        }

        printf("%lld\n",wyn);
    }

    return 0;
}
