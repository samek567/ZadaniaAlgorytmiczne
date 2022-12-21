#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n = 0, wczytany_dol = 0, wczytana_gora = 0, max_wyn = 1, p = 0, k = 0;
vector<int> doly;
vector<int> gory;
deque<int> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_dol >> wczytana_gora;
        doly.push_back(wczytany_dol);
        gory.push_back(wczytana_gora);
    }

    Q.push_front(doly[0]);
    while(true)
    {
        if (p == n-1)
        {
            max_wyn = max(max_wyn,p - k + 1);
            break;
        }
        if (gory[p+1] >= Q.front())
        {
            while (!Q.empty())
            {
                if (doly[p+1] > Q.back())
                    Q.pop_back();
                else
                    break;
            }
            Q.push_back(doly[p+1]);
            p++;
        }
        else
        {
            if (k+1 > p)
            {
                Q.clear();
                p++;
                Q.push_front(doly[p]);
            }
            else
            {
                if (Q.front() == doly[k])
                    Q.pop_front();
            }
            k++;
        }
        max_wyn = max(max_wyn,p - k + 1);
    }

    printf("%d",max_wyn);

    return 0;
}