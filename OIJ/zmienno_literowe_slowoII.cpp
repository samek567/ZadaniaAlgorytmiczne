#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

string ciag;
int suma = 0, ile_minus = 97; // ile trzeba zeby przekonwertowac do ASCII
ll wyn = 0, wyn_ile = 0, ile_par = 0;
vector<vector<vector<bool>>> stat;
vector<vector<int>> sumy_prefiksowe;

int main()
{
    // O(26*26*n) - zakladamy, ze srodek napisu to ciag[i] i liczymy ile jest trojek o srodku w ciag[i]
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    for (int i = 0; i < 26; ++i)
    {
        stat.push_back({});
        for (int j = 0; j < 26; ++j)
        {
            stat[i].push_back({});
            for (int k = 0; k < 26; ++k)
                stat[i][j].push_back(false);
        }
    }
    for (char i = 'a'; i <= 'z'; ++i)
    {
        suma = 0;
        sumy_prefiksowe.push_back({});
        for (int j = 0; j < ciag.size(); ++j)
        {
            if (ciag[j] == i)
                suma++;
            sumy_prefiksowe[i-ile_minus].push_back(suma);
        }
    }
    for (int i = 1; i < ciag.size()-1; ++i)
    {
        for (char j = 'a'; j <= 'z'; ++j)
        {
            if (j == ciag[i])
                continue;
            for (char k = 'a'; k <= 'z'; ++k)
            {
                if (k == ciag[i])
                    continue;
                ile_par = sumy_prefiksowe[j-ile_minus][i-1] * (sumy_prefiksowe[k-ile_minus][ciag.size()-1] - sumy_prefiksowe[k-ile_minus][i]);
                if (sumy_prefiksowe[j-ile_minus][i-1] > 0 && sumy_prefiksowe[k-ile_minus][ciag.size()-1] - sumy_prefiksowe[k-ile_minus][i] > 0)
                {
                    stat[int(j) - ile_minus][int(ciag[i]) - ile_minus][int(k) - ile_minus] = true;
                    wyn += ile_par;
                }
            }
        }
    }
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            for (int k = 0; k < 26; ++k)
                if (stat[i][j][k] == true)
                    wyn_ile++;
    printf("%lld %lld",wyn,wyn_ile);

    return 0;
}
