#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <cmath>

using namespace std;

map<string,int> liczby;
map<string,string> dopelnienia; // Musi byc string bo 00000 on traktuje jako 0.

map<string,int> wagi;

void uzupelniaj ()
{
    liczby.insert({"jeden",1});
    liczby.insert({"dwa",2});
    liczby.insert({"trzy",3});
    liczby.insert({"cztery",4});
    liczby.insert({"piec",5});
    liczby.insert({"szesc",6});
    liczby.insert({"siedem",7});
    liczby.insert({"osiem",8});
    liczby.insert({"dziewiec",9});

    wagi.insert({"jeden",1});
    wagi.insert({"dwa",1});
    wagi.insert({"trzy",1});
    wagi.insert({"cztery",1});
    wagi.insert({"piec",1});
    wagi.insert({"szesc",1});
    wagi.insert({"siedem",1});
    wagi.insert({"osiem",1});
    wagi.insert({"dziewiec",1});

    liczby.insert({"dziesiec",10});
    liczby.insert({"jedenascie",11});
    liczby.insert({"dwanascie",12});
    liczby.insert({"trzynascie",13});
    liczby.insert({"czternascie",14});
    liczby.insert({"pietnascie",15});
    liczby.insert({"szesnascie",16});
    liczby.insert({"siedemnascie",17});
    liczby.insert({"osiemnascie",18});
    liczby.insert({"dziewietnascie",19});

    // Traktujemy jako wage 1, ale bedziemy sprawdzac czy mamy na stosie 2. Jak tak to blad.
    wagi.insert({"dziesiec",1});
    wagi.insert({"jedenascie",1});
    wagi.insert({"dwanascie",1});
    wagi.insert({"trzynascie",1});
    wagi.insert({"czternascie",1});
    wagi.insert({"pietnascie",1});
    wagi.insert({"szesnascie",1});
    wagi.insert({"siedemnascie",1});
    wagi.insert({"osiemnascie",1});
    wagi.insert({"dziewietnascie",1});

    liczby.insert({"dwadziescia",20});
    liczby.insert({"trzydziesci",30});
    liczby.insert({"czterdziesci",40});
    liczby.insert({"piecdziesiat",50});
    liczby.insert({"szescdziesiat",60});
    liczby.insert({"siedemdziesiat",70});
    liczby.insert({"osiemdziesiat",80});
    liczby.insert({"dziewiecdziesiat",90});

    wagi.insert({"dwadziescia",2});
    wagi.insert({"trzydziesci",2});
    wagi.insert({"czterdziesci",2});
    wagi.insert({"piecdziesiat",2});
    wagi.insert({"szescdziesiat",2});
    wagi.insert({"siedemdziesiat",2});
    wagi.insert({"osiemdziesiat",2});
    wagi.insert({"dziewiecdziesiat",2});

    liczby.insert({"sto",100});
    liczby.insert({"dwiescie",200});
    liczby.insert({"trzysta",300});
    liczby.insert({"czterysta",400});
    liczby.insert({"piecset",500});
    liczby.insert({"szescset",600,});
    liczby.insert({"siedemset",700});
    liczby.insert({"osiemset",800});
    liczby.insert({"dziewiecset",900});

    wagi.insert({"sto",3});
    wagi.insert({"dwiescie",3});
    wagi.insert({"trzysta",3});
    wagi.insert({"czterysta",3});
    wagi.insert({"piecset",3});
    wagi.insert({"szescset",3,});
    wagi.insert({"siedemset",3});
    wagi.insert({"osiemset",3});
    wagi.insert({"dziewiecset",3});

    dopelnienia.insert({"tysiac","000"});
    dopelnienia.insert({"tysiace","000"});
    dopelnienia.insert({"tysiecy","000"});
    wagi.insert({"tysiac",4});
    wagi.insert({"tysiace",4});
    wagi.insert({"tysiecy",4});

    dopelnienia.insert({"milion","000000"});
    dopelnienia.insert({"miliony","000000"});
    dopelnienia.insert({"milionow","000000"});
    wagi.insert({"milion",5});
    wagi.insert({"miliony",5});
    wagi.insert({"milionow",5});

    dopelnienia.insert({"miliard","000000000"});
    wagi.insert({"miliard",6});
}

