#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#include <chrono>

using namespace std;

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n = 0;
    int licznik = 0;
    vector<long long> liczby;
    long long aktualna_liczba = 0;

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        liczby.push_back(aktualna_liczba);
    }

    sort(liczby.begin(), liczby.end());

    liczby[0] = liczby[0]-1;
    licznik++;

    for (int i = 1; i < n; i++)
    {
        if (liczby[i] - 1 > liczby[i-1])
        {
            liczby[i] = liczby[i] - 1;
        }
        else if (liczby[i] - 1 < liczby[i-1])
        {
            liczby[i] = liczby[i] + 1;
        }
        //
        if (liczby[i] > liczby[i-1])
        {
            licznik++;
        }
    }

    cout << licznik;

    return 0;
}