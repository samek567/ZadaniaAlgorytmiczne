#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct Element
{
    int suma;
    int maska;
    bool operator < (const Element &element) const
    {
        return suma < element.suma;
    }
};

int n = 0, S = 0, N = 0;
string wyn;
vector<int> liczby;
vector<Element> A;
vector<Element> B;

inline string convert_to_binary(int x, int ile)
{
    string res;
    for (int j = 0; j < ile; ++j)
    {
        auto b = (1 << j) & x;
        if (b)
            res += '1';
        else
            res += '0';
    }
    return res;
}

int main()
{
    // Meet in the middle z binary searchem, mozna zamiast binary searcha gasienice.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];
    cin >> S;
    N = n;

    int val = n/2;
    A.assign((1 << val),{});
    for (int i = 0; i < (1 << val); ++i)
    {
        int sum = 0;
        for (int j = 0; j < val; ++j)
        {
            auto b = (1 << j) & i;
            if (b)
                sum += liczby[j];
        }
        A[i] = {sum,i};
    }

    n -= n/2;
    if (n > 0)
    {
        val = n;
        B.assign((1 << val),{});
        for (int i = 0; i < (1 << val); ++i)
        {
            int sum = 0;
            for (int j = 0; j < val; ++j)
            {
                auto b = (1 << j) & i;
                if (b)
                    sum += liczby[j+N/2];
            }
            B[i] = {sum,i};
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i].suma > S)
            break;
        else if (A[i].suma == S)
        {
            wyn = convert_to_binary(A[i].maska,N/2);
            break;
        }
    }
    for (int i = 0; i < B.size(); ++i)
    {
        if (B[i].suma > S)
            break;
        else if (B[i].suma == S)
        {
            wyn = convert_to_binary(B[i].maska,n);
            break;
        }
    }

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i].suma > S)
            break;
        int poczatek = -1, koniec = B.size(), srodek = 0;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (B[srodek].suma <= S - A[i].suma)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (poczatek == -1)
            continue;
        if (B[poczatek].suma == S - A[i].suma)
        {
            wyn = convert_to_binary(A[i].maska,N/2) + convert_to_binary(B[poczatek].maska,n);
            break;
        }
    }

    cout << wyn << '\n';

    return 0;
}
