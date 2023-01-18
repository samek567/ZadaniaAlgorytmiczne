#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, INF = 1e9+15, k = 316, wczytana_liczba = 0, decyzja = 0, a_i = 0, b_i = 0, ile_skokow = 0, numer = 0;
vector<int> wartosci;
vector<int> ile_skokow_do_kolejnego;
vector<int> numer_kolejnego;

int main()
{
    // O(q * sqrt(n))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ile_skokow_do_kolejnego.assign(n,-1);
    numer_kolejnego.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wartosci.push_back(wczytana_liczba);
    }
    numer_kolejnego[n-1] = INF;
    ile_skokow_do_kolejnego[n-1] = 1;
    for (int i = n-2; i >= 0; --i)
    {
        if (i + wartosci[i] > n-1)
        {
            numer_kolejnego[i] = INF;
            ile_skokow_do_kolejnego[i] = 1;
        }
        else if (i / k != (i + wartosci[i]) / k)
        {
            numer_kolejnego[i] = i + wartosci[i];
            ile_skokow_do_kolejnego[i] = 1;
        }
        else
        {
            numer_kolejnego[i] = numer_kolejnego[i+wartosci[i]];
            ile_skokow_do_kolejnego[i] = ile_skokow_do_kolejnego[i+wartosci[i]] + 1;
        }
    }
    while(m--)
    {
        cin >> decyzja;
        if (decyzja == 1)
        {
            cin >> a_i;
            a_i--;
            ile_skokow = 1;
            numer = a_i;
            while(true)
            {
                if (numer_kolejnego[numer] == INF)
                    break;
                ile_skokow += ile_skokow_do_kolejnego[numer];
                numer = numer_kolejnego[numer];
            }
            while (true)
            {
                if (numer + wartosci[numer] >= n)
                    break;
                ile_skokow++;
                numer = numer + wartosci[numer];
            }
            printf("%d %d\n",numer+1,ile_skokow);
        }
        else
        {
            cin >> a_i >> b_i;
            a_i--;
            wartosci[a_i] = b_i;
            // Idziemy po przedziale z tym samym pierwiastkiem i aktualizujemy dla nich wartosci.
            for (int i = a_i; a_i / k == i / k && i >= 0; --i)
            {
                if (i + wartosci[i] >= n)
                {
                    numer_kolejnego[i] = INF;
                    ile_skokow_do_kolejnego[i] = 1;
                }
                else if (i / k != (i + wartosci[i]) / k)
                {
                    numer_kolejnego[i] = i + wartosci[i];
                    ile_skokow_do_kolejnego[i] = 1;
                }
                else
                {
                    numer_kolejnego[i] = numer_kolejnego[i+wartosci[i]];
                    ile_skokow_do_kolejnego[i] = ile_skokow_do_kolejnego[i+wartosci[i]] + 1;
                }
            }
        }
    }
    return 0;
}
