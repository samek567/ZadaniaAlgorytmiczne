#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, q = 0, wczytana_liczba = 0, a = 0, b = 0, cnt = 0;
char znak;
vector<int> liczby;
vector<int> do_sorta;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b >> znak;
        do_sorta.clear();
        cnt = 0;
        for (int j = a-1; j < b; ++j)
            do_sorta.push_back(liczby[j]);
        if (znak == 'M')
            sort(do_sorta.begin(),do_sorta.end(), greater<int>());
        else
            sort(do_sorta.begin(),do_sorta.end());
        for (int j = a-1; j < b; ++j)
        {
            liczby[j] = do_sorta[cnt];
            cnt++;
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ",liczby[i]);
    return 0;
}