#include <iostream>
#include <vector>

using namespace std;

int n = 0, DOD = 97;
string ciag;
vector<int> pasujace[30];
vector<int> dod;

int main()
{
    // 41pkt -> O(N^2) i wypisujemy poprawnie dlugosc ciagu, niekoniecznie sam ciag.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    n = ciag.size();

    for (int i = 0; i < n; ++i)
        pasujace[(int)ciag[i]-DOD].push_back(i);

    for (int i = 0; i < 26; ++i)
    {
        if (pasujace[i].size() == 0)
        {
            cout << (char)(i+DOD);
            return 0;
        }
    }

    for (int i = 2; i <= n+1; ++i)
    {
        dod.clear();
        for (int j = 0; j < n; ++j)
        {
            bool czy_sie_da = true;
            for (int k = 0; k < 26; ++k)
                if (pasujace[k].size() == 0 or pasujace[k][0] >= j)
                    czy_sie_da = false;
            if (czy_sie_da == true)
                dod.push_back(j);
        }
        for (int j = 0; j < 26; ++j)
            pasujace[j].clear();
        for (int j = 0; j < dod.size(); ++j)
            pasujace[(int)ciag[dod[j]]-DOD].push_back(dod[j]);
        for (int j = 0; j < 26; ++j)
        {
            if (pasujace[j].size() == 0)
            {
                for (int k = 0; k < i; ++k)
                    cout << 'b';
                return 0;
            }
        }
    }

    return 0;
}