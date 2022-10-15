#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Wspolrzedna
{
    int y;
    int x;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int licznik = 0;
    int pierwsza_kolumna = 0;
    int ostatnia_kolumna = 0;
    int pierwszy_wiersz = 0;
    int ostatni_wiersz = 0;
    string kierunek;
    string skret;

    cin >> n >> kierunek >> skret >> pierwsza_kolumna >> ostatnia_kolumna >> pierwszy_wiersz >> ostatni_wiersz;

    long long wyniki[ostatni_wiersz-pierwszy_wiersz+1][ostatnia_kolumna-pierwsza_kolumna+1];
    //cout << "wysokosc: " << ostatni_wiersz-pierwszy_wiersz+1 << " Szerokosc: " << ostatnia_kolumna-pierwsza_kolumna+1 << endl;

    Wspolrzedna wspolrzedne;
    licznik = n;

    /*
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            szachownica[i][j] = 0;
        }
    }
    */

    if (kierunek == "POLNOC" && skret == "PRAWO")
    {
        wspolrzedne.y = n;
        wspolrzedne.x = 0;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            j = 0;
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }



    else if (kierunek == "POLNOC" && skret == "LEWO")
    {
        wspolrzedne.y = n;
        wspolrzedne.x = n-1;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }


    else if (kierunek == "POLUDNIE" && skret == "LEWO")
    {
        wspolrzedne.y = -1;
        wspolrzedne.x = 0;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }

    else if (kierunek == "POLUDNIE" && skret == "PRAWO")
    {
        wspolrzedne.y = -1;
        wspolrzedne.x = n-1;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }

    else if (kierunek == "WSCHOD" && skret == "LEWO")
    {
        wspolrzedne.y = n-1;
        wspolrzedne.x = -1;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }

    else if (kierunek == "WSCHOD" && skret == "PRAWO")
    {
        wspolrzedne.y = 0;
        wspolrzedne.x = -1;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }

    else if (kierunek == "ZACHOD" && skret == "LEWO")
    {
        wspolrzedne.y = 0;
        wspolrzedne.x = n;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            for (int l = 0; l < licznik; ++l)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }

    else if (kierunek == "ZACHOD" && skret == "PRAWO")
    {
        wspolrzedne.y = n-1;
        wspolrzedne.x = n;
        int j = 0;
        for (int i = 1; i <= pow(n,2); ++i)
        {
            // Gora
            //for (int j = 0; j < licznik; ++j)
            while (j < licznik)
            {
                wspolrzedne.x--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;

            // Prawo
            //for (int k = 0; k < licznik; ++k)
            while (j < licznik)
            {
                wspolrzedne.y--;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            // Dół
            //for (int m = 0; m < licznik; ++m)
            while (j < licznik)
            {
                wspolrzedne.x++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            licznik--;
            // Lewo
            //for (int l = 0; l < licznik; ++l)
            while (j < licznik)
            {
                wspolrzedne.y++;
                if (wspolrzedne.x >= pierwsza_kolumna - 1 && wspolrzedne.x <= ostatnia_kolumna-1 && wspolrzedne.y >= n - ostatni_wiersz && wspolrzedne.y <= n - pierwszy_wiersz)
                {
                    //cout << "i: " << i << " y: " << wspolrzedne.y << " x: " << wspolrzedne.x << endl;
                    //cout << "Wspolrzedne y: " << wspolrzedne.y-(n-ostatni_wiersz) << " x: " << wspolrzedne.x-pierwsza_kolumna<< endl << endl;
                    wyniki[wspolrzedne.y-(n-ostatni_wiersz)][wspolrzedne.x-pierwsza_kolumna + 1] = i; // Y dziala X nie dziala.
                    //wyniki[wspolrzedne.y-pierwsza_kolumna][wspolrzedne.x] = i; // Test czy wyznaczanie y dziala
                }
                i++;
                if (i > pow(n,2))
                {
                    break;
                }
                j++;
            }
            j = 0;
            i--;
        }
    }

    /*
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << szachownica[i][j] << " ";
            }
            cout << endl;
        }
    */


    for (int i = 0; i < ostatni_wiersz-pierwszy_wiersz+1; ++i)
    {
        for (int j = 0; j < ostatnia_kolumna-pierwsza_kolumna+1; ++j)
        {
            cout << wyniki[i][j] << " ";
        }
        cout << endl;
    }



    //delete [] szachownica;
    return 0;
}