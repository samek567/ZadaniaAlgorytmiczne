#include <iostream>
#include <stack>

using namespace std;

struct nawias
{
    int jaki_nawias;
    int stopien_zagniezdzenia;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int max_zagniezdzenie = 0;
    string ciag;
    stack<nawias> nawiasy_otwarte;

    cin >> n >> ciag;

    for (int i = 0; i < n; i++)
    {
        // ( - rodzaj 0, { - rodzaj 1, [ - rodzaj 2
        if (ciag[i] == '{')
        {
            if (nawiasy_otwarte.empty())
            {
                nawiasy_otwarte.push({1,1});
            }
            else
            {
                nawiasy_otwarte.push({1,nawiasy_otwarte.top().stopien_zagniezdzenia+1});
            }
            if (nawiasy_otwarte.top().stopien_zagniezdzenia > max_zagniezdzenie)
            {
                max_zagniezdzenie = nawiasy_otwarte.top().stopien_zagniezdzenia;
            }
        }
        else if (ciag[i] == '[')
        {
            if (nawiasy_otwarte.empty())
            {
                nawiasy_otwarte.push({2,1});
            }
            else
            {
                nawiasy_otwarte.push({2,nawiasy_otwarte.top().stopien_zagniezdzenia+1});
            }
            if (nawiasy_otwarte.top().stopien_zagniezdzenia > max_zagniezdzenie)
            {
                max_zagniezdzenie = nawiasy_otwarte.top().stopien_zagniezdzenia;
            }
        }
        else if (ciag[i] == '(')
        {
            if (nawiasy_otwarte.empty())
            {
                nawiasy_otwarte.push({0,1});
            }
            else
            {
                nawiasy_otwarte.push({0,nawiasy_otwarte.top().stopien_zagniezdzenia+1});
            }
            if (nawiasy_otwarte.top().stopien_zagniezdzenia > max_zagniezdzenie)
            {
                max_zagniezdzenie = nawiasy_otwarte.top().stopien_zagniezdzenia;
            }
        }
        else if (ciag[i] == ')')
        {
            if (nawiasy_otwarte.empty())
            {
                cout << "NIE";
                return 0;
            }
            else
            {
                if (nawiasy_otwarte.top().jaki_nawias == 0)
                {
                    // OK
                    nawiasy_otwarte.pop();
                }
                else
                {
                    cout << "NIE";
                    return 0;
                }
            }
        }
        else if (ciag[i] == ']')
        {
            if (nawiasy_otwarte.empty())
            {
                cout << "NIE";
                return 0;
            }
            else
            {
                if (nawiasy_otwarte.top().jaki_nawias == 2)
                {
                    // OK
                    nawiasy_otwarte.pop();
                }
                else
                {
                    cout << "NIE";
                    return 0;
                }
            }
        }
        else if (ciag[i] == '}')
        {
            if (nawiasy_otwarte.empty())
            {
                cout << "NIE";
                return 0;
            }
            else
            {
                if (nawiasy_otwarte.top().jaki_nawias == 1)
                {
                    // OK
                    nawiasy_otwarte.pop();
                }
                else
                {
                    cout << "NIE";
                    return 0;
                }
            }
        }
    }

    if (!nawiasy_otwarte.empty())
    {
        cout << "NIE";
    }
    else
    {
        cout << max_zagniezdzenie;
    }
    return 0;
}