#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n = 0, poczatek = 0, koniec = 0, srodek = 0, sum = 0;
vector<int> wysokosci;
vector<bool> czy_mozna_postawic;
deque<int> Q;

inline bool czy_pasuje(int x)
{
    if (x > n)
        return false;
    Q.clear();
    fill(czy_mozna_postawic.begin(), czy_mozna_postawic.end(), true);
    for (int i = 0; i < x; ++i)
        if (wysokosci[i] <= x)
            Q.push_back(i);
    for (int i = x; i < n; ++i)
    {
        if (!Q.empty())
            czy_mozna_postawic[i] = false;
        if (!Q.empty() and Q.front() == i-x)
            Q.pop_front();
        if (wysokosci[i] <= x)
            Q.push_back(i);
    }

    Q.clear();
    for (int i = n-1; i >= n-x; --i)
        if (wysokosci[i] <= x)
            Q.push_front(i);
    for (int i = n-x-1; i >= 0; --i)
    {
        if (!Q.empty())
            czy_mozna_postawic[i] = false;
        if (!Q.empty() and Q.back() == i+x)
            Q.pop_back();
        if (wysokosci[i] <= x)
            Q.push_front(i);
    }
    for (int i = x; i < n-x; ++i)
        if (czy_mozna_postawic[i] == true and wysokosci[i] >= 2*x+1)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    czy_mozna_postawic.assign(n,false);
    wysokosci.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> wysokosci[i];

    poczatek = 0, koniec = 1e6+20;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }

    cout << poczatek << '\n';

    return 0;
}