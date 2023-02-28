#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0;
vector<int> krawedzie;

int main()
{
    // Zlozonnosc czasowa, to O(N*K), a pamieciowa O(N), bez przespieszenia pamieciowego,
    // w zlozonnosci czasowej i pamieciowej O(N*K), wchodzi na 87pkt.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        krawedzie.push_back(wczytana_liczba);
    }

    vector<int> dp_poprzednie;
    vector<int> dp_akt;

    for (int i = 0; i < n; ++i)
    {
        dp_akt.push_back(i);
        dp_poprzednie.push_back(i);
    }

    for (int i = 1; i <= k; ++i) // pelta po k.
    {
        for (int j = 0; j < n; ++j)
            if (krawedzie[j] != -1)
                dp_akt[krawedzie[j]] = min(dp_akt[krawedzie[j]], dp_poprzednie[j] + 1);
        for (int j = 1; j < n; ++j)
            dp_akt[j] = min(dp_akt[j], dp_akt[j-1] + 1);
        dp_poprzednie = dp_akt;
    }

    cout << dp_akt[n-1] << '\n';

    return 0;
}