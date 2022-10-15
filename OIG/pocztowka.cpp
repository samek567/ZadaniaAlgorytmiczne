#include <iostream>
#include <vector>

using namespace std;

int n = 0;
long long m = 0, wczytana_pocztowka = 0;
unsigned long long wyn = 0;

vector<int> pasujace_idxy; // Vector z idxami >= m.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_pocztowka;
        if (wczytana_pocztowka >= m)
        {
            pasujace_idxy.push_back(i);
        }
    }

    if (pasujace_idxy.size() == 0)
    {
        cout << "0";
        return 0;
    }

    int wskaznik = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i > pasujace_idxy[wskaznik])
        {
            if (wskaznik < pasujace_idxy.size()-1)
            {
                wskaznik++;
            }
            else
            {
                break;
            }
        }
        wyn += n - pasujace_idxy[wskaznik];
    }

    cout << wyn;
    // Zlozonnosc takiego rozwiazania to O(n), bo dla kazdej liczby wykonujemy sprawdzanie w czasie O(1).
    return 0;
}