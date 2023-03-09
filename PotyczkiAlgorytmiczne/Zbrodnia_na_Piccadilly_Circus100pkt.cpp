#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int n = 0, a = 0, b = 0, min_wyn = 1e9, max_wyn = 0, bilans = 0, p = 0, k = 0, ostatnie_rozne_x = -1;
unordered_map<int,int> otwarte;
unordered_map<int,int> zamkniete;
set<int> S;

int main()
{
    // O(N lg N)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> k >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (auto it = otwarte.find(a) != otwarte.end())
            otwarte[a]++;
        else
            otwarte.insert({a,1});
        if (auto it = zamkniete.find(b) != zamkniete.end())
            zamkniete[b]++;
        else
            zamkniete.insert({b,1});
        S.insert(a), S.insert(b);
    }

    for (auto it = S.begin(); it != S.end(); ++it)
    {
        int ile_otwartych = 0, ile_zamknietych = 0, x = *it;

        if (auto it2 = otwarte.find(x) != otwarte.end())
            ile_otwartych = otwarte[x];
        if (auto it2 = zamkniete.find(x) != zamkniete.end())
            ile_zamknietych = zamkniete[x];

        if(auto it2 = S.find(x-1) == S.end())
        {
            if (x-1 >= p and x-1 <= k)
            {
                min_wyn = min(min_wyn, bilans);
                max_wyn = max(max_wyn, bilans);
            }
            if (ostatnie_rozne_x != -1)
            {
                if (ostatnie_rozne_x < k and x-1 > p)
                {
                    min_wyn = min(min_wyn, bilans);
                    max_wyn = max(max_wyn, bilans);
                }
            }
        }
        bilans += ile_otwartych;
        if (x >= p and x <= k)
        {
            min_wyn = min(min_wyn, bilans);
            max_wyn = max(max_wyn, bilans);
        }
        bilans -= ile_zamknietych;
        if (x+1 >= p and x+1 <= k)
        {
            min_wyn = min(min_wyn, bilans);
            max_wyn = max(max_wyn, bilans);
        }
        ostatnie_rozne_x = x;
    }

    cout << min_wyn << ' ' << max_wyn << '\n';

    return 0;
}
