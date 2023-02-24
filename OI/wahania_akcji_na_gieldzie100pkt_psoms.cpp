#include <iostream>
#include <vector>

using namespace std;

int  wyn = 0, KTR = 1;
const int SIZE = 1e6+5;
string ciag;
vector<int> operacje;
int bilans[SIZE] = {0}; // aktualny bilans dla i-tej akcji
int t_min[SIZE] = {0}; // Najnizszy dolek dla i-tej akcji
vector<int> wsk; // Wskazniki, ktore akcje sa na danych idx-ach
vector<int> dod; // Jakie beda akcje po zamienieniu w i-tym dniu (to co damy na wsk)

inline void przetwarzaj() // Funkcja ktora ciag wczytany w getlini-ie, tnie na inty i dodaje do vectora operacje.
{
    string spr;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == ' ')
        {
            if (!spr.empty())
                operacje.push_back(stoi(spr));
            spr.clear();
        }
        else
            spr += ciag[i];
    }
    if (!spr.empty())
        operacje.push_back(stoi(spr));
}

int main()
{
    // Problem Psoms. Wynik dla kazdej akcji do max_gora - min_dolek.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(getline(cin,ciag))
    {
        operacje.clear();
        przetwarzaj();
        dod.clear();
        while(wsk.size() < operacje.size())
        {
            wsk.push_back(KTR);
            KTR++;
        }
        for (int i = 0; i < operacje.size(); ++i)
        {
            if (operacje[i] == -99)
            {
                bilans[wsk[i]] = 0;
                t_min[wsk[i]] = 0;
            }
            else
            {
                bilans[wsk[i]] += operacje[i];
                t_min[wsk[i]] = min(t_min[wsk[i]],bilans[wsk[i]]);
                wyn = max(wyn, bilans[wsk[i]] - t_min[wsk[i]]);
                dod.push_back(wsk[i]);
            }
        }
        wsk = dod;
        vector<int> miny;
        vector<int> bilanse;
        for (int i = 0; i < wsk.size(); ++i)
        {
            miny.push_back(t_min[wsk[i]]);
            bilanse.push_back(bilans[wsk[i]]);
            bilans[wsk[i]] = 0;
            t_min[wsk[i]] = 0;
        }
        for (int i = 0; i < wsk.size(); ++i)
        {
            wsk[i] = i+1;
            bilans[i+1] = bilanse[i];
            t_min[i+1] = miny[i];
        }
        KTR = wsk.size()+1;
    }

    cout << wyn << '\n';

    return 0;
}