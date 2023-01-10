#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0, lewy_wsk = 0, prawy_wsk = 0, ile_jedynek = 0, wyn = 0, min_wyn = 0;
vector<int> segmenty;

int main()
{
    // O(n) gasienica. Stopniowo przesuwamy lewy wsk i prawy dorownujemy zeby przedzial pasowal.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        segmenty.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n; ++i)
    {
        if (segmenty[i] == 1)
            ile_jedynek++;
        else
            wyn++;
        if (ile_jedynek == k)
        {
            prawy_wsk = i;
            break;
        }
    }
    if (ile_jedynek < k)
    {
        printf("NIE");
        return 0;
    }
    min_wyn = wyn;
    while(true)
    {
        if (prawy_wsk == n-1 && segmenty[lewy_wsk] == 1)
            break;
        else if (prawy_wsk == lewy_wsk && prawy_wsk == n-1)
            break;
        if (segmenty[lewy_wsk] == 0)
            wyn--;
        else
            ile_jedynek--;
        while (ile_jedynek < k)
        {
            if (prawy_wsk == n-1)
                break;
            if (segmenty[prawy_wsk+1] == 1)
                ile_jedynek++;
            else
                wyn++;
            prawy_wsk++;
        }
        lewy_wsk++;
        if (ile_jedynek < k)
            break;
        min_wyn = min(min_wyn,wyn);
    }
    printf("%d",min_wyn);

    return 0;
}
