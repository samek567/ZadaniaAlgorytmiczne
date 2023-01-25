#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Segment
{
    char kolor;
    int ile;
};

struct Element_seta
{
    int ile_truskawka;
    int ile_wanilia;
    bool operator < (const Element_seta &element_seta) const
    {
        if (ile_truskawka == element_seta.ile_truskawka)
            return ile_wanilia < element_seta.ile_wanilia;
        return ile_truskawka < element_seta.ile_truskawka;
    }
};

int n = 0, m = 0, wczytana_liczba = 0, suma_lizak1 = 0, suma_lizak2 = 0, suma_wanilia_lizak1 = 0, suma_wanilia_lizak2 = 0, suma_truskawka_lizak1 = 0, suma_truskawka_lizak2 = 0, ile_wanilia = 0, ile_truskawka = 0, nadmiar_truskawka_lizak1 = 0, nadmiar_truskawka_lizak2 = 0, nadmiar_wanilia_lizak1 = 0, nadmiar_wanilia_lizak2 = 0, wyn = 0, max_wyn = 0;
char wczytany_znak;
bool czy_ulozylismy = false;
vector<Segment> lizak1;
vector<Segment> lizak2;
vector<int> sumy_prefiksowe_wanilia_lizak1;
vector<int> sumy_prefiksowe_wanilia_lizak2;
vector<int> sumy_prefiksowe_truskawka_lizak1;
vector<int> sumy_prefiksowe_truskawka_lizak2;
set<Element_seta> stat; // wanilia, truskawka

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak >> wczytana_liczba;
        lizak1.push_back({wczytany_znak,wczytana_liczba});
        suma_lizak1 += wczytana_liczba;
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> wczytany_znak >> wczytana_liczba;
        lizak2.push_back({wczytany_znak,wczytana_liczba});
        suma_lizak2 += wczytana_liczba;
    }
    if (suma_lizak1 <= 4000 && suma_lizak2 <= 4000)
    {
        // O(N^2* log(max(N1,N2)))
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < lizak1[i].ile; ++j)
            {
                if (lizak1[i].kolor == 'T')
                    suma_truskawka_lizak1++;
                else
                    suma_wanilia_lizak1++;
                sumy_prefiksowe_wanilia_lizak1.push_back(suma_wanilia_lizak1);
                sumy_prefiksowe_truskawka_lizak1.push_back(suma_truskawka_lizak1);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < lizak2[i].ile; ++j)
            {
                if (lizak2[i].kolor == 'T')
                    suma_truskawka_lizak2++;
                else
                    suma_wanilia_lizak2++;
                sumy_prefiksowe_wanilia_lizak2.push_back(suma_wanilia_lizak2);
                sumy_prefiksowe_truskawka_lizak2.push_back(suma_truskawka_lizak2);
            }
        }
        for (int i = min(suma_lizak1,suma_lizak2); i >= 1; --i)
        {
            stat.clear();
            for (int j = 0; j <= suma_lizak1 - i; ++j)
            {
                if (j == 0)
                    stat.insert({sumy_prefiksowe_wanilia_lizak1[j+i-1],sumy_prefiksowe_truskawka_lizak1[j+i-1]});
                else
                    stat.insert({sumy_prefiksowe_wanilia_lizak1[j+i-1] - sumy_prefiksowe_wanilia_lizak1[j-1],sumy_prefiksowe_truskawka_lizak1[j+i-1] - sumy_prefiksowe_truskawka_lizak1[j-1]});
            }
            for (int j = 0; j <= suma_lizak2 - i; ++j)
            {
                if (j == 0)
                {
                    ile_wanilia = sumy_prefiksowe_wanilia_lizak2[j+i-1];
                    ile_truskawka = sumy_prefiksowe_truskawka_lizak2[j+i-1];
                }
                else
                {
                    ile_wanilia = sumy_prefiksowe_wanilia_lizak2[j+i-1] - sumy_prefiksowe_wanilia_lizak2[j-1];
                    ile_truskawka = sumy_prefiksowe_truskawka_lizak2[j+i-1] - sumy_prefiksowe_truskawka_lizak2[j-1];
                }
                if (auto it = stat.find({ile_wanilia,ile_truskawka}) != stat.end())
                {
                    printf("%d",i);
                    return 0;
                }
            }
        }
        printf("0");
    }
    else
    {
        // O(M^4)
        // Mnozymy przez 2, bo dodalismy sztuczne 0, zeby liczyc te skladajace sie z jednego i dwóch niepełnych.
        for (int i = 0; i < n; ++i)
        {
            if (lizak1[i].kolor == 'T')
                ile_truskawka += lizak1[i].ile;
            else
                ile_wanilia += lizak1[i].ile;
            sumy_prefiksowe_truskawka_lizak1.push_back(ile_truskawka);
            sumy_prefiksowe_wanilia_lizak1.push_back(ile_wanilia);
        }
        ile_truskawka = 0;
        ile_wanilia = 0;
        for (int i = 0; i < m; ++i)
        {
            if (lizak2[i].kolor == 'T')
                ile_truskawka += lizak2[i].ile;
            else
                ile_wanilia += lizak2[i].ile;
            sumy_prefiksowe_truskawka_lizak2.push_back(ile_truskawka);
            sumy_prefiksowe_wanilia_lizak2.push_back(ile_wanilia);
        }
        // I - lewy_wsk_lizak1, J - prawy_wsk_lizak1, L - lewy_wsk_lizak2, P - prawy_wsk_lizak2
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (i == 0)
                {
                    suma_truskawka_lizak1 = sumy_prefiksowe_truskawka_lizak1[j];
                    suma_wanilia_lizak1 = sumy_prefiksowe_wanilia_lizak1[j];
                }
                else
                {
                    suma_truskawka_lizak1 = sumy_prefiksowe_truskawka_lizak1[j] - sumy_prefiksowe_truskawka_lizak1[i-1];
                    suma_wanilia_lizak1 = sumy_prefiksowe_wanilia_lizak1[j] - sumy_prefiksowe_wanilia_lizak1[i-1];
                }
                nadmiar_truskawka_lizak1 = 0;
                nadmiar_wanilia_lizak1 = 0;
                if (i != 0)
                {
                    if (lizak1[i-1].kolor == 'T')
                        nadmiar_truskawka_lizak1 += lizak1[i-1].ile;
                    else
                        nadmiar_wanilia_lizak1 += lizak1[i-1].ile;
                }
                if (j != n-1)
                {
                    if (lizak1[j+1].kolor == 'T')
                        nadmiar_truskawka_lizak1 += lizak1[j+1].ile;
                    else
                        nadmiar_wanilia_lizak1 += lizak1[j+1].ile;
                }
                for (int l = 0; l < m; ++l)
                {
                    for (int p = l; p < m; ++p)
                    {
                        if (l == 0)
                        {
                            suma_truskawka_lizak2 = sumy_prefiksowe_truskawka_lizak2[p];
                            suma_wanilia_lizak2 = sumy_prefiksowe_wanilia_lizak2[p];
                        }
                        else
                        {
                            suma_truskawka_lizak2 = sumy_prefiksowe_truskawka_lizak2[p] - sumy_prefiksowe_truskawka_lizak2[l-1];
                            suma_wanilia_lizak2 = sumy_prefiksowe_wanilia_lizak2[p] - sumy_prefiksowe_wanilia_lizak2[l-1];
                        }
                        nadmiar_truskawka_lizak2 = 0;
                        nadmiar_wanilia_lizak2 = 0;
                        if (l != 0)
                        {
                            if (lizak2[l-1].kolor == 'T')
                                nadmiar_truskawka_lizak2 += lizak2[l-1].ile;
                            else
                                nadmiar_wanilia_lizak2 += lizak2[l-1].ile;
                        }
                        if (p != m-1)
                        {
                            if (lizak2[p+1].kolor == 'T')
                                nadmiar_truskawka_lizak2 += lizak2[p+1].ile;
                            else
                                nadmiar_wanilia_lizak2 += lizak2[p+1].ile;
                        }
                        if (suma_truskawka_lizak1 > suma_truskawka_lizak2)
                        {
                            if (suma_truskawka_lizak2 + nadmiar_truskawka_lizak2  < suma_truskawka_lizak1)
                                continue;
                        }
                        else
                        {
                            if (suma_truskawka_lizak1 + nadmiar_truskawka_lizak1 < suma_truskawka_lizak2)
                                continue;
                        }
                        if (suma_wanilia_lizak1 > suma_wanilia_lizak2)
                        {
                            if (suma_wanilia_lizak2 + nadmiar_wanilia_lizak2  < suma_wanilia_lizak1)
                                continue;
                        }
                        else
                        {
                            if (suma_wanilia_lizak1 + nadmiar_wanilia_lizak1 < suma_wanilia_lizak2)
                                continue;
                        }
                        // Mamy pewnosc, ze sie da, tylko pytanie ile
                        wyn = min(suma_truskawka_lizak1 + nadmiar_truskawka_lizak1, suma_truskawka_lizak2 + nadmiar_truskawka_lizak2) + min(suma_wanilia_lizak1 + nadmiar_wanilia_lizak1, suma_wanilia_lizak2 + nadmiar_wanilia_lizak2);
                        max_wyn = max(max_wyn,wyn);
                    }
                }
            }
        }
        // Jeden niepelny przedzial
        int max_truskawka_lizak1 = 0, max_truskawka_lizak2 = 0, max_wanilia_lizak1 = 0, max_wanilia_lizak2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (lizak1[i].kolor == 'T')
                max_truskawka_lizak1 = max(max_truskawka_lizak1,lizak1[i].ile);
            else
                max_wanilia_lizak1 = max(max_wanilia_lizak1,lizak1[i].ile);
        }
        for (int i = 0; i < m; ++i)
        {
            if (lizak2[i].kolor == 'T')
                max_truskawka_lizak2 = max(max_truskawka_lizak2,lizak2[i].ile);
            else
                max_wanilia_lizak2 = max(max_wanilia_lizak2,lizak2[i].ile);
        }
        wyn = max(wyn,min(max_truskawka_lizak1, max_truskawka_lizak2));
        wyn = max(wyn,min(max_wanilia_lizak1, max_wanilia_lizak2));
        // Teraz ten sam algorytm, tylko zakladajac, ze przedzial jest niepelny i dopelnienie to 2 niepelne przedzialy
        for (int i = 0; i < n-1; ++i)
        {
            int ile_truskawka_lizak1 = 0;
            int ile_wanilia_lizak1 = 0;
            if (lizak1[i].kolor == 'T')
            {
                ile_truskawka_lizak1 = lizak1[i].ile;
                ile_wanilia_lizak1 = lizak1[i+1].ile;
            }
            else
            {
                ile_wanilia_lizak1 = lizak1[i].ile;
                ile_truskawka_lizak1 = lizak1[i+1].ile;
            }
            for (int j = 0; j < m-1; ++j)
            {
                int ile_truskawka_lizak2 = 0;
                int ile_wanilia_lizak2 = 0;
                if (lizak2[j].kolor == 'T')
                {
                    ile_truskawka_lizak2 = lizak2[j].ile;
                    ile_wanilia_lizak2 = lizak2[j+1].ile;
                }
                else
                {
                    ile_wanilia_lizak2 = lizak2[j].ile;
                    ile_truskawka_lizak2 = lizak2[j+1].ile;
                }
                wyn = max(wyn,min(ile_truskawka_lizak1,ile_truskawka_lizak2) + min(ile_wanilia_lizak1, ile_wanilia_lizak2));
            }
        }
        printf("%d",max_wyn);
    }
    return 0;
}
