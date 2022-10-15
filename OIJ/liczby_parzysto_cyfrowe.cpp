#include <iostream>

using namespace std;


int main() {
    long long n = 0;
    int k = 0;

    cin >> n;

    int cyfry[50];

    while (n>0) {
        cyfry[k] = n%5;
        k++;
        n /=5 ;
    }

    for (int i = k-1; i>=0; i--)
    {
        cout << 2 * cyfry[i];
    }

    return 0;
}