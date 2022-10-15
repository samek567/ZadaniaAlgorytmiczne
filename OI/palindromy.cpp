#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Element
{
    int ostatni_idx;
    vector<string> czesci;

    bool operator < (const Element&element) const
    {
        return ostatni_idx < element.ostatni_idx;
    }
    bool operator == (const Element&element) const
    {
        return ostatni_idx == element.ostatni_idx;
    }
};

bool czy_palindrom (string &ciag)
{
    int p = 0;
    int k = ciag.size()-1;

    while (k >= p)
    {
        if (ciag[p] != ciag[k])
        {
            return false;
        }
        p++;
        k--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ciag;

    cin >> ciag;
    vector<pair<string,int>> palindromy[ciag.size()];
    queue<Element>Q;
    vector<string> max_wynik;
    vector<string> min_wynik;

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (i % 2 != 0)
        {
            continue;
        }
        string prefix;
        for (int j = i; j < ciag.size(); ++j)
        {
            prefix += ciag[j];
            if (prefix.size() % 2 == 0)
            {
                if (czy_palindrom(prefix) == true)
                {
                    palindromy[i].push_back({prefix,j});
                }
            }
        }
    }

    // MIN
    Q.push({-1,{}});
    bool czy_bylismy[ciag.size()] {false};
    if (ciag.size()== 1)
    {
        cout << "NIE";
        return 0;
    }
    while (!Q.empty())
    {
        if (Q.front().ostatni_idx == ciag.size()-1)
        {
            int opcja = Q.front().czesci.size();
            if (opcja < min_wynik.size() || min_wynik.size() == 0)
            {
                min_wynik = Q.front().czesci;
            }
            break;
        }
        else
        {
            for (int i = 0; i < palindromy[Q.front().ostatni_idx+1].size(); ++i)
            {
                if (czy_bylismy[palindromy[Q.front().ostatni_idx+1][i].second] == false)
                {
                    czy_bylismy[palindromy[Q.front().ostatni_idx+1][i].second] = true;
                    Q.push({palindromy[Q.front().ostatni_idx+1][i].second,Q.front().czesci});
                    Q.back().czesci.push_back(palindromy[Q.front().ostatni_idx+1][i].first);
                }
            }
        }
        Q.pop();
    }


    // MAX
    set<Element> elementy {{-1,{}}};
    while (!elementy.empty())
    {
        Element sprawdzany;
        for (auto c : elementy)
        {
            sprawdzany = c;
            break;
        }
        if (sprawdzany.ostatni_idx == ciag.size()-1)
        {
            int opcja = sprawdzany.czesci.size();
            if (opcja > max_wynik.size() || max_wynik.size() == 0)
            {
                max_wynik = sprawdzany.czesci;
            }
        }
        else
        {
            for (int i = 0; i < palindromy[sprawdzany.ostatni_idx+1].size(); ++i)
            {
                int szukany = palindromy[sprawdzany.ostatni_idx+1][i].second;
                auto it = elementy.find({szukany});
                if (it != elementy.end()) // Znalezlismy
                {

                    if (sprawdzany.czesci.size()+1 > it->czesci.size())
                    {
                        elementy.erase(it);
                        vector<string> Vect;
                        Vect = sprawdzany.czesci;
                        Vect.push_back(palindromy[sprawdzany.ostatni_idx+1][i].first);
                        elementy.insert({palindromy[sprawdzany.ostatni_idx+1][i].second,Vect});
                    }

                }
                else
                {
                    vector<string> Vect;
                    Vect = sprawdzany.czesci;
                    Vect.push_back(palindromy[sprawdzany.ostatni_idx+1][i].first);
                    elementy.insert({palindromy[sprawdzany.ostatni_idx+1][i].second,Vect});
                }
            }
        }
        elementy.erase({sprawdzany.ostatni_idx});
    }

    if (max_wynik.size() == 0 || min_wynik.size() == 0)
    {
        cout << "NIE";
    }
    else
    {
        for (int i = 0; i < min_wynik.size(); ++i)
        {
            cout << min_wynik[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < max_wynik.size(); ++i)
        {
            cout << max_wynik[i] << " ";
        }
    }

    return 0;
}