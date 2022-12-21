#include <iostream>
#include <vector>

using namespace std;

int n = 0;
long long wczytana_liczba = 0, max_wyn = 0;
vector<long long> liczby;
vector<long long> prefix_max;
vector<long long> sufix_max;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    prefix_max.assign(n,0);
    sufix_max.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    prefix_max[1] = liczby[1];
    for (int i = 2; i < n; ++i)
        prefix_max[i] = max(prefix_max[i-1] + liczby[i], liczby[i]);

    sufix_max[n-2] = liczby[n-2];
    for (int i = n-3; i >= 0; --i)
        sufix_max[i] = max(sufix_max[i+1] + liczby[i], liczby[i]);

    for (int i = 1; i < n-1; ++i)
        max_wyn = max(max_wyn,prefix_max[i-1] + sufix_max[i+1]);

    printf("%lld",max_wyn);

    return 0;
}
