#include <iostream>
#include <vector>

using namespace std;

long long n = 0, wczytana_liczba = 0, wyn = -1e15, max_odl = -1e15;
vector<long long> miasta;
vector<long long> odleglosci;

int main()
{
    // O(n) Programowanie dynamiczne. Podobne jak w zadaniu tory kolejowe.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        miasta.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n-1; ++i)
    {
        cin >> wczytana_liczba;
        odleglosci.push_back(wczytana_liczba);
    }

    for (int i = 1; i < n; ++i)
    {
        max_odl = max(max_odl - odleglosci[i-1], miasta[i-1] - odleglosci[i-1]);
        wyn = max(wyn,max_odl - miasta[i]);
    }

    max_odl = -1e15;
    for (int i = n - 2; i >= 0; --i)
    {
        max_odl = max(max_odl - odleglosci[i], miasta[i+1] - odleglosci[i]);
        wyn = max(wyn,max_odl - miasta[i]);
    }

    printf("%lld",max((long long)0,wyn));

    return 0;
}