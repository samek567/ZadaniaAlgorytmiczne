#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Liczba
{
    long long wartosc;
    long long numer;

    bool operator < (const Liczba& liczba) const
    {
        return wartosc < liczba.wartosc;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long bajtson_w = 0;
    long long bajtson_v = 0;
    long long wczytane_w = 0;
    long long wczytane_v = 0;
    double ruchy = 0;
    vector<Liczba> liczba_ruchow;
    vector<long long> idxy_nadmiarow;

    cin >> n >> bajtson_w >> bajtson_v;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytane_w >> wczytane_v;
        if (wczytane_v <= bajtson_v)
        {
            idxy_nadmiarow.push_back(i+1);
            continue;
        }
        ruchy = ceil(double(bajtson_w-wczytane_w)/(wczytane_v-bajtson_v));
        liczba_ruchow.push_back({ruchy,i+1});
    }

    sort(liczba_ruchow.begin(),liczba_ruchow.end());
/*
    for (auto i : liczba_ruchow)
    {
        cout << i.wartosc << endl;
    }
*/
    for (int i = 0; i < liczba_ruchow.size(); ++i)
    {
        if (liczba_ruchow[i].wartosc <= i)
        {
            cout << "GAME OVER";
            return 0;
        }
    }

    for (auto i : liczba_ruchow)
    {
        cout << i.numer << " ";
    }
    for (auto i : idxy_nadmiarow)
    {
        cout << i << " ";
    }
    return 0;
}