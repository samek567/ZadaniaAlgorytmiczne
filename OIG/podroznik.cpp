#include <iostream>

using namespace std;

struct granica
{
    long long lewo;
    long long prawo;
    long long dol;
    long long gora;
};

struct punkt
{
    long long x;
    long long y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long k = 0;
    punkt pozycja{0,0};
    punkt przed{0,0};
    punkt suma{0,0};
    string ciag;
    granica maxy{0,0,0,0};

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> k >> ciag;

        granica tmax{0,0,0,0};
        pozycja.x = 0;
        pozycja.y = 0;

        for (long long i = 0; i < ciag.size(); i++)
        {
            if (ciag[i] == 'N')
            {
                pozycja.y++;
                if (pozycja.y > tmax.gora)
                {
                    tmax.gora = pozycja.y;
                }
            }
            else if (ciag[i] == 'S')
            {
                pozycja.y--;
                if (pozycja.y < tmax.dol)
                {
                    tmax.dol = pozycja.y;
                }
            }
            else if (ciag[i] == 'E')
            {
                pozycja.x++;
                if (pozycja.x > tmax.prawo)
                {
                    tmax.prawo = pozycja.x;
                }
            }
            else if (ciag[i] == 'W')
            {
                pozycja.x--;
                if (pozycja.x < tmax.lewo)
                {
                    tmax.lewo = pozycja.x;
                }
            }

        }
        //
        long long dg = tmax.gora - pozycja.y;
        long long dd = tmax.dol - pozycja.y;
        long long dp = tmax.prawo - pozycja.x;
        long long dl = tmax.lewo - pozycja.x;
        //
        pozycja.x = pozycja.x * k;
        pozycja.y = pozycja.y * k;
        //
        if (pozycja.y > 0)
        {
            tmax.gora = pozycja.y + dg;
        }
        if (pozycja.y < 0)
        {
            tmax.dol = pozycja.y + dd;
        }
        if (pozycja.x > 0)
        {
            tmax.prawo = pozycja.x + dp;
        }
        if (pozycja.x < 0)
        {
            tmax.lewo = pozycja.x + dl;
        }
        //
        if (przed.x + tmax.prawo > maxy.prawo)
        {
            maxy.prawo = przed.x + tmax.prawo;
        }
        if (przed.x + tmax.lewo < maxy.lewo)
        {
            maxy.lewo = przed.x + tmax.lewo;
        }
        if (przed.y + tmax.gora > maxy.gora)
        {
            maxy.gora = przed.y + tmax.gora;
        }
        if (przed.y + tmax.dol < maxy.dol)
        {
            maxy.dol = przed.y + tmax.dol;
        }
        //
        suma.x += pozycja.x;
        suma.y += pozycja.y;
        przed.x = suma.x;
        przed.y = suma.y;

    }

    cout << maxy.gora - maxy.dol << " " << maxy.prawo - maxy.lewo;

    return 0;
}