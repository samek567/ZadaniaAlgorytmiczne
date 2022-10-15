#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<long long> deski;
    long long max_bok = 0;
    int n = 0;
    long long aktualna_liczba = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aktualna_liczba;
        deski.push_back(aktualna_liczba);
    }

    sort(deski.begin(),deski.end());

    if (n >= 1)
    {
        max_bok = deski[n-1] / 4;
    }

    if (n >= 2)
    {
        if (deski[n-2] > max_bok && deski[n-1] / 3 > max_bok)
        {
            // Sprawdzamy co mniejsze
            if (deski[n-1] / 3 < deski[n-2])
            {
                max_bok = deski[n-1] / 3;
            }
            else
            {
                max_bok = deski[n-2];
            }
        }
        if (deski[n-1] / 2 > max_bok && deski[n-2] / 2 > max_bok)
        {
            // wiadomo ze deski od n-2 / 2 sa mniejsze od deski od n-1 / 2
            max_bok = deski[n-2] / 2;
        }
    }

    if (n >= 3)
    {
        if (deski[n-1] / 2 > max_bok && deski[n-2] > max_bok && deski[n-3] > max_bok)
        {
            if (deski[n-1] / 2 < deski[n-3])
            {
                max_bok = deski[n-1] / 2;
            }
            else
            {
                max_bok = deski[n-3];
            }
        }
    }

    if (n >= 4)
    {
        if (deski[n-4] > max_bok)
        {
            // Wiemy ze najmniejsze jest n-4 wiec nie musimy sprawdzac
            max_bok = deski[n-4];
        }
    }

    printf("%lld",max_bok * max_bok);
    return 0;
}