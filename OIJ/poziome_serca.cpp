#include <iostream>

using namespace std;

void rysuj_serca(int);

int main() {
    int n = 0;
    cin >> n;
    rysuj_serca(n);
    return 0;
}

void rysuj_serca(int n) {
    for (int i=0; i<n; i++) {
        cout << " @@@   @@@ " << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "@   @ @   @" << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "@    @    @" << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "@         @" << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << " @       @ " << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "  @     @  " << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "   @   @   " << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "    @ @    " << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << "     @     " << " ";
    }
    cout << endl;
}