#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long aktualna_liczba = 0;
    long long wartosc = 0;
    vector<long long> miasta;
    vector<long long> koszty_drogi;
    long long amax = 0;
    long long amin = 0;
    long long azysk = 0;
    long long max_zysk = 0;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        miasta.push_back(aktualna_liczba);
    }

    for (long long i = 0; i < n-1; i++)
    {
        cin >> aktualna_liczba;
        koszty_drogi.push_back(aktualna_liczba);
    }

    wartosc = miasta[0];
    amin = miasta[0];
    amax = miasta[0];
    for (long long i = 0; i < n-1; i++)
    {
        wartosc += miasta[i+1] - miasta[i] - koszty_drogi[i];
        if (wartosc > amax)
        {
            amax = wartosc;
            azysk = amax - amin;
            if (azysk > max_zysk)
            {
                max_zysk = azysk;
            }
        }
        if (wartosc < amin)
        {
            amin = wartosc;
            amax = wartosc;
        }
    }

    //cout << endl;
    wartosc = miasta[n-1];
    amin = miasta[n-1];
    amax = miasta[n-1];
    for (long long i = n-1; i > 0; i--)
    {
        wartosc += miasta[i-1] - miasta[i] - koszty_drogi[i-1];
        //cout << "wartosc: " << wartosc << endl;
        if (wartosc > amax)
        {
            amax = wartosc;
            azysk = amax - amin;
            //cout << "zysk: " << azysk << " max: " << amax << " min: " << amin << endl;
            if (azysk > max_zysk)
            {
                max_zysk = azysk;
            }
        }
        if (wartosc < amin)
        {
            amin = wartosc;
            amax = wartosc;
        }
    }

    cout << max_zysk;

    return 0;
}