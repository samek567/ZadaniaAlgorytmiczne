#include <iostream>
#include <queue>

using namespace std;

struct Punkt
{
    int y;
    int x;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z = 0;

    cin >> z;

    for (int k = 0; k < z; ++k)
    {
        int wysokosc = 0;
        int szerokosc = 0;
        char wczytany_znak;

        cin >> szerokosc >> wysokosc;
        bool czy_diament[wysokosc][szerokosc];
        int wynik[wysokosc][szerokosc];
        Punkt odtwarzanie[wysokosc][szerokosc];

        for (int i = 0; i < wysokosc; ++i)
        {
            for (int j = 0; j < szerokosc; ++j)
            {
                cin >> wczytany_znak;
                if (wczytany_znak == '1')
                {
                    czy_diament[i][j] = true;
                }
                else
                {
                    czy_diament[i][j] = false;
                }
                wynik[i][j] = 0;
            }
        }

        int s = 0;
        for (int i = 0; i < szerokosc; ++i)
        {
            if (czy_diament[0][i] == true)
            {
                s++;
            }
            wynik[0][i] = s;
            odtwarzanie[0][i] = {0,i-1};
        }

        s = wynik[0][0];
        for (int i = 1; i < wysokosc; ++i)
        {
            if (czy_diament[i][0] == true)
            {
                s++;
            }
            wynik[i][0] = s;
            odtwarzanie[i][0] = {i-1,0};
        }

        for (int i = 1; i < wysokosc; ++i)
        {
            for (int j = 1; j < szerokosc; ++j)
            {
                if (wynik[i-1][j] > wynik[i][j-1])
                {
                    odtwarzanie[i][j] = {i-1,j};
                }
                else
                {
                    odtwarzanie[i][j] = {i,j-1};
                }
                wynik[i][j] = max(wynik[i-1][j],wynik[i][j-1]);
                if (czy_diament[i][j] == true)
                {
                    wynik[i][j]++;
                }
            }
        }
        string ciag;
        Punkt wskazywane = {wysokosc-1,szerokosc-1};
        while (wskazywane.x != -1)
        {
            if (odtwarzanie[wskazywane.y][wskazywane.x].y < wskazywane.y)
            {
                ciag += 'v';
            }
            else
            {
                ciag += '>';
            }
            wskazywane = odtwarzanie[wskazywane.y][wskazywane.x];
        }
        cout << wynik[wysokosc-1][szerokosc-1] << " ";
        for (int i = ciag.size() - 2; i >= 0; --i)
        {
            cout << ciag[i];
        }
        cout << endl;
    }
    return 0;
}