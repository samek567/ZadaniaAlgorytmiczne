#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll lewy_wsk = 0, prawy_wsk = 0;
ll n = 0, sito_SIZE = 2e8+1, suma = 2;
vector<ll> P;
vector<bool> sito(2e8+1,false);

void przesuwaj_lewy()
{
    suma -= P[lewy_wsk];
    lewy_wsk++;
    if (lewy_wsk > prawy_wsk)
    {
        prawy_wsk = lewy_wsk;
        suma = P[lewy_wsk];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (ll i = 2; i <= sito_SIZE; ++i)
    {
        if (sito[i] == false)
        {
            P.push_back(i);
            for (ll j = i * i; j <= sito_SIZE; j += i)
                sito[j] = true;
        }
    }

    if (n < 2)
    {
        printf("NIE");
        return 0;
    }

    while(true)
    {
        if (suma == n)
        {
            printf("%lld %lld",P[lewy_wsk],P[prawy_wsk]);
            return 0;
        }
        else if (lewy_wsk == prawy_wsk && prawy_wsk == P.size() - 1)
            break;
        else if (prawy_wsk == P.size() - 1)
            przesuwaj_lewy();
        else if (suma + P[prawy_wsk+1] <= n)
        {
            suma += P[prawy_wsk+1];
            prawy_wsk++;
        }
        else
            przesuwaj_lewy();
    }
    printf("NIE");

    return 0;
}