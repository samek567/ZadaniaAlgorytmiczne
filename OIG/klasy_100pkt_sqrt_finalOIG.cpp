#include <iostream>
#include <vector>

using namespace std;

int n = 0, wyn = 0;
string ciag;
vector<int> idxy;
vector<bool> czy_sprawdzilismy(1e6+1,false);

int przetwarzaj_kandydata(int k)
{
    int wyn = 0;
    vector<int> stat(k,0);

    for (int i = 0; i < idxy.size(); ++i)
        stat[idxy[i]%k]++;

    for (int i = 0; i < k; ++i)
        wyn = max(wyn,stat[i]);
    return wyn;
}

int main()
{
    // O(N * sqrt(N)), sprawdzamy na kandydata, tylko 2, oraz odleglosci pomiedzy kolejnymi kamieniami,
    // dzieki tablicy czy_sprawdzilismy, nie ma powtorzen i mamy O(N * sqrt(N)).
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    for (int i = 0; i < n; ++i)
        if (ciag[i] == '#')
            idxy.push_back(i);

    wyn = przetwarzaj_kandydata(2);
    czy_sprawdzilismy[2] = true;

    for (int i = 0; i < idxy.size()-1; ++i)
    {
        if (czy_sprawdzilismy[idxy[i+1] - idxy[i]] == false && idxy[i+1] - idxy[i] != 1)
        {
            wyn = max(wyn,przetwarzaj_kandydata(idxy[i+1] - idxy[i]));
            czy_sprawdzilismy[idxy[i+1] - idxy[i]] = true;
        }
    }

    cout << wyn << '\n';

    return 0;
}