bool czy_dobrze_zakonczenia (string slowo, stack<pair<int,string>>zagniezdzenie)
{
    if (zagniezdzenie.size() == 1)
    {
        if (zagniezdzenie.top().second == "jeden" )
        {
            if (slowo == "tysiac" || slowo == "milion" || slowo == "miliard")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (slowo == "tysiac" || slowo == "milion" || slowo == "miliard")
    {
        if (zagniezdzenie.top().second == "jeden" && zagniezdzenie.size() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (slowo == "tysiace" || slowo == "miliony")
    {
        if (zagniezdzenie.top().second == "dwa" || zagniezdzenie.top().second == "trzy" || zagniezdzenie.top().second == "cztery")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (slowo == "tysiecy" || slowo == "milionow")
    {
        if (zagniezdzenie.top().second == "dwa" || zagniezdzenie.top().second == "trzy" || zagniezdzenie.top().second == "cztery")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ciag;
    string prefix;
    vector<string> slowa;
    long long wynik = 0;
    long long akt_wynik = 0;

    uzupelniaj();

    getline(cin,ciag);

    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == ' ')
        {
            slowa.push_back(prefix);
            prefix.clear();
        }
        else
        {
            prefix += ciag[i];
        }
    }
    if (!prefix.empty())
    {
        slowa.push_back(prefix);
    }

    int licznik_prefix = 0;
    stack<pair<int,string>> zagniezdzenie; // stopien zagniezdzenia,liczba.
    vector<int> wagi_dopelnien;
    for (int i = 0; i < slowa.size(); ++i)
    {
        if (auto it = liczby.find(slowa[i]) != liczby.end()) // Znalezlismy
        {
            licznik_prefix++;
            if (zagniezdzenie.empty())
            {
                zagniezdzenie.push({wagi[slowa[i]],slowa[i]});
            }
            else
            {
                if (wagi[slowa[i]] < zagniezdzenie.top().first)
                {
                    if (slowa[i] == "dziesiec" || slowa[i] == "jedenascie" || slowa[i] == "dwanascie" || slowa[i] == "trzynascie" || slowa[i] == "czternascie" || slowa[i] == "pietnascie" || slowa[i] == "szesnascie" || slowa[i] == "siedemnascie" || slowa[i] == "osiemnascie" || slowa[i] == "dziewietnascie")
                    {
                        if (zagniezdzenie.top().first == 2)
                        {
                            cout << "NIE";
                            return 0;
                        }
                    }
                    zagniezdzenie.push({wagi[slowa[i]],slowa[i]});
                }
                else
                {
                    cout << "NIE";
                    return 0;
                }
            }
            akt_wynik += liczby[slowa[i]];
        }

        else // Nie znalezlismy
        {
            // Tutaj zdejmujemy elementy z stosu - laczymy w jeden poziom
            if (auto it = dopelnienia.find(slowa[i]) != dopelnienia.end())
            {
                if (zagniezdzenie.empty())
                {
                    cout << "NIE";
                    return 0;
                }
                else
                {
                    for (int j = 0; j < wagi_dopelnien.size(); ++j)
                    {
                        if (wagi_dopelnien[j] == wagi[slowa[i]] || wagi_dopelnien[j] < wagi[slowa[i]])
                        {
                            cout << "NIE";
                            return 0;
                        }
                    }
                    wagi_dopelnien.push_back(wagi[slowa[i]]);

                    if (czy_dobrze_zakonczenia(slowa[i],zagniezdzenie) == false)
                    {
                        cout << "NIE";
                        return 0;
                    }

                    for (int j = 0; j < licznik_prefix; ++j)
                    {
                        zagniezdzenie.pop();
                    }
                    licznik_prefix = 0;
                }

                string ciag_wyn = to_string(akt_wynik) + dopelnienia[slowa[i]];
                akt_wynik = stoll(ciag_wyn);
                wynik += akt_wynik;
                akt_wynik = 0;
            }
            else
            {
                cout << "NIE";
                return 0;
            }
        }
    }

    wynik += akt_wynik;
    if (wynik <= pow(10,9))
    {
        cout << wynik;
    }
    else
    {
        cout << "NIE";
    }
    return 0;
}