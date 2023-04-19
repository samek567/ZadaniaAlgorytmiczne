#include <iostream>
#include <vector>

using namespace std;

struct Element
{
    int wartosc;
    int idx;
};

int n = 0, k = 0, ile_w_turze = 0, cnt = 0, sum = 0;
string ciag;
char wczytany_znak;
vector<Element> S;
vector<vector<int>> wyn;

int main()
{
    /* O(N), zachlan na stosie. Ciagle bierzemy, chyba, ze nie mozemy, to usuwamy i dalej bierzemy.
    // Sprytny trik, ze odtwarzamy od konca, fajny opis w ksiazeczce OI.
    // Mozna tez drzewo przedzialowe przedzial - przedzial min-ow
       z binary searchem, ale to O(N * lg N * lg N), wiec raczej nie przejdzie na 100pkt. */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> ciag;
    ile_w_turze = k + 1;

    wyn.assign(n / ile_w_turze, {});

    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == 'b')
            sum = 1;
        else
            sum = -k;
        if (S.empty())
            S.push_back({sum,i});
        else
            S.push_back({S[S.size()-1].wartosc + sum,i});
        if (S.size() >= ile_w_turze)
        {
            int val = 0;
            if (S.size() != ile_w_turze)
                val = S[S.size()-ile_w_turze-1].wartosc;
            if (S[S.size()-1].wartosc - val == 0)
            {
                for (int j = S.size()-ile_w_turze; j < S.size(); ++j)
                    wyn[cnt].push_back(S[j].idx + 1);
                cnt++;
                for (int j = 0; j < ile_w_turze; ++j)
                    S.pop_back();
            }
        }
    }

    for (int i = n / ile_w_turze - 1; i >= 0; --i)
    {
        for (int j = 0; j < ile_w_turze; ++j)
            cout << wyn[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
