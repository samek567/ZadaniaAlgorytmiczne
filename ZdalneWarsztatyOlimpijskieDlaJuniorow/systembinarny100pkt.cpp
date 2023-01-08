#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

string decyzja, decyzja2, do_zamiany_binarny, wyn_binary;
ll liczba = 0, pow = 1, wyn = 0;
bool czy_byla_jedynka = false;
vector<ll> POW;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> decyzja >> decyzja2;
    decyzja += decyzja2;
    POW.push_back(1);
    for (int i = 1; i <= 60; ++i)
        POW.push_back(POW[i-1] * 2);

    if (decyzja == "nadziesiatkowy")
    {
        cin >> do_zamiany_binarny;
        for (int i = do_zamiany_binarny.size()-1; i >= 0; --i)
        {
            if (do_zamiany_binarny[i] == '1')
                wyn += pow;
            pow *= 2;
        }
        printf("%lld",wyn);
    }
    else
    {
        cin >> liczba;
        for (int i = 60; i >= 0; --i)
        {
            if (POW[i] <= liczba)
            {
                wyn_binary.push_back('1');
                liczba -= POW[i];
            }
            else
                wyn_binary.push_back('0');
        }
        for (int i = 0; i <= 60; ++i)
        {
            if (wyn_binary[i] == '1')
                czy_byla_jedynka = true;
            if (czy_byla_jedynka == true)
                printf("%c",wyn_binary[i]);
        }
    }
    return 0;
}