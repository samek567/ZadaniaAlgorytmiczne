#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Produkt
{
    int ID;
    int liczba_wystapien;
    int idx;

    bool operator < (const Produkt&produkt)
    {
        if (ID != produkt.ID)
        {
            return ID < produkt.ID;
        }
        else
        {
            return idx < produkt.idx;
        }
    }
};

struct Produkt2
{
    int ID;
    int liczba_wystapien;
    int idx;

    bool operator < (const Produkt2&produkt2)
    {
        return idx < produkt2.idx;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;

    cin >> n;
    Produkt produkty[n];
    vector<Produkt2> zliczone;

    for (int i = 0; i < n; ++i)
    {
        cin >> produkty[i].ID >> produkty[i].liczba_wystapien;
        produkty[i].idx = i;
    }
    sort(produkty,produkty+n);

    int licznik = produkty[0].liczba_wystapien;
    int idx_w = produkty[0].idx;
    for (int i = 0; i < n-1; ++i)
    {
        if (produkty[i].ID == produkty[i+1].ID)
        {
            licznik+=produkty[i+1].liczba_wystapien;
        }
        else
        {
            zliczone.push_back({produkty[i].ID,licznik,idx_w});
            licznik = produkty[i+1].liczba_wystapien;
            idx_w = produkty[i+1].idx;
        }
    }
    zliczone.push_back({produkty[n-1].ID,licznik,idx_w});

    sort(zliczone.begin(),zliczone.end());

    cout << zliczone.size() << endl;
    for (auto i : zliczone)
    {
        cout << i.ID << " " << i.liczba_wystapien << endl;
    }

    return 0;
}