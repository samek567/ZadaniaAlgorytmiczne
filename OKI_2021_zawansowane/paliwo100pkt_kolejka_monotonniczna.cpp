#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Stacja
{
    int cena;
    int odleglosc;
};

struct Element
{
    int wartosc;
    int ile;
};

int p = 0, n = 0, c = 0, d = 0, ile_mamy = 0, wyn = 0;
vector<Stacja> stacje;
deque<Element> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c >> d;
        stacje.push_back({c,d});
    }

    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            int ile_zostalo_do_oddania = stacje[i-1].odleglosc;
            while(ile_zostalo_do_oddania > 0)
            {
                if (ile_zostalo_do_oddania == Q.front().ile)
                {
                    wyn += ile_zostalo_do_oddania * Q.front().wartosc;
                    ile_mamy -= ile_zostalo_do_oddania;
                    Q.pop_front();
                    break;
                }
                else if (Q.front().ile > ile_zostalo_do_oddania)
                {
                    wyn += ile_zostalo_do_oddania * Q.front().wartosc;
                    ile_mamy -= ile_zostalo_do_oddania;
                    Q.front().ile -= ile_zostalo_do_oddania;
                    break;
                }
                wyn += Q.front().ile * Q.front().wartosc;
                ile_zostalo_do_oddania -= Q.front().ile;
                ile_mamy -= Q.front().ile;
                Q.pop_front();
            }
        }
        while(!Q.empty())
        {
            if (Q.back().wartosc >= stacje[i].cena)
            {
                ile_mamy -= Q.back().ile;
                Q.pop_back();
            }
            else
                break;
        }
        Q.push_back({stacje[i].cena, p - ile_mamy});
        ile_mamy = p;
    }

    int ile_zostalo_do_oddania = stacje[n-1].odleglosc;
    while(ile_zostalo_do_oddania > 0)
    {
        if (ile_zostalo_do_oddania == Q.front().ile)
        {
            wyn += ile_zostalo_do_oddania * Q.front().wartosc;
            Q.pop_front();
            break;
        }
        else if (Q.front().ile > ile_zostalo_do_oddania)
        {
            wyn += ile_zostalo_do_oddania * Q.front().wartosc;
            break;
        }
        wyn += Q.front().ile * Q.front().wartosc;
        ile_zostalo_do_oddania -= Q.front().ile;
        Q.pop_front();
    }

    cout << wyn << '\n';

    return 0;
}