#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, wyn = 1;
bool czy_rosnacy = true;
vector<int> liczby;

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
    for (int i = 1; i < n; ++i)
    {
        if (czy_rosnacy == true)
        {
            if (liczby[i] < liczby[i-1])
            {
                wyn++;
                czy_rosnacy = false;
            }
        }
        else
        {
            if (liczby[i] > liczby[i-1])
            {
                wyn++;
                czy_rosnacy = true;
            }
        }
    }
    printf("%d",wyn);

    return 0;
}
