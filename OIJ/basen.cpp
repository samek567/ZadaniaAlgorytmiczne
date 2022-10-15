#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n = 0;
    long long liczba = 0;
    long long licznik = 1;
    long long pierwsza_liczba = 0;
    long long druga_liczba = 0;
    bool czyRosnacy;
    vector<long long> Liczby;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> liczba;
        Liczby.push_back(liczba);
    }

    pierwsza_liczba = Liczby[0];
    druga_liczba = Liczby[1];

    if (pierwsza_liczba > druga_liczba)
    {
        czyRosnacy = false;
        licznik++;
    }
    else
    {
        czyRosnacy = true;
    }

    for (long long i = 0; i < n-1; i++)
    {
        if (Liczby[i] > Liczby[i+1] && czyRosnacy == true )
        {
            licznik++;
            czyRosnacy = false;
            //cout << "Liczy od i to: " << Liczby[i] << endl;
        }
        else if (Liczby[i] < Liczby[i+1] && czyRosnacy == false )
        {
            licznik++;
            czyRosnacy = true;
            //cout << "Liczy od i to: " << Liczby[i] << endl;
        }
    }

    cout << licznik;

    return 0;
}