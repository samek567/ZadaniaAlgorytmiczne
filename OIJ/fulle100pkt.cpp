#include <iostream>
#include <unordered_map>

using namespace std;

string ciag;
int ile_dwojek = 0, ile_trojek = 0, ile_czworek = 0, wyn = 0, dwojki_spr = 0, trojki_spr = 0;
unordered_map<char,int> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (auto it = stat.find(ciag[i]) != stat.end())
            stat[ciag[i]]++;
        else
            stat.insert({ciag[i],1});
    }

    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        if (it->second == 2)
            ile_dwojek++;
        else if (it->second == 3)
            ile_trojek++;
        else if (it->second == 4)
            ile_czworek++;
    }

    for (int i = 0; i <= ile_czworek; ++i)
    {
        dwojki_spr = ile_dwojek + i*2;
        trojki_spr = ile_trojek + (ile_czworek - i);
        if (dwojki_spr == trojki_spr)
            wyn = max(wyn, dwojki_spr);
        else if (dwojki_spr > trojki_spr)
            wyn = max(wyn, trojki_spr);
        else
        {
            int ile_roznicy = (trojki_spr - dwojki_spr) / 2;
            wyn = max(wyn, dwojki_spr + ile_roznicy);
        }
    }

    cout << wyn << '\n';

    return 0;
}