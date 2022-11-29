#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;
vector<int> wystapienia_idx;
long long wyn = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    wystapienia_idx.assign(n+1,0);

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
        wystapienia_idx[wczytana_liczba] = i;
    }

    int x = 1;
    wyn = wystapienia_idx[1] + 1;
    while(x < n)
    {
        if (wystapienia_idx[x] < wystapienia_idx[x+1])
        {
            wyn += wystapienia_idx[x+1] - wystapienia_idx[x];
        }
        else
        {
            wyn += n - (wystapienia_idx[x]+1);
            wyn += wystapienia_idx[x+1]+1;
        }
        x++;
    }

    printf("%lld",wyn);
    return 0;
}