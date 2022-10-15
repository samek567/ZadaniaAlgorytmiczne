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
    int aktualna_liczba = 0;
    int aktualny_idx = 2;
    int licznik = 3;
    int max_licznik = 0;
    vector<int> liczby;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        liczby.push_back(aktualna_liczba);
    }

    sort(liczby.begin(),liczby.end(),greater<int>());

    for (int i = 0; i < n; i++)
    {
        licznik = licznik - 1;
        for(int j = aktualny_idx; j < n; j++)
        {
            if (liczby[j] + liczby[j-1] > liczby[i])
            {
                licznik++;
                aktualny_idx = j + 1;
            }
            else
            {
                break;
            }
        }
        if (licznik > max_licznik)
        {
            max_licznik = licznik;
        }
        //cout << "I: " << i << " Licznik to: " << licznik << endl;
    }

    cout << max_licznik;

    return 0;
}