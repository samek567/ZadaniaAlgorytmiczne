#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q = 0;
    unsigned long long a = 0;
    unsigned long long b = 0;
    unsigned long long iloczyn = 1;
    unsigned long long wynik = 0;
    unsigned long long idx_pierszej = 0;
    unsigned long long idx_ostatniej = 0;
    unsigned long long suma = 0;
    bool czy_sumujemy = false;
    vector<unsigned long long> silnie;
    vector<unsigned long long> liczby_silne;
    vector<unsigned long long> sumy_prefiksowe;

    for (int i = 1; i <= 17; ++i)
    {
        iloczyn *= i;
        silnie.push_back(iloczyn);
    }


    // Liczby silne 1 elementowe
    for (int i = 0; i < 17; ++i)
    {
        liczby_silne.push_back(silnie[i]);
    }



    // Liczby silne 2 elementowe
    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            liczby_silne.push_back(silnie[i] + silnie[j]);
        }
    }



    // Liczby silne 3 elementowe
    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]);
            }
        }
    }



    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]);
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]);
                    }
                }
            }
        }
    }



    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }



    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                for (int x = f+1; x < 17; ++x)
                                                {
                                                    liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]+silnie[x]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                for (int x = f+1; x < 17; ++x)
                                                {
                                                    for (int y = x+1; y < 17; ++y)
                                                    {
                                                        liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]+silnie[x]+silnie[y]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                for (int x = f+1; x < 17; ++x)
                                                {
                                                    for (int y = x+1; y < 17; ++y)
                                                    {
                                                        for (int z = y+1; z < 17; ++z)
                                                        {
                                                            liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]+silnie[x]+silnie[y]+silnie[z]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                for (int x = f+1; x < 17; ++x)
                                                {
                                                    for (int y = x+1; y < 17; ++y)
                                                    {
                                                        for (int z = y+1; z < 17; ++z)
                                                        {
                                                            for (int v = z+1; v < 17; ++v)
                                                            {
                                                                liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]+silnie[x]+silnie[y]+silnie[z]+silnie[v]);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                for (int x = f+1; x < 17; ++x)
                                                {
                                                    for (int y = x+1; y < 17; ++y)
                                                    {
                                                        for (int z = y+1; z < 17; ++z)
                                                        {
                                                            for (int v = z+1; v < 17; ++v)
                                                            {
                                                                for (int q = v+1; q < 17; ++q)
                                                                {
                                                                    liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]+silnie[x]+silnie[y]+silnie[z]+silnie[v]+silnie[q]);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 17; ++i)
    {
        for (int j = i+1; j < 17; ++j)
        {
            for (int k = j+1; k < 17; ++k)
            {
                for (int g = k+1; g < 17; ++g)
                {
                    for (int h = g+1; h < 17; ++h)
                    {
                        for (int a = h+1; a < 17; ++a)
                        {
                            for (int b = a+1; b < 17; ++b)
                            {
                                for (int c = b+1; c < 17; ++c)
                                {
                                    for (int d = c+1; d < 17; ++d)
                                    {
                                        for (int e = d+1; e < 17; ++e)
                                        {
                                            for (int f = e+1; f < 17; ++f)
                                            {
                                                for (int x = f+1; x < 17; ++x)
                                                {
                                                    for (int y = x+1; y < 17; ++y)
                                                    {
                                                        for (int z = y+1; z < 17; ++z)
                                                        {
                                                            for (int v = z+1; v < 17; ++v)
                                                            {
                                                                for (int q = v+1; q < 17; ++q)
                                                                {
                                                                    for (int r = q+1; r < 17; ++r)
                                                                    {
                                                                        liczby_silne.push_back(silnie[i]+silnie[j]+silnie[k]+silnie[g]+silnie[h]+silnie[a]+silnie[b]+silnie[c]+silnie[d]+silnie[e]+silnie[f]+silnie[x]+silnie[y]+silnie[z]+silnie[v]+silnie[q]+silnie[r]);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    sort(liczby_silne.begin(),liczby_silne.end()); // Sortujemy do binary searcha

    for (int i = 0; i < liczby_silne.size(); ++i)
    {
        suma += liczby_silne[i];
        sumy_prefiksowe.push_back(suma);
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        bool czy_liczymy = false;
        wynik = 0;
        cin >> a >> b;

        long long szukana = a;
        long long poczatek = -1;
        long long koniec = liczby_silne.size();
        long long srodek = 0;

        while (koniec - poczatek != 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (liczby_silne[srodek] >= szukana)
            {
                koniec = srodek;
            }
            else
            {
                poczatek = srodek;
            }
        }
        if (koniec < liczby_silne.size())
        {
            idx_pierszej = koniec;
        }
        else
        {
            cout << "0" << endl;
            continue;
        }

        szukana = b;
        poczatek = -1;
        koniec = liczby_silne.size();
        srodek = 0;

        while (koniec - poczatek != 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (liczby_silne[srodek] >= szukana)
            {
                koniec = srodek;
            }
            else
            {
                poczatek = srodek;
            }
        }
        if (koniec < liczby_silne.size())
        {
            idx_ostatniej = koniec;
            if (idx_ostatniej == 0)
            {
                cout << liczby_silne[0] << endl;
                continue;
            }
            else
            {
                if (liczby_silne[idx_ostatniej] == b)
                {
                    if (idx_pierszej == 0)
                    {
                        wynik = sumy_prefiksowe[idx_ostatniej];
                    }
                    else
                    {
                        wynik = sumy_prefiksowe[idx_ostatniej] - sumy_prefiksowe[idx_pierszej-1];
                    }
                }
                else
                {
                    if (idx_pierszej == 0)
                    {
                        wynik = sumy_prefiksowe[idx_ostatniej-1];
                    }
                    else
                    {
                        wynik = sumy_prefiksowe[idx_ostatniej-1] - sumy_prefiksowe[idx_pierszej-1];
                    }
                }
            }
            //cout << "Idx od poczatek: " << idx_pierszej << " Idx od koniec: " << idx_ostatniej << endl;

        }
        else
        {
            cout << "0" << endl;
            continue;
        }

        cout << wynik << endl;
    }

    return 0;
}