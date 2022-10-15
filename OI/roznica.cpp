#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int max_wynik = 0;
    char wczytany_znak;
    vector<int> wystapienia[26];
    int znaki[1000001];

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        wystapienia[int(wczytany_znak)-'a'].push_back(i);
    }

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            int leni = wystapienia[i].size();
            int lenj = wystapienia[j].size();

            if (j == i || leni == 0 || lenj == 0)
            {
                continue;
            }

            int len = leni + lenj;

            int wskaznik_i = 0;
            int wskaznik_j = 0;

            for (int f = 0; f < len; ++f)
            {
                if (wskaznik_i >= leni)
                {
                    znaki[f] = -1;
                }
                else if (wskaznik_j >= lenj)
                {
                    znaki[f] = 1;
                }
                else if (wystapienia[i][wskaznik_i] < wystapienia[j][wskaznik_j])
                {
                    znaki[f] = 1;
                    wskaznik_i+=1;
                }
                else
                {
                    znaki[f] = -1;
                    wskaznik_j+=1;
                }
            }

            int h = 0;
            int c_max = 0;
            int c_min = 0;
            int t_wynik = 0;
            bool jest_spadek = false;

            for (int k = 0; k < len; ++k)
            {
                if (znaki[k] == 1)
                {
                    h++;
                    if (jest_spadek)
                    {
                        c_max = max(c_max,h);
                    }
                    else
                    {
                        c_max = max(c_max,h-1);
                    }
                }
                else
                {
                    jest_spadek = true;
                    h--;
                    if (h < c_min) // reset mina
                    {
                        t_wynik = max(t_wynik,c_max-c_min);
                        c_min = h;
                        c_max = h;
                        jest_spadek = false;
                    }
                }
            }
            t_wynik = max(t_wynik,c_max-c_min);

            max_wynik = max(max_wynik,t_wynik);
        }
    }

    printf("%d",max_wynik);
    return 0;
}