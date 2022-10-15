#include <iostream>
#include <string>

using namespace std;

int suma_cyfr(long long liczba) {
    if (liczba > 0) {
        // return n % 10 + suma_cyfr(n / 10);
        int sum;
        for (sum = 0; liczba > 0; sum += liczba % 10, liczba /= 10)
            ;
        return sum;
    }
    return 0;
}

long long kalkulacja_orig(long long liczba, long long n) {
    long long start = liczba;
    for (int i = 0; i < n-1; i++)
    {
        liczba = 2 * suma_cyfr(liczba);
        // cout << n << endl;
    }
    return liczba;
}


long long kalkulacja(long long liczba, long long n) {
    long long start = n;
    for (int i = 0; i < n-1; i++)
    {
        liczba = 2 * suma_cyfr(liczba);
        if (liczba == 18) {
            return liczba;
        }
        else if (liczba == 8) {
            long long diff = (start - i - 2) % 6;
            switch (diff) {
                case 0: return 8;
                case 1: return 16;
                case 2: return 14;
                case 3: return 10;
                case 4: return 2;
                case 5: return 4;
            }
        }
        else if (liczba == 6) {
            long long diff = (start - i - 2) % 2;
            switch (diff) {
                case 0: return 6;
                case 1: return 12;
            }
        }
        else if (liczba == 4) {
            long long diff = (start - i - 2) % 6;
            switch (diff) {
                case 0: return 4;
                case 1: return 8;
                case 2: return 16;
                case 3: return 14;
                case 4: return 10;
                case 5: return 2;
            }
        }
        else if (liczba == 2) {
            long long diff = (start - i - 2) % 6;
            switch (diff) {
                case 0: return 2;
                case 1: return 4;
                case 2: return 8;
                case 3: return 16;
                case 4: return 14;
                case 5: return 10;
            }
        }
        // cout << n << endl;
    }
    return liczba;
}

int main() {

    long long n = 0;
    long long liczba = 0;

    cin >> n;
    cin >> liczba;

    liczba = kalkulacja(liczba, n);
    cout << liczba;

    /*
    int nn = 111;
    for (long long i=1; i<1+10; i++) {
        if (kalkulacja_orig(i,nn) != kalkulacja(i, nn)) {
            cout << i << "/" << nn << " " << kalkulacja_orig(i, nn) << " " << kalkulacja(i,nn) << endl;
        }
    }
     */

    return 0;
}