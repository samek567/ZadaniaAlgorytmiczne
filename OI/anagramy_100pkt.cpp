#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Element_vectora
{
    string ciag;
    int numer_grupy;

    bool operator < (const Element_vectora & element_vectora) const
    {
        if (ciag == element_vectora.ciag)
        {
            return numer_grupy > element_vectora.numer_grupy;
        }
        return ciag < element_vectora.ciag;
    }
};

int n = 0;
string wczytany_ciag;
map<vector<int>,vector<string>> stat;
vector<vector<string>> podzielone_na_grupy;
vector<Element_vectora> sprawdzanie;
set<string> ciagi_bez_powtorzen;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_ciag;
        ciagi_bez_powtorzen.insert(wczytany_ciag);
    }

    for (auto i : ciagi_bez_powtorzen)
    {
        vector<int> wystapienia;
        for (char j = 'a'; j <= 'z'; ++j)
        {
            wystapienia.push_back(0);
        }
        for (int j = 0; j < i.size(); ++j)
        {
            wystapienia[(int) i[j] - 97]++;
        }

        if (auto it = stat.find(wystapienia) != stat.end()) // Znalezlismy
        {
            stat[wystapienia].push_back(i);
        }
        else
        {
            stat.insert({wystapienia, {i}});
        }
    }

    int licznik = 0;
    for (auto i: stat)
    {
        podzielone_na_grupy.push_back({});
        for (int j = 0; j < i.second.size(); ++j)
        {
            podzielone_na_grupy[licznik].push_back(i.second[j]);
        }
        licznik++;
    }

    for (int i = 0; i < podzielone_na_grupy.size(); ++i)
    {
        sort(podzielone_na_grupy[i].begin(),podzielone_na_grupy[i].end());
    }

    for (int i = 0; i < podzielone_na_grupy.size(); ++i)
    {
        sprawdzanie.push_back({podzielone_na_grupy[i][0],i});
    }
    sort(sprawdzanie.begin(),sprawdzanie.end());

    for (int i = 0; i < sprawdzanie.size(); ++i)
    {
        for (int j = 0; j < podzielone_na_grupy[sprawdzanie[i].numer_grupy].size(); ++j)
        {
            printf("%s ", podzielone_na_grupy[sprawdzanie[i].numer_grupy][j].c_str());
        }
        printf("\n");
    }

    return 0;
}
