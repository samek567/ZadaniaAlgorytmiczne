#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, max_liczba = 0, wyn = 0, lewy_wsk = -1, prawy_wsk = -1;
vector<int> liczby;

int main()
{
    // Gasienica od srodka.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] == 1)
        {
            lewy_wsk = i;
            prawy_wsk = i;
            max_liczba = 1;
            break;
        }
    }

    while (true)
    {
        if (max_liczba == prawy_wsk - lewy_wsk + 1)
            wyn++;
        if (lewy_wsk == 0 && prawy_wsk == n-1)
            break;
        else if (lewy_wsk == 0)
        {
            prawy_wsk++;
            max_liczba = max(max_liczba,liczby[prawy_wsk]);
        }
        else if (prawy_wsk == n-1)
        {
            lewy_wsk--;
            max_liczba = max(max_liczba,liczby[lewy_wsk]);
        }
        else
        {
            if (liczby[lewy_wsk-1] < liczby[prawy_wsk+1])
            {
                lewy_wsk--;
                max_liczba = max(max_liczba,liczby[lewy_wsk]);
            }
            else if (liczby[prawy_wsk+1] < liczby[lewy_wsk-1])
            {
                prawy_wsk++;
                max_liczba = max(max_liczba,liczby[prawy_wsk]);
            }
        }
    }
    printf("%d",wyn);

    return 0;
}