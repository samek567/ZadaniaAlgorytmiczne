#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;

int odtwarzaj(bool czy_gora_wzgledem_rodzica)
{
    int wyn = 0;
    for (int i = 1; i < n; ++i)
    {
        bool czy_update = false;
        if (czy_gora_wzgledem_rodzica == true)
        {
            if (!(liczby[i] > liczby[i-1])) // Nie jest wieksze
            {
                wyn++;
                czy_update = true;
            }
        }
        else
        {
            if (!(liczby[i] < liczby[i-1])) // Nie jest mniejsze
            {
                wyn++;
                czy_update = true;
            }
        }
        if (czy_update == true)
            i++;
        if (czy_update == false)
            czy_gora_wzgledem_rodzica = !czy_gora_wzgledem_rodzica;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    printf("%d",min(odtwarzaj(true), odtwarzaj(false)));

    return 0;
}