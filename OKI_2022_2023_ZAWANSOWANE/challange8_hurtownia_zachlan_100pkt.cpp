#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

struct Element
{
    int wartosc;
    int idx;
    bool operator < (const Element &element) const
    {
        if (wartosc == element.wartosc)
            return idx < element.idx;
        return wartosc < element.wartosc;
    }
};

int n = 0;
ll suma = 0;
vector<int> A;
vector<int> B;
set<Element> S;
vector<bool> czy_jest;

int main()
{
    // O(N lg N), zachlan na secie, mozna tez na kolejce priorytetowej.
    // Ciagle bierzemy, chyba ze nie mozemy to usuwamy i potencjalnie bierzemy dalej.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    A.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    B.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    for (int i = 0; i < n; ++i)
    {
        suma += A[i];
        if (suma >= B[i])
        {
            suma -= B[i];
            S.insert({B[i],i});
        }
        else
        {
            if (!S.empty())
            {
                if (S.rbegin()->wartosc > B[i])
                {
                    suma += S.rbegin()->wartosc;
                    S.erase(*S.rbegin());
                    S.insert({B[i],i});
                    suma -= B[i];
                }
            }
        }
    }

    cout << S.size() << '\n';

    czy_jest.assign(n+1,false);
    for (auto it = S.begin(); it != S.end(); ++it)
        czy_jest[it->idx+1] = true;

    for (int i = 1; i <= n; ++i)
        if (czy_jest[i] == true)
            cout << i << ' ';

    return 0;
}