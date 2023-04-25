#include <iostream>
#include <vector>

using namespace std;

int suma = 0, zapas = 0;
string ciag;
vector<int> wyn;

int main()
{
    // O(N), gdzie N to dlugosc ciagu na wejsciu. Zauwazamy, ze kazda cyfra bedzie na kazdej pozycji, i dodajemy w slopku.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ciag;
    for (int i = 0; i < ciag.size(); ++i)
        suma += (int)ciag[i] - 48;

    for (int i = 0; i < ciag.size(); ++i)
    {
        wyn.push_back((suma + zapas) % 10);
        zapas = (suma + zapas) / 10;
    }

    if (zapas != 0)
        wyn.push_back(zapas);

    for (int i = wyn.size()-1; i >= 0; --i)
        cout << wyn[i];

    return 0;
}