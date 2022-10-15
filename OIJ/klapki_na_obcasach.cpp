#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    long long min_wzrost = 0;
    long long aktualna_liczba = 0;
    long long licznik = 0;
    long long sprawdzany_klapek = 0;
    vector<long long> wzrost_osob;
    vector<long long> klapki;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        wzrost_osob.push_back(aktualna_liczba);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> aktualna_liczba;
        klapki.push_back(aktualna_liczba);
    }

    cin >> min_wzrost;

    sort(wzrost_osob.begin(),wzrost_osob.end(),greater<long long>());
    sort(klapki.begin(),klapki.end());

    for (int i = 0 ; i < n; i++)
    {
        if (wzrost_osob[i] >= min_wzrost)
        {
            licznik++;
        }
        else
        {
            for (int j = sprawdzany_klapek; j < m; j++)
            {
                if (klapki[j] + wzrost_osob[i] >= min_wzrost)
                {
                    licznik++;
                    sprawdzany_klapek++;
                    break;
                }
                sprawdzany_klapek++;
            }
        }
    }

    printf("%lld",licznik);

    return 0;
}