#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unsigned long long n = 0;
    unsigned long long liczba = 0;
    unsigned long long pole = 0;
    vector<unsigned long long> Liczby;

    cin >> n;

    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> liczba;
        Liczby.push_back(liczba);
    }

    sort(Liczby.begin(),Liczby.end());


    for (int i = 0; i < n; i++)
    {
        //cout << Liczby[i] << endl;
    }


    if (n < 4)
    {
        pole = 0;
    }
    else
    {
        pole = (Liczby[n-4]) * (Liczby[n-4]);
    }

    cout << pole;

    return 0;
}