#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int wartosc;
    int ile_elementow;
};

int n = 0, k = 0, wczytana_liczba = 0, ile_pod_rzad = 1, ile_na_lewo = 0, max_wyn = 0;
vector<int> liczby;
vector<Element> elementy;

int main()
{
    // O(n log n) Sortowanie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    sort(liczby.begin(),liczby.end(),greater<int>());

    for (int i = 1; i < n; ++i)
    {
        if (liczby[i] == liczby[i-1])
            ile_pod_rzad++;
        else
        {
            elementy.push_back({liczby[i-1],ile_pod_rzad});
            ile_pod_rzad = 1;
        }
    }
    elementy.push_back({liczby[n-1],ile_pod_rzad});

    for (int i = 0; i < elementy.size(); ++i)
    {
        max_wyn = max(max_wyn,elementy[i].ile_elementow + min(ile_na_lewo,k));
        ile_na_lewo += elementy[i].ile_elementow;
    }

    printf("%d",max_wyn);

    return 0;
}
