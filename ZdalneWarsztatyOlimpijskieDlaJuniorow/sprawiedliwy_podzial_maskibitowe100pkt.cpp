#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int n = 0, wczytana_liczba = 0;
ll suma = 0, suma_sprawdzana = 0;

vector<int> liczby;

int main()
{
    // O(2^n) - maski bitowe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        suma += wczytana_liczba;
    }
    for (int i = 1; i < (1 << n); ++i)
    {
        suma_sprawdzana = 0;
        for (int j = 0; j < n; ++j)
        {
            auto b = (1 << j) & i;
            if (b)
                suma_sprawdzana += liczby[j];
        }
        if (suma_sprawdzana == suma - suma_sprawdzana)
        {
            printf("TAK");
            return 0;
        }
    }
    printf("NIE");
    return 0;
}