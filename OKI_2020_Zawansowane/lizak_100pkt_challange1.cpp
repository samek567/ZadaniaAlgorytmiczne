#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0, idx_pierwszej_W = 1e7, idx_ostatniej_W = -1e7;
string lizak;
vector<pair<int,int>> zap; // first - poczatek, second - koniec zapytania (oba idx-y)

void przetwarzaj(int l, int p)
{
    int suma = 0;
    for (int i = l; i <= p; ++i)
    {
        if (lizak[i] == 'T')
            suma += 2;
        else
            suma += 1;
    }
    while(suma > 0)
    {
        zap[suma] = {l,p};
        suma -= 2;
        if (lizak[l] == 'T')
            l++;
        else if (lizak[p] == 'T')
            p--;
        else
        {
            l++;
            p--;
        }
    }
}

int main()
{
    // O(N+M) korzystamy z obserwacji, ze zawsze fragment lizaka mozna obciac o 2,
    // wiec szukamy fragmentu o najwiekszej sumie parzystego i nieparzystego, szukajac pierszego wystapienia smaku waniliowego.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> lizak;
    zap.assign(2000005,{-1,-1});
    przetwarzaj(0,n-1);
    if (n != 1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (lizak[i] == 'W')
            {
                idx_pierwszej_W = min(idx_pierwszej_W,i);
                idx_ostatniej_W = max(idx_ostatniej_W,i);
            }
        }
        if (idx_pierwszej_W != 1e7)
        {
            if (idx_pierwszej_W == n-1)
                przetwarzaj(0,n-2);
            else if (idx_ostatniej_W == 0)
                przetwarzaj(1,n-1);
            else
            {
                if (idx_pierwszej_W + 1 < n - idx_ostatniej_W)
                    przetwarzaj(idx_pierwszej_W+1,n-1);
                else
                    przetwarzaj(0,idx_ostatniej_W-1);
            }
        }
    }

    while(m--)
    {
        cin >> a;
        if (zap[a].first == -1)
            cout << "NIE" << '\n';
        else
            cout << zap[a].first + 1 << " " << zap[a].second + 1 << '\n';
    }

    return 0;
}