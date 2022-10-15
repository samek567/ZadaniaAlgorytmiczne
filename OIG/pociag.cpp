#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    int aktualna_wartosc = 0;
    int aktualny_idx_sprawdzany = 0;
    int licznik = 0;

    vector<int> miasta;
    int* indeksy = new int[1000001];
    vector<int> wagony_pociagu;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_wartosc;
        wagony_pociagu.push_back(aktualna_wartosc);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_wartosc;
        miasta.push_back(aktualna_wartosc);
    }

    for (int i = 0; i < n; i++)
    {
        indeksy[miasta[i]] = i;
    }

    int indeks;
    int wczesniejszy_indeks = INT_MAX;

    for (int i = wagony_pociagu.size() - 1; i>-1; i--)
    {
        int wagon = wagony_pociagu[i];
        indeks = indeksy[wagon];
        // cout << "indeks: " << indeks << " wczesniejszy: " << wczesniejszy_indeks << endl;
        if (indeks < wczesniejszy_indeks)
        {
            licznik++;
        }
        wczesniejszy_indeks = indeks;
    }

    if (indeks == 0)
        licznik--;

    cout << licznik;

    delete [] indeksy;
    return 0;
}