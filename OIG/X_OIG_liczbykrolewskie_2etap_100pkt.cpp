#include <iostream>

using namespace std;

int t = 0;
long long k = 0;

string convert_to_binary(long long x)
{
    int ile_elementow = 1;
    long long iloczyn = 1;
    string wyn;
    while(iloczyn * 2 <= x)
    {
        ile_elementow++;
        iloczyn *= 2;
    }

    for (int i = 0; i < ile_elementow; ++i)
    {
        wyn += '0';
    }
    while(x > 0)
    {
        if (x >= iloczyn)
        {
            x -= iloczyn;
            wyn[ile_elementow-1] = '1';
        }
        ile_elementow--;
        iloczyn /= 2;
    }

    return wyn;
}

int count_possitive_bit(string x)
{
    int licznik = 0;
    for (int i = 0; i < x.size(); ++i)
    {
        if (x[i] == '1')
        {
            licznik++;
        }
    }
    return licznik;
}

int main()
{
    // O(T * log n), bo bitow mozemy miec maksymalnie logarytmicznie wiele.
    // Mozna bez funkcji cout_positive_bit tylko zamknac to w 1 funkcje.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> k;
        if (count_possitive_bit(convert_to_binary(2*k-1)) % 2 == 0)
        {
            printf("%lld \n", 2*k-1);
        }
        else
        {
            printf("%lld \n", 2*k-2);
        }
    }

    return 0;
}