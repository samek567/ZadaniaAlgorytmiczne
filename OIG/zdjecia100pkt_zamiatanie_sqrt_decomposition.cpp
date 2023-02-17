#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Przedzial
{
    int x;
    int poczatek_y;
    int koniec_y;
    int ile_dodajemy; // Ile dodajemy(poczatek zdjecia, +1) czy odejmujemy(koniec zdjecia, -1)
};

int n = 0, k = 447, ile_przedzialow = 402000 / k, x_1 = 0, x_2 = 0, y_1 = 0, y_2 = 0, max_wyn = 0; // K ~ sqrt(max(N))
vector<Przedzial> przedzialy_wejscie; // Wczytane z wejscia, do counting sorta.
vector<Przedzial> przedzialy; // Na nich operujemy, juz posortowane(po counting sorcie)
vector<int> stat; // Ile wbite aktualnie w miejscu;
vector<int> ile_dodajemy_przedzial; // Jaki jest zapas na calym przedziale(jak skakalismy co sqrt, po pelnych przedzialach)
vector<int> max_przedzial; // Maks liczba na przedziale(tym o dlugosci sqrt, nie uwzgledniajac ile_dodajemy_przedzial(wspolnych dla wszystkich elementow))
vector<int> counting_sort_poczatki[400001]; // 400001, bo liczb na zmiotce, bedzie maksymalnie 400001
vector<int> counting_sort_konce[400001]; // // 400001, bo liczb na zmiotce, bedzie maksymalnie 400001

inline void counting_sort() // Sortowanie przez zliczanie
{
    for (int i = 0; i <= 4e5; ++i)
    {
        for (int j = 0; j < counting_sort_poczatki[i].size(); ++j)
            przedzialy.push_back(przedzialy_wejscie[counting_sort_poczatki[i][j]]);
        for (int j = 0; j < counting_sort_konce[i].size(); ++j)
            przedzialy.push_back(przedzialy_wejscie[counting_sort_konce[i][j]]);
    }
}

inline void dodaj(int a, int b, int val) // Sqrt decomposition.
{
    // Dodawania na przedzialach. O(sqrt(400001))
    a += 2e5, b += 2e5;
    int w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k;

    // Dodajemy w innych przedzialach niz A i B
    for (int i = w_jakim_przedziale_a+1; i < w_jakim_przedziale_b; ++i)
        ile_dodajemy_przedzial[i] += val;

    // Dorownujemy na przedziale A
    for (int i = a; i <= min(w_jakim_przedziale_a * k + k-1,b); ++i)
        stat[i] += val;

    // Dorownujemy w przedziale B
    if (w_jakim_przedziale_a != w_jakim_przedziale_b)
        for (int i = b; i >= w_jakim_przedziale_b * k; --i)
            stat[i] += val;

    // Sprawdzamy max-a w przedziale A
    max_przedzial[w_jakim_przedziale_a] = -1000000;
    for (int i = w_jakim_przedziale_a * k; i < w_jakim_przedziale_a * k + k; ++i)
        max_przedzial[w_jakim_przedziale_a] = max(max_przedzial[w_jakim_przedziale_a], stat[i]);

    // Sprawdzamy max-a w przedziale B
    max_przedzial[w_jakim_przedziale_b] = -1000000;
    for (int i = w_jakim_przedziale_b * k; i < w_jakim_przedziale_b * k + k; ++i)
        max_przedzial[w_jakim_przedziale_b] = max(max_przedzial[w_jakim_przedziale_b], stat[i]);
}

inline int odczytaj_max()
{
    // Odtwarzanie wyniku, O(sqrt(400001))
    int wyn = 0;
    for (int i = 0; i < ile_przedzialow; ++i)
        wyn = max(wyn,max_przedzial[i] + ile_dodajemy_przedzial[i]);
    return wyn;
}

int main()
{
    // O(N*sqrt(N) + N) - zamiatanie (zamiast drzewa przedzial-przedzial(dodaj na przedziale, i odczytaj maxa) mamy pierwiastek). N, bo trzeba posortowac zdjecia(mozna counting sortem)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        counting_sort_poczatki[x_1+200000].push_back(przedzialy_wejscie.size());
        przedzialy_wejscie.push_back({x_1,y_1,y_2,1});

        counting_sort_konce[x_2+200000].push_back(przedzialy_wejscie.size());
        przedzialy_wejscie.push_back({x_2,y_1,y_2,-1});
    }

    counting_sort();

    stat.assign(402000,0);
    ile_dodajemy_przedzial.assign(ile_przedzialow,0);
    max_przedzial.assign(ile_przedzialow,0);

    for (int i = 0; i < 2*n; ++i)
    {
        dodaj(przedzialy[i].poczatek_y,przedzialy[i].koniec_y,przedzialy[i].ile_dodajemy);
        if (przedzialy[i].ile_dodajemy == 1)
            max_wyn = max(max_wyn,odczytaj_max());
    }

    cout << max_wyn << '\n';

    return 0;
}
