#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Q
{
    __int128 p;
    __int128 q;

    bool operator < (const Q &other) const
    {
        return p * other.q < other.p * q;
    }
    bool operator > (const Q &other) const
    {
        return p * other.q > other.p * q;
    }
    bool operator >= (const Q &other) const
    {
        return p * other.q >= other.p * q;
    }
    bool operator == (const Q &other) const
    {
        return p * other.q == other.p * q;
    }
    Q operator + (const Q &other) const
    {
        return { p * other.q + other.p * q, q * other.q };
    }
    Q operator - (const Q &other) const
    {
        return { p * other.q - other.p * q, q * other.q };
    }
    Q operator * (const Q &other) const
    {
        return { p * other.p, q * other.q};
    }
    Q operator / (const Q &other) const
    {
        return { p * other.q, q * other.p};
    }
};

struct Ciezarowka
{
    ll tyl;
    ll przod;
    Q v;
};

struct Element_seta
{
    Q t;
    ll numer_c1;
    ll numer_c2;

    bool operator < (const Element_seta &element_seta) const
    {
        if (t == element_seta.t)
        {
            return numer_c1 > element_seta.numer_c1;
        }
        return t < element_seta.t;
    }
    bool operator == (const Element_seta &element_seta) const
    {
        if (t == element_seta.t)
        {
            return numer_c1 == element_seta.numer_c1;
        }
        return t == element_seta.t;
    }
};

bool debug = false;

vector<Ciezarowka> ciezarowki;
set<ll> numery_ciezarowek_przed_bajtazarem;
set<Element_seta> wyprzedzenia;
string kierunek_bajtazara = "prawo";
ll n = 0, x_i = 0, d_i = 0, wynik = 0, d = 0, w = 0, m = 0, w_i = 0, m_i = 0;

void wypisz_ciezarowki()
{
    cout << "Wypisuje ciezarowki: " << endl;
    for (int i = 0; i <= n; ++i)
    {
        cout << "Idx: " << i << " tyl: " << ciezarowki[i].tyl << " przod: " << ciezarowki[i].przod << "\n";
    }
    cout << endl;
}


void wypisz_numery_ciezarowek_przed_bajtazarem()
{
    cout << "Wypisuje numery ciezarowek przed bajtazarem: " << "\n";
    for (auto i : numery_ciezarowek_przed_bajtazarem)
    {
        cout << i << "\n";
    }
    cout << "\n";
}

Q kiedy_sie_dogonia(Ciezarowka c1, Ciezarowka c2) // Kiedy c1 dogoni c2 , Ta funkcja oblicza czas globalnie a nie samego wyprzedzenia
{
    __int128 delta_s = __int128(c2.tyl) - __int128(c1.przod);

    if (c1.v < c2.v)
    {
        return {__int128(-1),__int128(1)};
    }

    Q delta_v = c1.v - c2.v;

    if (c1.v == c2.v)
    {
        if (delta_s == __int128(0))
        {
            return {__int128(0),__int128(1)};
        }
        else
        {
            return {__int128(-1),__int128(1)};
        }
    }
    if (delta_s == __int128(0))
    {
        return {__int128(0),__int128(1)};
    }
    return Q{delta_s,__int128(1)} / delta_v;
}

Q kiedy_bajtazar_wyprzedzi(Ciezarowka Bajtazar, Ciezarowka c2) // Ta funkcja oblicza czas globalnie a nie samego wyprzedzenia
{
    return (Q{__int128(c2.przod) - __int128(Bajtazar.tyl),__int128(1)}) / (Bajtazar.v - c2.v);
}

