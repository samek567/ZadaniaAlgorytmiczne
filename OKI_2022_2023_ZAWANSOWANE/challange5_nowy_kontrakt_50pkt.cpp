#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0;
bool czy_dopelnilismy = false;
vector<string> liczby;

inline void dopelniaj(int idx)
{
    while(liczby[idx].size() < liczby[idx-1].size())
    {
        liczby[idx].push_back('0');
        wyn++;
    }
}

inline void dopelniaj_zero_wiecej(int idx)
{
    while(liczby[idx].size() <= liczby[idx-1].size())
    {
        liczby[idx].push_back('0');
        wyn++;
    }
}

inline bool czy_wieksze(int &idx1, int idx2)
{
    for (int i = 0; i < liczby[idx1].size(); ++i)
    {
        if (liczby[idx1][i] > liczby[idx1-1][i])
            return true;
        else if (liczby[idx1][i] < liczby[idx1-1][i])
            return false;
    }
    return false;
}

int main()
{
    // Brucik.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    liczby.assign(n,"");
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    for (int i = 1; i < n; ++i)
    {
        if (liczby[i].size() > liczby[i-1].size())
            continue;
        if (liczby[i].size() == liczby[i-1].size())
        {
            if (czy_wieksze(i,i-1) == true)
                continue;
            wyn++;
            liczby[i].push_back('0');
            continue;
        }
        czy_dopelnilismy = false;
        for (int j = 0; j < liczby[i].size(); ++j)
        {
            if (liczby[i][j] > liczby[i-1][j])
            {
                dopelniaj(i);
                czy_dopelnilismy = true;
                break;
            }
            else if (liczby[i][j] < liczby[i-1][j])
            {
                dopelniaj_zero_wiecej(i);
                czy_dopelnilismy = true;
                break;
            }
        }
        if (czy_dopelnilismy == false)
        {
            int idx_roznego_od_dziewiec = -1;
            for (int j = liczby[i-1].size()-1; j >= liczby[i].size(); --j)
            {
                if (liczby[i-1][j] != '9')
                {
                    idx_roznego_od_dziewiec = j;
                    break;
                }
            }
            if (idx_roznego_od_dziewiec == -1)
            {
                while(liczby[i].size() <= liczby[i-1].size())
                {
                    liczby[i].push_back('0');
                    wyn++;
                }
            }
            else
            {
                int SIZE = liczby[i].size(), czy_dopelnilismy = false;
                for (int j = SIZE; j < liczby[i-1].size(); ++j)
                {
                    if (j == idx_roznego_od_dziewiec)
                    {
                        liczby[i].push_back(char(liczby[i-1][j]+1));
                        czy_dopelnilismy = true;
                    }
                    else if (czy_dopelnilismy == false)
                        liczby[i].push_back(liczby[i-1][j]);
                    else
                        liczby[i].push_back('0');
                    wyn++;
                }
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}