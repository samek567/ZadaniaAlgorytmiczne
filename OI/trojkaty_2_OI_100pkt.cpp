#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long wczytana_liczba = 0;
vector<long long> patyczki;

int main()
{
    // Kompilator nie akceptuje printf-ow, trzeba cout-y.

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true)
    {
        cin >> wczytana_liczba;
        if (wczytana_liczba == 0 || patyczki.size() > 47)
        {
            break;
        }
        patyczki.push_back(wczytana_liczba);
    }

    for (int i = 0; i < patyczki.size(); ++i)
    {
        for (int j = i+1; j < patyczki.size(); ++j)
        {
            for (int k = j+1; k < patyczki.size(); ++k)
            {
                vector<long long> do_sorta = {patyczki[i],patyczki[j],patyczki[k]};
                sort(do_sorta.begin(),do_sorta.end());
                if (do_sorta[0] + do_sorta[1] > do_sorta[2])
                {
                    cout << patyczki[i] << " " << patyczki[j] << " " << patyczki[k] << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "NIE" << '\n';

    return 0;
}