#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int m = 0;
    long long wczytana_liczba = 0;
    stack<long long> wieza_1;
    stack<long long> wieza_2;
    long long suma_1 = 0;
    long long suma_2 = 0;
    long long licznik = 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wieza_1.push(wczytana_liczba);
        suma_1 += wczytana_liczba;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        wieza_2.push(wczytana_liczba);
        suma_2 += wczytana_liczba;
    }

    while (suma_1 != suma_2)
    {
        if (suma_1 > suma_2)
        {
            suma_1 -= wieza_1.top();
            wieza_1.pop();
        }
        else
        {
            suma_2 -= wieza_2.top();
            wieza_2.pop();
        }
        licznik++;
    }

    cout << licznik;
    return 0;
}