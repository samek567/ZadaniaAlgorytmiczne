#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0, poczatek = 0, max_wysokosc = 0, stat = 0;
char wczytany_znak;
vector<int> salatka;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'p')
            salatka.push_back(1);
        else
            salatka.push_back(-1);
    }

    for (int i = 0; i < n; ++i)
    {
        max_wysokosc = -1e8;
        stat = poczatek;
        for (int j = i; j < n; ++j)
        {
            stat += salatka[j];
            max_wysokosc = max(max_wysokosc,stat);
            if (stat < poczatek)
                break;
            if (stat >= max_wysokosc)
            {
                wyn = max(wyn,j-i+1);
                //cout << "I: " << i << " J: " << j << endl;
            }
        }
        poczatek += salatka[i];
        //cout << "Wyn: " << wyn << " Max wysokosc: " << max_wysokosc << '\n';
    }

    printf("%d",wyn);

    return 0;
}