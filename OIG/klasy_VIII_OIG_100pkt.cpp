#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wyn = 0;
string ciag;
vector<int> idxy;
vector<int> stat;
vector<int> idx_poprzedniej;

inline int ile_pasuje(int x)
{
    int wynn = 0;
    for (int i = 0; i < idxy.size(); ++i)
    {
        if (idx_poprzedniej[idxy[i]%x] != x)
        {
            idx_poprzedniej[idxy[i]%x] = x;
            stat[idxy[i]%x] = 1;
        }
        else
            stat[idxy[i]%x]++;
        wynn = max(wynn, stat[idxy[i]%x]);
    }
    return wynn;
}

int main()
{
    // O(N)
    // Super wątek: https://forum.pasja-informatyki.pl/580454/zadanie-klasy-final-oig?show=581562#c581562
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    stat.assign(n,0);
    idx_poprzedniej.assign(n,-1);
    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == '#')
        {
            k++;
            idxy.push_back(i);
        }
    }

    for (int i = 2; i <= 2*n/k; ++i)
        wyn = max(wyn, ile_pasuje(i));

    cout << wyn << '\n';

    return 0;
}
