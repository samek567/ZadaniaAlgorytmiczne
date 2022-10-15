#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int vect_size = 1000002;

vector<int> samochody;
vector<int>* zaleznosci[vect_size];
vector<int> grupa_koloru;
vector<int> kolory_po_zmianie;

void wypisz_grupy_kolorow()
{
    cout << "Wypisuje vector kolory: " << endl;
    for (int i = 1; i < grupa_koloru.size(); ++i)
    {
        cout << grupa_koloru[i] << " ";
    }
    cout << endl;
}

void wypisz_zaleznosci()
{
    cout << endl << "Wypisuje zaleznosci: " << endl;
    for (int i = 1; i <= grupa_koloru.size(); ++i)
    {
        if (zaleznosci[i] == nullptr)
        {
            continue;
        }
        for (int j = 0; j < zaleznosci[i]->size(); ++j)
        {
            cout << zaleznosci[i]->operator[](j) << " ";
        }
        cout << endl;
    }
}

void wypisz_kolory_samochodow_po_zmianie()
{
    for (int i = 0; i < samochody.size(); ++i)
    {
        cout << kolory_po_zmianie[samochody[i]] << " ";
    }
}

void odtwarzaj_kolory()
{
    int n = grupa_koloru.size();
    for (int i = 1; i < n; ++i)
    {
        if (zaleznosci[i] == nullptr)
        {
            continue;
        }
        if(grupa_koloru[i] == 0)
        {
            continue;
        }
        queue<int> Q;
        Q.push(grupa_koloru[i]);
        while(!Q.empty())
        {
            kolory_po_zmianie[Q.front()] = i;
            for (int j = 1; j < zaleznosci[Q.front()]->size(); ++j)
            {
                kolory_po_zmianie[zaleznosci[Q.front()]->operator[](j)] = i;
                Q.push(zaleznosci[Q.front()]->operator[](j));
            }
            Q.pop();
        }
    }
}

int main()
{
    // JEDNO Z TRUDNIEJSZYCH ZADAN Z OIG-a !!! Zeszlo mi sie z nim okolo 50h, wersja bez wskaznikow daje 93 pkt jeden test nie przechodzi xd
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, m = 0, k = 0, wczytany_samochod = 0, od_kod, do_kod;

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_samochod;
        samochody.push_back(wczytany_samochod);
    }

    for (int i = 0; i <= k; ++i)
    {
        grupa_koloru.push_back(i);
        kolory_po_zmianie.push_back(i);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> od_kod >> do_kod;
        if (zaleznosci[od_kod] == nullptr)
        {
            zaleznosci[od_kod] = new vector<int>();
            zaleznosci[od_kod]->push_back(od_kod);
        }
        if (zaleznosci[do_kod] == nullptr)
        {
            zaleznosci[do_kod] = new vector<int>();
            zaleznosci[do_kod]->push_back(do_kod);
        }

        if (od_kod == do_kod || grupa_koloru[od_kod] == 0)
        {
            continue;
        }
        if (grupa_koloru[do_kod] == 0)
        {
            grupa_koloru[do_kod] = grupa_koloru[od_kod];
        }
        else
        {
            zaleznosci[grupa_koloru[do_kod]]->push_back(grupa_koloru[od_kod]);
        }
        grupa_koloru[od_kod] = 0;
    }


    //Dla testu wypisywanie.
    //wypisz_grupy_kolorow();
    //wypisz_zaleznosci();


    odtwarzaj_kolory(); // Odtwarzamy kolory z zaleznosci.

    wypisz_kolory_samochodow_po_zmianie(); // Wypisujemy samochody po zmianie kolorów.

    return 0;
}