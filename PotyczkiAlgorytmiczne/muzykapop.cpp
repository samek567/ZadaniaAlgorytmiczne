#include <iostream>
#include <vector>

using namespace std;

int n = 0, suma = 0;
vector<int> najdalszy_idx;

string convert_to_binary(int x)
{
    int ile_elementow = 1;
    int iloczyn = 1;
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
    // Korzystamy z obserwacji ze roznych wartosci moze byc co najwyzej logarytm.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1)
    {
        printf("1 \n1");
        return 0;
    }
    if (n == 2)
    {
        printf("2 \n2 1");
        return 0;
    }
    najdalszy_idx.assign(25,-1);
    for (int i = 1; i <= n; ++i)
    {
        int ile_zapalonych_bitow = count_possitive_bit(convert_to_binary(i));
        najdalszy_idx[ile_zapalonych_bitow] = i;
        suma += ile_zapalonych_bitow;
        int szukana_liczba = suma - n;
        if (szukana_liczba >= 0)
        {
            if (najdalszy_idx[szukana_liczba] != -1)
            {
                printf("%d \n",i-1);
                for (int j = i; j >= 1; --j)
                {
                    if (j != najdalszy_idx[szukana_liczba])
                    {
                        printf("%d ",j);
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}