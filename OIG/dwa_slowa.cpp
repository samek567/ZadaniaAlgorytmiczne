#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    string ciag1;
    string ciag2;
    long long liczba_zapytan = 0;
    long long idx1 = 0;
    long long idx2 = 1;
    set<int> roznice;
    char bufor;

    cin >> n >> ciag1 >> ciag2 >> liczba_zapytan;

    for (int i = 0; i < n; i++)
    {
        if (ciag1[i] != ciag2[i])
        {
            roznice.insert(i);
        }
    }


    for (int i = 0; i < liczba_zapytan; i++)
    {
        cin >> idx1 >> idx2;

        bufor = ciag1[idx1];
        ciag1[idx1] = ciag2[idx2];
        ciag2[idx2] = bufor;

        if (ciag1[idx1] != ciag2[idx1])
        {
            roznice.insert(idx1);
        }
        else
        {
            auto it = roznice.find (idx1);
            if (it != roznice.end())
            {
                roznice.erase (it);
            }
        }

        if (ciag1[idx2] != ciag2[idx2])
        {
            roznice.insert(idx2);
        }
        else
        {
            auto it = roznice.find (idx2);
            if (it != roznice.end())
            {
                roznice.erase (it);
            }
        }

        if (roznice.empty())
        {
            cout << 0 << endl;
        }
        else
        {
            auto it = roznice.begin();
            int idx = *it;
            if (ciag1[idx] > ciag2[idx])
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }

    }

    return 0;
}