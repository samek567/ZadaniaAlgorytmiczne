#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Element
{
    int wysokosc;
    int szerokosc;
};

int n = 0, wyn = 0;
char wczytany_znak;
vector<vector<bool>> dzialka;
vector<vector<int>> stat;
stack<Element> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        dzialka.push_back({});
        stat.push_back({});
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytany_znak;
            if (wczytany_znak == '0')
                dzialka[i].push_back(true);
            else
                dzialka[i].push_back(false);
            stat[i].push_back(0);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (dzialka[j][i] == true)
                sum++;
            else
                sum = 0;
            stat[j][i] = sum;
        }
    }

    // Odpalamy algorytm histogramowy z SPOJ-a dla kazdego wiersza
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (S.empty())
                S.push({stat[i][j],1});
            else if (stat[i][j] == S.top().wysokosc)
                S.top().szerokosc++;
            else if (stat[i][j] > S.top().wysokosc)
                S.push({stat[i][j],1});
            else
            {
                int szerokosc_suma = 0;
                while (!S.empty())
                {
                    if (stat[i][j] > S.top().wysokosc)
                        break;
                    szerokosc_suma += S.top().szerokosc;
                    wyn = max(wyn, S.top().wysokosc * szerokosc_suma);
                    S.pop();
                }
                if (stat[i][j] != 0)
                    S.push({stat[i][j],szerokosc_suma+1});
            }
        }
        int szerokosc_suma = 0;
        while (!S.empty())
        {
            szerokosc_suma += S.top().szerokosc;
            wyn = max(wyn, S.top().wysokosc * szerokosc_suma);
            S.pop();
        }
    }

    printf("%d",wyn);

    return 0;
}