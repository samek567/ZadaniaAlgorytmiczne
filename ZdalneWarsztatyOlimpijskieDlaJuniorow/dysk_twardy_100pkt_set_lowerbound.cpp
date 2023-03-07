#include <iostream>
#include <set>

using namespace std;

int n = 0, wczytana_liczba = 0;
set<int> S;

int main()
{
    // O(N lg N), mozna na drzewie przedzialowym punkt - przedzial z binary searchem
    // w O(N * lg N * lg N), ale to z binary serchem i drzewem przedzialowym, nie wiem czy przejdzie czasowo.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        S.insert(i);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        S.erase(wczytana_liczba);
        auto it = S.lower_bound(wczytana_liczba);
        if (it == S.end())
            cout << "NIE" << '\n';
        else
            cout << *it << '\n';
    }
    return 0;
}