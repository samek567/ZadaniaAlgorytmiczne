#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

struct Element
{
    unsigned long long iloczyn;
    vector<unsigned long long> liczba_klockow;

    bool operator < (const Element&element) const
    {
        return iloczyn > element.iloczyn;
    }
    bool operator == (const Element&element) const
    {
        return iloczyn == element.iloczyn;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n = 0;
    unsigned long long t = 0;
    unsigned long long wczytana_liczba = 0;
    unsigned long long min_iloczyn = ULLONG_MAX;
    vector<unsigned long long> klocki;
    set<Element> kombinacje;

    cin >> n >> t;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        if (t % wczytana_liczba != 0)
        {
            continue;
        }
        if (wczytana_liczba == t)
        {
            cout << "1" << endl << wczytana_liczba;
            return 0;
        }
        min_iloczyn = min(min_iloczyn,wczytana_liczba);
        klocki.push_back(wczytana_liczba);
    }

    if (min_iloczyn > t)
    {
        cout << "NIE";
        return 0;
    }

    for (int i = 0; i < klocki.size(); ++i)
    {
        for (auto j : kombinacje)
        {
            if (j.iloczyn*klocki[i] > t || t % (j.iloczyn*klocki[i]) != 0)
            {
                continue;
            }
            auto it = kombinacje.find({j.iloczyn*klocki[i]});
            vector<unsigned long long> vect = j.liczba_klockow;
            vect.push_back(klocki[i]);
            if (it != kombinacje.end()) // Znalezlismy
            {
                if (j.liczba_klockow.size()+1 < it->liczba_klockow.size())
                {
                    kombinacje.erase({j.iloczyn*klocki[i]});
                    kombinacje.insert({j.iloczyn*klocki[i],vect});
                }
            }
            else
            {
                kombinacje.insert({j.iloczyn*klocki[i],vect});
            }
        }
        if (auto it = kombinacje.find({klocki[i]}) != kombinacje.end()) // Znalezlismy
        {
            kombinacje.erase({klocki[i]});
            kombinacje.insert({klocki[i],{klocki[i]}});
        }
        else
        {
            kombinacje.insert({klocki[i],{klocki[i]}});
        }
    }

    auto it = kombinacje.find({t});
    if (it != kombinacje.end())
    {
        cout << it->liczba_klockow.size() << endl;
        for (int i = 0; i < it->liczba_klockow.size(); ++i)
        {
            cout << it->liczba_klockow[i] << " ";
        }
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}