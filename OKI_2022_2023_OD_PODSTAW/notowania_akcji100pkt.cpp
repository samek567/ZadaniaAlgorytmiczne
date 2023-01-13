#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, k_i = 0, wczytana_liczba = 0, ile_pod_rzad = 1;
vector<int> akcje;
vector<int> stat;

int main()
{
    // O(n+q)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat.assign(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        akcje.push_back(wczytana_liczba);
    }

    for (int i = 1; i < n; ++i)
    {
        if (akcje[i] > akcje[i-1])
            ile_pod_rzad++;
        else
        {
            for (int j = 1; j <= ile_pod_rzad; ++j)
                stat[j] += ile_pod_rzad-j+1;
            ile_pod_rzad = 1;
        }
    }
    for (int i = 1; i <= ile_pod_rzad; ++i)
        stat[i] += ile_pod_rzad-i+1;
    ile_pod_rzad = 1;

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> k_i;
        printf("%d\n",stat[k_i]);
    }

    return 0;
}