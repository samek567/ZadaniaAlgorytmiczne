#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int q = 0, k = 0, n = 0, m = 0, SIZE1 = 0, SIZE2 = 0, wczytana_liczba = 0, wyn = 0;
char wczytany_znak;
bool czy_mamy = false;
int dlugosci_zmiennych[26];
vector<pair<char,int>> slowo1;
vector<pair<char,int>> slowo2;
vector<vector<vector<int>>> wystapienia; // 1 - Litera [0,26], 2 - numer w dlugosiach zmiennych, 3 - wystapienia na jakich idx-ach wystepuje.

inline void wypisz()
{
    cout << "Slowo1: " << endl;
    for (int i = 0; i < SIZE1; ++i)
        cout << slowo1[i].first << ' ';
    cout << endl << "Slowo2: " << endl;
    for (int i = 0; i < SIZE1; ++i)
        cout << slowo2[i].first << ' ';
    cout << endl << endl;
}

inline void DFS(int v, char co_dac)
{
    if (czy_mamy == true)
        return;

    vector<int> do_dodania;
    if (slowo1[v].second != -1)
    {
        for (int i = 0; i < wystapienia[(int)slowo1[v].first-97][slowo1[v].second].size(); ++i)
            do_dodania.push_back(wystapienia[(int)slowo1[v].first-97][slowo1[v].second][i]);
        wystapienia[(int)slowo1[v].first-97][slowo1[v].second].clear();
    }
    if (slowo2[v].second != -1)
    {
        for (int i = 0; i < wystapienia[(int)slowo2[v].first-97][slowo2[v].second].size(); ++i)
            do_dodania.push_back(wystapienia[(int)slowo2[v].first-97][slowo2[v].second][i]);
        wystapienia[(int)slowo2[v].first-97][slowo2[v].second].clear();
    }

    if (slowo1[v].second == -1 && slowo1[v].first != co_dac)
    {
        czy_mamy = true;
        return;
    }
    if (slowo2[v].second == -1 && slowo2[v].first != co_dac)
    {
        czy_mamy = true;
        return;
    }
    slowo1[v] = {co_dac,-1};
    slowo2[v] = {co_dac,-1};

    for (int i = 0; i < do_dodania.size(); ++i)
    {
        DFS(do_dodania[i],co_dac);
    }
}

inline void POW_string(int p, int x)
{
    int SIZE = 10000, idx_najblizszej = SIZE - 1;
    int w1[SIZE] = {0}, zapas[SIZE] = {0};
    w1[SIZE-1] = 1;
    int w2 = p;

    for (int i = 0; i < x; ++i)
    {
        for (int j = SIZE-1; j >= idx_najblizszej; --j)
        {
            int sum = w1[j] * p + zapas[j];
            w1[j] = sum % 10;
            zapas[j] = 0;
            zapas[j-1] += sum / 10;
            if (j == idx_najblizszej)
                if (zapas[j-1] != 0 || w1[j-1] != 0)
                    idx_najblizszej--;
        }
    }

    bool czy_wypisujemy = false;
    for (int i = 0; i < SIZE; ++i)
    {
        if (w1[i] != 0)
            czy_wypisujemy = true;
        if (czy_wypisujemy == true)
            cout << w1[i];
    }
}

int main()
{
    // Podzial grafu na spojne skladowe.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        SIZE1 = 0, SIZE2 = 0, wyn = 0, czy_mamy = false;
        slowo1.clear();
        slowo2.clear();
        wystapienia.clear();
        cin >> k;
        wystapienia.assign(k,{});
        for (int i = 0; i < k; ++i)
        {
            cin >> wczytana_liczba;
            dlugosci_zmiennych[i] = wczytana_liczba;
            for (int j = 0; j < wczytana_liczba; ++j)
                wystapienia[i].push_back({});
        }
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '0' || wczytany_znak == '1')
            {
                SIZE1++;
                slowo1.push_back({wczytany_znak,-1});
            }
            else
            {
                for (int j = 0; j < dlugosci_zmiennych[(int)wczytany_znak-97]; ++j)
                {
                    slowo1.push_back({wczytany_znak,j});
                    wystapienia[(int)wczytany_znak-97][j].push_back(SIZE1 + j);
                }
                SIZE1 += dlugosci_zmiennych[(int)wczytany_znak-97];
            }
        }
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '0' || wczytany_znak == '1')
            {
                SIZE2++;
                slowo2.push_back({wczytany_znak,-1});
            }
            else
            {
                for (int j = 0; j < dlugosci_zmiennych[(int)wczytany_znak-97]; ++j)
                {
                    slowo2.push_back({wczytany_znak,j});
                    wystapienia[(int)wczytany_znak-97][j].push_back(SIZE2 + j);
                }
                SIZE2 += dlugosci_zmiennych[(int)wczytany_znak-97];
            }
        }
        if (SIZE1 != SIZE2)
        {
            cout << "0" << '\n';
            continue;
        }

        for (int i = 0; i < SIZE1; ++i)
        {
            if (slowo1[i].second == -1 && slowo2[i].second == -1)
            {
                if (slowo1[i].first != slowo2[i].first)
                {
                    czy_mamy = true;
                    break;
                }
            }
        }
        if (czy_mamy == true)
        {
            cout << "0" << '\n';
            continue;
        }

        for (int i = 0; i < SIZE1; ++i)
        {
            if (slowo1[i].second == -1 && slowo2[i].second == -1)
                continue;
            else if (slowo1[i].second != -1 && slowo2[i].second != -1)
                continue;
            char znak;
            if (slowo1[i].second == -1)
                znak = slowo1[i].first;
            else
                znak = slowo2[i].first;
            DFS(i,znak);
        }
        if (czy_mamy == true)
        {
            cout << "0" << '\n';
            continue;
        }

        for (int i = 0; i < SIZE1; ++i)
        {
            if (slowo1[i].second != -1 && slowo2[i].second != -1)
            {
                DFS(i,'2');
                wyn++;
            }
        }
        if (czy_mamy == true)
        {
            cout << "0" << '\n';
            continue;
        }

        POW_string(2,wyn);
        cout << '\n';
    }
    return 0;
}