bool czy_bajtazar_moze_zjechac(Ciezarowka Bajtazar, Ciezarowka c1, Ciezarowka c2, Q czas)
{
    Q przod_c1 = Q{__int128(c1.przod),__int128(1)} + czas * c1.v;
    Q tyl_c2 = Q{__int128(c2.tyl),__int128(1)} + czas * c2.v;

    Q tyl_minus_przod = tyl_c2 - przod_c1;
    Q dlugosc_bajtazara = Q{__int128(Bajtazar.przod) - __int128(Bajtazar.tyl),__int128(1)};

    if (tyl_minus_przod >= dlugosc_bajtazara)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> w >> m;
    ciezarowki.push_back({0,d,{__int128(w), __int128(m)}});
    // Dodajemy Bajtazara on ma idx 0.

    for (int i = 1; i <= n; ++i)
    {
        cin >> x_i >> d_i >> w_i >> m_i;
        ciezarowki.push_back({d + x_i - d_i,d + x_i, {__int128(w_i),__int128(m_i)}});
        numery_ciezarowek_przed_bajtazarem.insert(i);
        if (kiedy_sie_dogonia(ciezarowki[i - 1], ciezarowki[i]).p != -1)
        {
            wyprzedzenia.insert({kiedy_sie_dogonia(ciezarowki[i - 1], ciezarowki[i]), i - 1, i});
        }
    }

    while (!numery_ciezarowek_przed_bajtazarem.empty())
    {
        auto min_dogoniecie = wyprzedzenia.begin();

        if (kierunek_bajtazara == "prawo")
        {
            if (numery_ciezarowek_przed_bajtazarem.size() == 1)
            {
                cout << (wynik+1) << "\n";
                return 0;
            }

            if (min_dogoniecie->numer_c1 == 0) // Bajtazar dogania najszybciej.
            {
                kierunek_bajtazara = "lewo";
                wynik++;
                wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                wyprzedzenia.insert({kiedy_bajtazar_wyprzedzi(ciezarowki[0],ciezarowki[*numery_ciezarowek_przed_bajtazarem.begin()]), 0, *numery_ciezarowek_przed_bajtazarem.begin()});
            }
            else
            {
                ciezarowki[min_dogoniecie->numer_c2] = {ciezarowki[min_dogoniecie->numer_c2].tyl - (ciezarowki[min_dogoniecie->numer_c1].przod - ciezarowki[min_dogoniecie->numer_c1].tyl),ciezarowki[min_dogoniecie->numer_c2].przod,{ciezarowki[min_dogoniecie->numer_c2].v.p,ciezarowki[min_dogoniecie->numer_c2].v.q}};
                auto it_1 = numery_ciezarowek_przed_bajtazarem.find(min_dogoniecie->numer_c1);
                auto it_2 = it_1;
                ll numer_ciezarowki_it_1 = *it_1;
                ll numer_ciezarowki_it_2 = numer_ciezarowki_it_1;
                ll numer_ciezarowki_it_3 = numer_ciezarowki_it_1;
                if (*numery_ciezarowek_przed_bajtazarem.begin() == numer_ciezarowki_it_1) // Bajtazar jest za
                {
                    ++it_2;
                    numer_ciezarowki_it_2 = *it_2;
                    auto wsk_dogoniecie_wczesniejszej = wyprzedzenia.find({kiedy_sie_dogonia(ciezarowki[0],ciezarowki[numer_ciezarowki_it_1]), 0, numer_ciezarowki_it_1});
                    numery_ciezarowek_przed_bajtazarem.erase(numer_ciezarowki_it_1);
                    wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                    if (wsk_dogoniecie_wczesniejszej != wyprzedzenia.end())
                    {
                        wyprzedzenia.erase({wsk_dogoniecie_wczesniejszej->t,wsk_dogoniecie_wczesniejszej->numer_c1,wsk_dogoniecie_wczesniejszej->numer_c2});
                    }
                    wyprzedzenia.insert({kiedy_sie_dogonia(ciezarowki[0], ciezarowki[numer_ciezarowki_it_2]), 0, numer_ciezarowki_it_2});
                }
                else
                {
                    --it_1;
                    ++it_2;
                    numer_ciezarowki_it_1 = *it_1;
                    numer_ciezarowki_it_3 = *it_2;
                    auto wsk_dogoniecie_wczesniejszej = wyprzedzenia.find({kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1], ciezarowki[numer_ciezarowki_it_2]), numer_ciezarowki_it_1, numer_ciezarowki_it_2});
                    numery_ciezarowek_przed_bajtazarem.erase(numer_ciezarowki_it_2);
                    wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                    if (wsk_dogoniecie_wczesniejszej != wyprzedzenia.end())
                    {
                        wyprzedzenia.erase({wsk_dogoniecie_wczesniejszej->t,wsk_dogoniecie_wczesniejszej->numer_c1,wsk_dogoniecie_wczesniejszej->numer_c2});
                    }
                    if (kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1], ciezarowki[numer_ciezarowki_it_3]).p != -1)
                    {
                        wyprzedzenia.insert({kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1],ciezarowki[numer_ciezarowki_it_3]), numer_ciezarowki_it_1, numer_ciezarowki_it_3});
                    }
                }
            }
        }
        else
        {
            if (numery_ciezarowek_przed_bajtazarem.size() == 1)
            {
                cout << wynik << "\n";
                return 0;
            }

            if (min_dogoniecie->numer_c1 == 0)
            {
                auto it_1 = numery_ciezarowek_przed_bajtazarem.begin();
                auto it_2 = numery_ciezarowek_przed_bajtazarem.begin();
                ++it_2;
                ll numer_ciezarowki_it_1 = *it_1;
                ll numer_ciezarowki_it_2 = *it_2;

                if (czy_bajtazar_moze_zjechac(ciezarowki[0],ciezarowki[numer_ciezarowki_it_1],ciezarowki[numer_ciezarowki_it_2], min_dogoniecie->t)) // Jesli mozna zmienic pas (nie ma kolizji) z i+1 - sza.
                {
                    kierunek_bajtazara = "prawo";
                    wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                    wyprzedzenia.insert({kiedy_sie_dogonia(ciezarowki[0], ciezarowki[numer_ciezarowki_it_2]), 0, numer_ciezarowki_it_2});
                }
                else
                {
                    wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                    wyprzedzenia.insert({kiedy_bajtazar_wyprzedzi(ciezarowki[0], ciezarowki[numer_ciezarowki_it_2]), 0, numer_ciezarowki_it_2});
                }

                auto it_delete = wyprzedzenia.find({kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1],ciezarowki[numer_ciezarowki_it_2]), numer_ciezarowki_it_1, numer_ciezarowki_it_2});
                if (it_delete != wyprzedzenia.end()) // Znalezlismy na secie.
                {
                    wyprzedzenia.erase({it_delete->t,it_delete->numer_c1,it_delete->numer_c2});
                }
                numery_ciezarowek_przed_bajtazarem.erase(numer_ciezarowki_it_1);
            }
            else
            {
                ciezarowki[min_dogoniecie->numer_c2] = {ciezarowki[min_dogoniecie->numer_c2].tyl - (ciezarowki[min_dogoniecie->numer_c1].przod - ciezarowki[min_dogoniecie->numer_c1].tyl),ciezarowki[min_dogoniecie->numer_c2].przod,{ciezarowki[min_dogoniecie->numer_c2].v.p,ciezarowki[min_dogoniecie->numer_c2].v.q}};
                auto it_1 = numery_ciezarowek_przed_bajtazarem.find(min_dogoniecie->numer_c1);
                auto it_2 = it_1;
                ll numer_ciezarowki_it_1 = *it_1;
                ll numer_ciezarowki_it_2 = numer_ciezarowki_it_1;
                ll numer_ciezarowki_it_3 = numer_ciezarowki_it_1;
                if (*numery_ciezarowek_przed_bajtazarem.begin() == numer_ciezarowki_it_1)
                {
                    ++it_2;
                    numer_ciezarowki_it_2 = *it_2;
                    auto wsk_dogoniecie_wczesniejszej = wyprzedzenia.find({kiedy_bajtazar_wyprzedzi(ciezarowki[0],ciezarowki[numer_ciezarowki_it_1]), 0, numer_ciezarowki_it_1});
                    numery_ciezarowek_przed_bajtazarem.erase(numer_ciezarowki_it_1);
                    wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                    if (wsk_dogoniecie_wczesniejszej != wyprzedzenia.end())
                    {
                        wyprzedzenia.erase({wsk_dogoniecie_wczesniejszej->t,wsk_dogoniecie_wczesniejszej->numer_c1,wsk_dogoniecie_wczesniejszej->numer_c2});
                    }
                    wyprzedzenia.insert({kiedy_bajtazar_wyprzedzi(ciezarowki[0], ciezarowki[numer_ciezarowki_it_2]), 0, numer_ciezarowki_it_2});
                }
                else
                {
                    --it_1;
                    ++it_2;
                    numer_ciezarowki_it_1 = *it_1;
                    numer_ciezarowki_it_3 = *it_2;
                    auto wsk_dogoniecie_wczesniejszej = wyprzedzenia.find({kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1], ciezarowki[numer_ciezarowki_it_2]), numer_ciezarowki_it_1, numer_ciezarowki_it_2});
                    numery_ciezarowek_przed_bajtazarem.erase(numer_ciezarowki_it_2);
                    wyprzedzenia.erase({min_dogoniecie->t,min_dogoniecie->numer_c1,min_dogoniecie->numer_c2});
                    if (wsk_dogoniecie_wczesniejszej != wyprzedzenia.end())
                    {
                        wyprzedzenia.erase({wsk_dogoniecie_wczesniejszej->t,wsk_dogoniecie_wczesniejszej->numer_c1,wsk_dogoniecie_wczesniejszej->numer_c2}); // Tu wywala
                    }
                    if (kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1], ciezarowki[numer_ciezarowki_it_3]).p != -1)
                    {
                        wyprzedzenia.insert({kiedy_sie_dogonia(ciezarowki[numer_ciezarowki_it_1],ciezarowki[numer_ciezarowki_it_3]), numer_ciezarowki_it_1, numer_ciezarowki_it_3});
                    }
                }
            }
        }
    }

    cout << wynik << "\n";

    return 0;
}