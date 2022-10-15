#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Ciezarowka
{
    long double x;
    long long v;

    bool operator < (const Ciezarowka&ciezarowka) const
    {
        return v < ciezarowka.v;
    }

    long double czasDo(const Ciezarowka& n) const
    {
        if (n.x > x)
        {
            return abs(((long double)(n.x - x))/(long double)(v - n.v));
        }
        else if(x > n.x)
        {
            return abs(((long double)(x - n.x))/(long double)(v + n.v));
        }
        else
        {
            return (long double)0;
        }
    }

    long double czasDo(const long long b) const
    {
        return abs(((x - (long double)b))/(long double)(v));
    }

    void jedziemy(const Ciezarowka& n, long double t)
    {
        //cout << "jedziemy: " << n.v << endl;
        if (n.x > x)
        {
            x += (long double)v * t;
        }
        else if(x > n.x)
        {
            x -= (long double)v * t;
        }
        else//nesseser jedzie zawsze w prawo
        {
            x += (long double)v * t;
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    long long x_a = 0;
    long long x_b = 0;
    long long x_alinogrod = 0;
    long long x_bajtogrod = 0;
    long long wczytane_v = 0;
    long long wczytane_x = 0;
    vector<Ciezarowka> ciezarowki;

    cin >> n >> x_a >> x_b;

    if (x_b > x_a)
    {
        x_alinogrod = 0;
        x_bajtogrod = x_b - x_a;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytane_x >> wczytane_v;
            ciezarowki.push_back({wczytane_x-x_a,wczytane_v});
        }
        ciezarowki.push_back({x_alinogrod,0});
    }
    else
    {
        x_alinogrod = 0;
        x_bajtogrod = x_a - x_b;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytane_x >> wczytane_v;
            ciezarowki.push_back({-(wczytane_x-x_a),wczytane_v});
        }
        ciezarowki.push_back({x_alinogrod,0});
    }

    sort(ciezarowki.begin(), ciezarowki.end());
    int wskaznik_nesseser = 0;
    n++;

    long double czas = (long double)0;

    while (true)
    {
        //cout << "wskaznik nesseser: " << wskaznik_nesseser << endl;
        Ciezarowka nesseser = ciezarowki[wskaznik_nesseser];
        long double tn = nesseser.czasDo(x_bajtogrod);
        if (n - 1 > wskaznik_nesseser)
        {
            long double czas_min = (long double)10000000000000;
            int wskaznik_min;
            for (int i=wskaznik_nesseser + 1; i<n; ++i)
            {
                long double tc = ciezarowki[i].czasDo(nesseser);
                if (tc < czas_min)
                {
                    czas_min = tc;
                    wskaznik_min = i;
                }
            }
            //
            if (czas_min >= tn)
            {
                czas += tn;
                break;
            }
            else
            {
                //jedziemy
                for (int i=wskaznik_nesseser; i<n; ++i)
                {
                    ciezarowki[i].jedziemy(nesseser, czas_min);
                }
                czas += czas_min;
                //przekazanie nessesera
                wskaznik_nesseser = wskaznik_min;
            }
        }
        else
        {
            czas += tn;
            break;
        }
    }

    cout << fixed << setprecision(9) << czas;

    return 0;
}