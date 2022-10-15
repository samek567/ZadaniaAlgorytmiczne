#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    vector<int> liczby;

    cin >> a >> b >> c;

    liczby.push_back(a);
    liczby.push_back(b);
    liczby.push_back(c);

    sort(liczby.begin(),liczby.end());

    //for (int i = 0; i < liczby.size(); i++)
    //{

    if (liczby[0] == 0)
    {

        if (liczby[1] != 0)
        {
            liczby[0] = liczby[1];
            liczby[1] = 0;
        }
        else if (liczby[2] != 0)
        {

            liczby[0] = liczby[2];
            liczby[2] = 0;
        }
    }
    cout << liczby[0];
    cout << liczby[1];
    cout << liczby[2];
    //}

    return 0;
}