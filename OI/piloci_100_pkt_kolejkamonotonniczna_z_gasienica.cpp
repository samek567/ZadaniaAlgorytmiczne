#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n = 0, p = 0, k = 0, max_wyn = 1;
long long t = 0, a_i = 0;
deque<long long> Q_max;
deque<long long> Q_min;
vector<long long> liczby;

int main()
{
    // Zadanie Piloci z finału XVII OI, Kolejka monotonniczna z gąsienicą.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a_i;
        liczby.push_back(a_i);
    }
    Q_min.push_front(liczby[0]);
    Q_max.push_front(liczby[0]);

    while (p < n-1)
    {
        if (abs(Q_min.front() - liczby[p+1]) <= t && abs(Q_max.front() - liczby[p+1]) <= t)
        {
            // Przesuwamy poczatek.
            p++;
            max_wyn = max(max_wyn,p - k + 1);
            while (!Q_min.empty())
            {
                if (Q_min.back() > liczby[p])
                {
                    Q_min.pop_back();
                }
                else
                {
                    break;
                }
            }
            Q_min.push_back(liczby[p]);

            while (!Q_max.empty())
            {
                if (Q_max.back() < liczby[p])
                {
                    Q_max.pop_back();
                }
                else
                {
                    break;
                }
            }
            Q_max.push_back(liczby[p]);
        }
        else
        {
            // Przesuwamy koniec.
            k++;
            if (k > p)
            {
                p = k;
                Q_min.clear();
                Q_min.push_front(liczby[p]);

                Q_max.clear();
                Q_max.push_front(liczby[p]);
            }
            else
            {
                if (Q_min.front() == liczby[k-1])
                {
                    Q_min.pop_front();
                }
                if (Q_max.front() == liczby[k-1])
                {
                    Q_max.pop_front();
                }
            }
        }
    }

    cout << max_wyn << '\n';

    return 0;
}
