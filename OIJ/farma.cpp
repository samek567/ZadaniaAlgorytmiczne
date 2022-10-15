#include <iostream>

using namespace std;

long long liczba_glow = 0, liczba_nog = 0, liczba_kur = 0, liczba_krow = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> liczba_glow >> liczba_nog;

    liczba_krow = (liczba_nog - (2 * liczba_glow)) / 2;
    liczba_kur = (liczba_nog - (4*liczba_krow)) / 2;
    cout << liczba_kur << " " << liczba_krow;
    return 0;
}