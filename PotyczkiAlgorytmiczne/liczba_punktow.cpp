#include <iostream>

using namespace std;

int n = 0, ile_dobrze = 0, ile_podciag = 0, wyn = 0;
char wczytany_znak;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ile_podciag = n / 10;

    for (int i = 1; i <= n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'T')
            ile_dobrze++;
        if (i % ile_podciag == 0)
        {
            if (ile_dobrze == ile_podciag)
                wyn++;
            ile_dobrze = 0;
        }
    }

    printf("%d",wyn);

    return 0;
}