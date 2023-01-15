#include <iostream>
#include <vector>

using namespace std;

int n = 0, p = 0, wczytana_liczba = 0, wyn = 0;
vector<int> reszty;
vector<int> liczby;

int main()
{
    // O(n) jesli dwie liczby daja taka sama reszte z dzielenie przez p, to zawsze stworza pare przegrywajaca dla Antka.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    reszty.assign(p,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        reszty[wczytana_liczba % p]++;
    }
    for (int i = 0; i < n; ++i)
        if (reszty[liczby[i] % p] == 1)
            wyn++;
    printf("%d",wyn);
    
    return 0;
}
