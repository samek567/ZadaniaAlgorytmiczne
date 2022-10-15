#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    unsigned long long n = 0;
    unsigned long long kwota_wczytana = 0;
    unsigned long long nr_policjanta_wczytana = 0;
    unsigned long long suma = 0;
    vector<unsigned long long> kwota;
    vector<unsigned long long> policjant;

    cin >> n;

    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> kwota_wczytana;
        kwota.push_back(kwota_wczytana);
        //cout << kwota[i] << endl;
    }

    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> nr_policjanta_wczytana;
        policjant.push_back(nr_policjanta_wczytana);
        //cout << policjant[i] << endl;
    }

    sort(kwota.begin(),kwota.end());
    sort(policjant.begin(),policjant.end(), greater<long long>());

    for (unsigned long long i = 0; i < n; i++)
    {
        suma += atoll((to_string(kwota[i]) + to_string(policjant[i])).c_str());
    }
    cout << suma << endl;

    return 0;
}