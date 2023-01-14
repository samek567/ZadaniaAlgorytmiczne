#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba = 0;
vector<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    if (k == 1)
    {
        int minn = 1e9+5;
        for (int i = 0; i < n; ++i)
            minn = min(minn,liczby[i]);
        printf("%d",minn);
    }
    else if (k == 2)
    {
        vector<int> min_sufix;
        int min_lewo = 1e9+5, wyn = -1e9-5;
        min_sufix.assign(n,liczby[n-1]);
        for (int i = n-2; i >= 0; --i)
            min_sufix[i] = min(liczby[i],min_sufix[i+1]);
        for (int i = 0; i < n-1; ++i)
        {
            min_lewo = min(min_lewo,liczby[i]);
            wyn = max(wyn,max(min_lewo,min_sufix[i+1]));
        }
        printf("%d",wyn);
    }
    else
    {
        int maxx = -1e9-5;
        for (int i = 0; i < n; ++i)
            maxx = max(maxx,liczby[i]);
        printf("%d",maxx);
    }

    return 0;
}