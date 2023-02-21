#include <iostream>

using namespace std;

int x = 0, s = 0;

int main()
{
    // O(1), zauwazamy ze konic doskoczy do wszystkich odleglosci ponizej 2*s, klasyczny problem zajaca,
    // z 1 + 1/2 + 1/4 + 1/8... w nieskonczonosci = 2, ale tak naprawde nigdy do tego nie doskoczymy.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> s;

    if (s * 2 > x)
        cout << "TAK" << '\n';
    else
        cout << "NIE" << '\n';

    return 0;
}