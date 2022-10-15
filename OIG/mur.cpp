#include <iostream>

using namespace std;

struct Element
{
    long long x;
    long long y;
};

long long iloczyn_wektorowy (Element el_1, Element el_2)
{
    long long iloczyn_wektorowy = (el_1.x * el_2.y) - (el_1.y * el_2.x);
    return iloczyn_wektorowy;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z = 0;
    cin >> z;

    for (int h = 0; h < z; ++h)
    {

        int n = 0;
        bool czy_koniec = false;
        Element jacek;

        cin >> n >> jacek.x >> jacek.y;
        Element elementy[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> elementy[i].x >> elementy[i].y;
            elementy[i].x -= jacek.x;
            elementy[i].y -= jacek.y;
        }

        char kierunek;
        long long iloczyn_wekt = iloczyn_wektorowy(elementy[0],elementy[1]);
        if(iloczyn_wekt == 0)
        {
            cout << "NIE" << endl;
            czy_koniec = true;
        }
        else  if (iloczyn_wekt > 0)
        {
            kierunek = 'P';
        }
        else
        {
            kierunek = 'L';
        }
        for (int i = 1; i < n; ++i)
        {
            // Sztuczka z modulo n.
            long long iloczyn_vect = iloczyn_wektorowy(elementy[i % n],elementy[(i+1) % n]);
            if (iloczyn_vect == 0)
            {
                cout << "NIE" << endl;
                czy_koniec = true;
                break;
            }
            else if (iloczyn_vect > 0)
            {
                if (kierunek == 'L')
                {
                    cout << "NIE" << endl;
                    czy_koniec = true;
                    break;
                }
            }
            else
            {
                if (kierunek == 'P')
                {
                    cout << "NIE" << endl;
                    czy_koniec = true;
                    break;
                }
            }
        }
        if (czy_koniec == false)
        {
            cout << "TAK" << endl;
        }

    }
    return 0;
}