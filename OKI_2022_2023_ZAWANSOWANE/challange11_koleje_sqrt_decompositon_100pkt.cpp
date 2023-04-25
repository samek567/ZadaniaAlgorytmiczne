#include <iostream>
#include <vector>

using namespace std;

int k = 224, ile_przedzialow = 0, n = 0, m = 0, z = 0, a = 0, b = 0, v = 0;
vector<int> dodawanie_przedzial;
vector<int> max_przedzial;
vector<int> stat;

inline void dodaj(int a, int b, int val)
{

}

inline int odczytaj_max(int a, int b)
{
    a--, b--;
    int wyn = 0, w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k;

    for (int i = w_jakim_przedziale_a+1; i < w_jakim_przedziale_b; ++i)
        wyn = max(wyn,max_przedzial[i] + dodawanie_przedzial[i]);

    for (int i = a; i <= min(w_jakim_przedziale_a * k + k-1,b); ++i)
        wyn = max(wyn,stat[i] + dodawanie_przedzial[w_jakim_przedziale_a]);

    if (w_jakim_przedziale_a != w_jakim_przedziale_b)
        for (int i = b; i >= w_jakim_przedziale_b * k; --i)
            wyn = max(wyn,stat[i] + dodawanie_przedzial[w_jakim_przedziale_b]);

    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> z;

    ile_przedzialow = n / k + 1;
    stat.assign(n+2*k,0);
    dodawanie_przedzial.assign(ile_przedzialow,0);
    max_przedzial.assign(ile_przedzialow,0);

    while(z--)
    {
        cin >> a >> b >> v;
        if (odczytaj_max(a,b-1) + v <= m)
        {
            a--, b-=2;
            int w_jakim_przedziale_a = a / k, w_jakim_przedziale_b = b / k;

            // Dodajemy na przedzialach, gdzie nie ma A oraz nie ma B
            for (int i = w_jakim_przedziale_a+1; i < w_jakim_przedziale_b; ++i)
                dodawanie_przedzial[i] += v;

            // Dopelniamy i bierzemy max-a do przedzialu, gdzie jest A
            for (int i = a; i <= min(w_jakim_przedziale_a*k + k-1,b); ++i)
            {
                stat[i] += v;
                max_przedzial[w_jakim_przedziale_a] = max(max_przedzial[w_jakim_przedziale_a],stat[i]);
            }

            // Dopelniamy i bierzemy max-a do przedzialu, gdzie jest B
            if (w_jakim_przedziale_a != w_jakim_przedziale_b)
            {
                for (int i = b; i >= w_jakim_przedziale_b * k; --i)
                {
                    stat[i] += v;
                    max_przedzial[w_jakim_przedziale_b] = max(max_przedzial[w_jakim_przedziale_b],stat[i]);
                }
            }
            printf("T\n");
        }
        else
            printf("N\n");
    }

    return 0;
}