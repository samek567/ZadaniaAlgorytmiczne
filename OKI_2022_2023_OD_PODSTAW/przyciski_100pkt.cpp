#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, wyn_akt = 0, wyn = 0;
vector<int> przyciski;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    przyciski.assign(n,0);
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        wczytana_liczba--;
        if (wczytana_liczba == n)
            wyn = wyn_akt;
        else
        {
            if (przyciski[wczytana_liczba] < wyn)
                przyciski[wczytana_liczba] = wyn;
            przyciski[wczytana_liczba]++;
            wyn_akt = max(wyn_akt,przyciski[wczytana_liczba]);
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d ",max(przyciski[i],wyn));
    return 0;
}
