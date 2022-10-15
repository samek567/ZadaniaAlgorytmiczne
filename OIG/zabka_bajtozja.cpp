#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct kamien
{
    double x;
    double y;
    bool sprawdzony;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long liczba_kamieni = 0;
    long long idx_kamien_siedzacy = 0;
    long long max_skok = 0;
    double wspolrzedne_x = 0;
    double wspolrzedne_y = 0;
    double max_wynik = 0;
    vector<kamien> kamienie;
    vector<double> odleglosc_od_miejsca_poczatkowego;
    queue<long long> droga;

    cin >> liczba_kamieni >> idx_kamien_siedzacy >> max_skok;

    droga.push(idx_kamien_siedzacy - 1);

    for (long long i = 0; i < liczba_kamieni; i++)
    {
        cin >> wspolrzedne_x >> wspolrzedne_y;
        kamienie.push_back({wspolrzedne_x,wspolrzedne_y,false});
    }

    while (!droga.empty())
    {
        for (long long i = 0; i < liczba_kamieni; i++)
        {
            // Sprawdzamy kamienie czy mozna skoczyc Pitagorasem
            if (!kamienie[i].sprawdzony)
            {
                // tu liczymy odlegosc

                //if (sqrt(((kamienie[i].x - kamienie[droga.front()].x) * (kamienie[i].x - kamienie[droga.front()].x)) + ((kamienie[i].y - kamienie[droga.front()].y) * (kamienie[i].y - kamienie[droga.front()].y))) <= max_skok)
                double przyrost = sqrt(( pow(kamienie[i].x - kamienie[droga.front()].x, 2)) + pow(kamienie[i].y - kamienie[droga.front()].y, 2));
                if (przyrost <= max_skok)
                {
                    kamienie[i].sprawdzony = true;
                    //cout << "Wynik to: " << wynik << endl;
                    droga.push(i);
                    //
                    double odleglosc = sqrt(( pow(kamienie[i].x - kamienie[idx_kamien_siedzacy-1].x, 2)) + pow(kamienie[i].y - kamienie[idx_kamien_siedzacy-1].y, 2));
                    if (odleglosc > max_wynik)
                    {
                        max_wynik = odleglosc;
                    }
                }
            }
        }
        droga.pop();
    }

    /*
    cout << "wypisuje tablice booli: " << endl;

    for (long long i = 0; i < liczba_kamieni; i++)
    {
        if (czy_kamien_sprawdzony[i] == true)
        {
            cout << "Da sie skoczyc.";
        }
        else
        {
            cout << "Nie da sie skoczyc.";
        }
    }
    */


    cout << fixed << setprecision(3) << max_wynik + max_skok;

    return 0;
}