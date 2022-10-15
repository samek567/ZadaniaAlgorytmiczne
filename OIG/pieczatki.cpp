#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int wysokosc = 0;
    int szerokosc = 0;
    int wysokosc_pieczatki = 0;
    int szerokosc_pieczatki = 0;
    int liczba_pieczatek = 0;
    char wczytany_znak;


    cin >> wysokosc >> szerokosc;

    int szachownica[wysokosc][szerokosc];
    int wyniki[wysokosc][szerokosc]; // Ten co bedziemy na koniec sprawdzac.

    for (int i = 0; i < wysokosc; ++i)
    {
        for (int j = 0; j < szerokosc; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '.')
            {
                szachownica[i][j] = 0; // Puste
                wyniki[i][j] = 0; // Puste
            }
            else
            {
                szachownica[i][j] = 1; // Zajete
                wyniki[i][j] = 1; // Puste
            }
        }
    }

    cin >> liczba_pieczatek;

    for (int i = 0; i < liczba_pieczatek; ++i)
    {
        int pierwszy_wiersz_x = 0;
        int ostatni_wiersz_x = 0;
        int pierwsza_kolumna_x = 0;
        int ostatnia_kolumna_x = 0;

        cin >> wysokosc_pieczatki >> szerokosc_pieczatki;

        int pieczatka[wysokosc_pieczatki][szerokosc_pieczatki];
        for (int j = 0; j < wysokosc_pieczatki; ++j)
        {
            for (int k = 0; k < szerokosc_pieczatki; ++k)
            {
                cin >> wczytany_znak;
                if (wczytany_znak == '.')
                {
                    pieczatka[j][k] = 0; // Puste
                }
                else
                {
                    pieczatka[j][k] = 1; // Zajete
                }
            }
        }
        // Wystarczy nam tylko tymczasowe wektory pieczatek NIE MUSIMY ZAPISYWAC!


        // Obcinanie

        // Pierwsza kolumna
        bool czy_koniec = false;
        for (int c = 0; c < szerokosc_pieczatki; ++c)
        {
            if (czy_koniec == true)
            {
                break;
            }
            for (int d = 0; d < wysokosc_pieczatki; ++d)
            {
                if (pieczatka[d][c] == 1)
                {
                    pierwsza_kolumna_x = c;
                    czy_koniec = true;
                    break;
                }
            }
        }
        // Ostatnia kolumna
        czy_koniec = false;
        for (int c = szerokosc_pieczatki-1; c >= 0; --c)
        {
            if (czy_koniec == true)
            {
                break;
            }
            for (int d = wysokosc_pieczatki-1; d >= 0; --d)
            {
                if (pieczatka[d][c] == 1)
                {
                    ostatnia_kolumna_x = c;
                    czy_koniec = true;
                    break;
                }
            }
        }
        // Pierwszy wiersz
        czy_koniec = false;
        for (int c = 0; c < wysokosc_pieczatki; ++c)
        {
            if (czy_koniec == true)
            {
                break;
            }
            for (int d = 0; d < szerokosc_pieczatki; ++d)
            {
                if (pieczatka[c][d] == 1)
                {
                    pierwszy_wiersz_x = c;
                    czy_koniec = true;
                    break;
                }
            }
        }

        // Ostatni wiersz
        czy_koniec = false;
        for (int c = wysokosc_pieczatki-1; c >= 0; --c)
        {
            if (czy_koniec == true)
            {
                break;
            }
            for (int d = szerokosc_pieczatki-1; d >= 0; --d)
            {
                if (pieczatka[c][d] == 1)
                {
                    ostatni_wiersz_x = c;
                    czy_koniec = true;
                    break;
                }
            }
        }

        int nowa_pieczatka[ostatni_wiersz_x-pierwszy_wiersz_x+1][ostatnia_kolumna_x-pierwsza_kolumna_x+1];
        int wysokosc_nowej_pieczatki = ostatni_wiersz_x - pierwszy_wiersz_x + 1;
        int szerokosc_nowej_pieczatki = ostatnia_kolumna_x - pierwsza_kolumna_x + 1;

        for (int r = pierwszy_wiersz_x; r <= ostatni_wiersz_x; ++r)
        {
            for (int t = pierwsza_kolumna_x; t <= ostatnia_kolumna_x; ++t)
            {
                nowa_pieczatka[r-pierwszy_wiersz_x][t-pierwsza_kolumna_x] = pieczatka[r][t];
            }
        }

        if (wysokosc_nowej_pieczatki > wysokosc || szerokosc_nowej_pieczatki > szerokosc)
        {
            continue;
        }

        // Z kazdego punktu rysujemy prostokaw w O(n*n*n*n).
        for (int h = 0; h < wysokosc; ++h)
        {
            for (int g = 0; g < szerokosc; ++g)
            {
                if (wysokosc_nowej_pieczatki+h > wysokosc || szerokosc_nowej_pieczatki+g > szerokosc) // Czy mozemy postawic pieczatke.
                {
                    continue;
                }

                // Mozemy postawic pieczatke.

                bool czy_zepsulismy = false;
                for (int f = 0; f < wysokosc_nowej_pieczatki; ++f)
                {
                    for (int l = 0; l < szerokosc_nowej_pieczatki; ++l)
                    {
                        if (nowa_pieczatka[f][l] == 1)// Tu trzeba uwzglednic ze jest mniejsze.
                        {
                            if (szachownica[h+f][g+l] != 1)
                            {
                                czy_zepsulismy = true;
                                break;
                            }
                        }
                    }
                    if (czy_zepsulismy == true)
                    {
                        break;
                    }
                }

                if (czy_zepsulismy == false)
                {
                    for (int a = h; a < h + wysokosc_nowej_pieczatki; ++a)
                    {
                        for (int b = g; b < g + szerokosc_nowej_pieczatki; ++b)
                        {
                            if (nowa_pieczatka[a-h][b-g] == 1)
                            {
                                wyniki[a][b] = 2;
                            }
                        }
                    }
                }

            }
        }
    }

    // Koncowe sprawdzanie czy Tak czy Nie.
    for (int i = 0; i < wysokosc; ++i)
    {
        for (int j = 0; j < szerokosc; ++j)
        {
            if (wyniki[i][j] == 1)
            {
                cout << "NIE";
                return 0;
            }
        }
    }
    cout << "TAK";
    return 0;
}