#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

struct Odcinek
{
    double zysk;
    long long liczba_czesci;
    long long przeciwprostokatna;
    bool operator < (const Odcinek&odcinek) const // Operator wstawiania po najwiekszych wynikach.
    {
        return zysk > odcinek.zysk;
    }
    bool operator == (const Odcinek&odcinek) const
    {
        return zysk == odcinek.zysk;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int k = 0;
    long long d = 0;
    long long wczytane_polozenie = 0;
    double pole_grupy = 0;
    double wynik = 0;
    double zysk = 0;
    double zysk_wynik = 0;
    vector<long long> polozenia_lamp;
    multiset<Odcinek> zacienione_obszary;

    cin >> n >> k >> d;


    for (int i = 0; i < n; ++i)
    {
        cin >> wczytane_polozenie;
        polozenia_lamp.push_back(wczytane_polozenie);
    }

    for (int i = 1; i < n; ++i)
    {
        pole_grupy = pow (((double)(polozenia_lamp[i]-polozenia_lamp[i-1]) / (1)),2) * 1 / 4;
        zysk_wynik = pole_grupy - (pow((double)(polozenia_lamp[i]-polozenia_lamp[i-1]) / (2),2) / 4 * (2));
        zacienione_obszary.insert({zysk_wynik,1,polozenia_lamp[i]-polozenia_lamp[i-1]});
    }

    Odcinek do_usuniecia;
    for (int i = 0; i < k; ++i)
    {
        for(auto j : zacienione_obszary)
        {
            pole_grupy = pow (((double)(j.przeciwprostokatna) / (j.liczba_czesci+1)),2) * (j.liczba_czesci+1) / 4;
            zysk_wynik = pole_grupy - ((pow((double)(j.przeciwprostokatna) / (j.liczba_czesci+2),2) / 4 * (j.liczba_czesci+2)));
            zacienione_obszary.insert({zysk_wynik,j.liczba_czesci+1,j.przeciwprostokatna});
            do_usuniecia = j;
            break;
        }
        zacienione_obszary.erase(zacienione_obszary.lower_bound(do_usuniecia)); // Usuwanie tylko jednego elementu z multi seta

    }

    for (auto j : zacienione_obszary)
    {
        wynik += pow(((double)j.przeciwprostokatna / ((double)j.liczba_czesci)),2) / 4 * (double)j.liczba_czesci;
    }

    cout << fixed << std::setprecision(9) << wynik;
    return 0;
}