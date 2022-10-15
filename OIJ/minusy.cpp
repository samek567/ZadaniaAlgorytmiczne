#include <iostream>
#include <vector>

using namespace std;

struct Grupa
{
    int powtorzenia;
    char znak;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string ciag;
    char kolej;
    int licznik = 0;
    int licznik_max = 0;
    int licznik_tymczasowy = 0;
    vector<Grupa> grupy;

    cin >> ciag;

    for (int i = 0; i < ciag.size(); i++)
    {
        if (ciag[i] == '+')
        {
            if (kolej == '-')
            {
                grupy.push_back({licznik,kolej});
                licznik = 1;
            }
            else
            {
                licznik++;
            }
            kolej = '+';
        }
        else
        {
            if (kolej == '+')
            {
                grupy.push_back({licznik,kolej});
                licznik = 1;
            }
            else
            {
                licznik++;
            }
            kolej = '-';
        }
    }

    grupy.push_back({licznik,kolej});


    /*
    for (int i = 0; i < grupy.size(); i++)
    {
        cout << "i: " << i << " powtorzenia: " << grupy[i].powtorzenia << " znak: " << grupy[i].znak << endl;
    }
    */


    for (int i = 0; i < grupy.size(); i++)
    {
        if (grupy[i].znak == '+')
        {
            licznik_tymczasowy += grupy[i].powtorzenia;
        }
        else
        {
            if (grupy[i].powtorzenia % 2 == 0)
            {
                licznik_tymczasowy += grupy[i].powtorzenia / 2;
            }
            else if (grupy[i].powtorzenia % 2 != 0)
            {
                licznik_tymczasowy += (grupy[i].powtorzenia - 1) / 2;
                if (licznik_tymczasowy > licznik_max)
                {
                    licznik_max = licznik_tymczasowy;
                }
                licznik_tymczasowy = (grupy[i].powtorzenia - 1) / 2;
            }
        }
    }

    if (licznik_tymczasowy > licznik_max)
    {
        licznik_max = licznik_tymczasowy;
    }

    printf("%d",licznik_max);

    return 0;
}