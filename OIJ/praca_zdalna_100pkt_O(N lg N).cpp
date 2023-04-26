#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Pracownik
{
    int poczatek;
    int koniec;
};

int n = 0, wsk = 0, ile_wzietych = 0;
ll wyn = 0;
vector<Pracownik> pracownicy;
vector<int> kandydaci;
vector<ll> wyniki;
vector<int> poczatki;
vector<int> konce;

int main()
{
    /* O(N lg N), Optymalny dobor spotkanie jest zawsze w chwili poczatku / konca pracy jakiegos pracownika. */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    pracownicy.assign(n,{});
    for (int i = 0; i < n; ++i)
        cin >> pracownicy[i].poczatek >> pracownicy[i].koniec;

    kandydaci.assign(2*n,-1);
    for (int i = 0; i < n; ++i)
    {
        kandydaci[2*i] = pracownicy[i].poczatek;
        kandydaci[2*i+1] = pracownicy[i].koniec;
    }
    sort(kandydaci.begin(), kandydaci.end());

    konce.assign(n,-1);
    for (int i = 0; i < n; ++i)
        konce[i] = pracownicy[i].koniec;
    sort(konce.begin(),konce.end());

    wyniki.assign(2*n,0);
    for (int i = 1; i < n*2; ++i)
    {
        while(wsk < n)
        {
            if (kandydaci[i] > konce[wsk])
            {
                ile_wzietych++;
                wsk++;
            }
            else
                break;
        }
        wyn += (ll)ile_wzietych * (ll)(kandydaci[i] - kandydaci[i-1]);
        wyniki[i] = wyn;
    }

    poczatki.assign(n,-1);
    for (int i = 0; i < n; ++i)
        poczatki[i] = pracownicy[i].poczatek;
    sort(poczatki.begin(),poczatki.end(),greater<int>());

    wsk = 0, wyn = 0, ile_wzietych = 0;
    for (int i = n*2-1; i >= 0; --i)
    {
        while(wsk < n)
        {
            if (kandydaci[i] < poczatki[wsk])
            {
                ile_wzietych++;
                wsk++;
            }
            else
                break;
        }
        wyn += (ll)ile_wzietych * (ll)(kandydaci[i+1] - kandydaci[i]);
        wyniki[i] += wyn;
    }

    wyn = 1e18+20;
    for (int i = 0; i < 2*n; ++i)
        wyn = min(wyn, wyniki[i]);

    for (int i = 0; i < 2*n; ++i)
    {
        if (wyniki[i] == wyn)
        {
            cout << kandydaci[i] << ' ' << wyn << '\n';
            return 0;
        }
    }

    return 0;
}
