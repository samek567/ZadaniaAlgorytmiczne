#include <iostream>
#include <vector>

using namespace std;

struct Przeszkoda
{
    long long x;
    long long gora;
    long long dol;
};

long long n = 0, x = 0, x_i = 0, a_i = 0, b_i = 0, gora = 0, dol = 0, wyn = 0;
vector<Przeszkoda> przeszkody;

bool czy_mozna_przejsc_przeszkody ()
{
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            gora += przeszkody[i].x;
            dol -= (przeszkody[i].x);
        }
        else
        {
            gora += (przeszkody[i].x - przeszkody[i-1].x);
            dol -= (przeszkody[i].x - przeszkody[i-1].x);
        }

        if (dol >= przeszkody[i].gora)
        {
            return false;
        }
        if (gora <= przeszkody[i].dol)
        {
            return false;
        }

        // Teraz normalizujemy
        if (dol <= przeszkody[i].dol)
        {
            if (abs(dol % 2) == abs(przeszkody[i].dol % 2))
            {
                dol = przeszkody[i].dol + 2;
            }
            else
            {
                dol = przeszkody[i].dol + 1;
            }
        }
        if (gora >= przeszkody[i].gora)
        {
            if (abs(gora % 2) == abs(przeszkody[i].gora % 2))
            {
                gora = przeszkody[i].gora - 2;
            }
            else
            {
                gora = przeszkody[i].gora - 1;
            }
        }

        if (dol >= przeszkody[i].gora || gora <= przeszkody[i].dol)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Zadanie FlappyBird XIV OI 1 etap, 100pkt.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    if (n == 0)
    {
        cout << "0" << "\n";
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> x_i >> a_i >> b_i;
        przeszkody.push_back({x_i,b_i,a_i});
    }

    if (czy_mozna_przejsc_przeszkody() == true)
    {
        long long ile_r;
        long long ile_skok;
        if (dol >= 0)
        {
            ile_r = przeszkody[n-1].x;
            ile_skok = dol;
            wyn = (ile_r - ile_skok) / 2 + ile_skok;
        }
        else
        {
            ile_r = przeszkody[n-1].x - (abs(dol));
            wyn = ile_r / 2;
        }
        cout << wyn << "\n";
    }
    else
    {
        cout << "NIE" << "\n";
    }

    return 0;
}
