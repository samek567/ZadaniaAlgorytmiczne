#include <iostream>
#include <vector>

using namespace std;

int n, wskI = 0, wskJ = 0, wyn = 0, bilans = 0, t_min = 0, t_max = 0, idx_min = 0, idx_max = 0;
bool czy_jest_I = false, czy_jest_J = false;
string ciag;
vector<int> stat[26]; // Tyle jest liter w alfabecie od a - z.
vector<char> znaki;

int main()
{
    // O(A*N), gdzie A, to rozmiar alfabetu.
    /* Zauwazmy, ze gdyby nie bylo ograniczenia, ze musi byc przynajmniej jedna litera i oraz jedna litera j, tylko wystarczalaby,
     tylko jedna z tych liter, to cale nasze wygibasy bylyby niepotrzebne. Tylko wystarczyloby, ze wzielibysmy najwyzszy(gore) - najmniejszy(dolek).
     Jednak w naszym przypadku musza wystepowac obydwa znaki. Zauwazamy, wiec ze wtedy interesuje nas pierwszy, który jest najnizej i ostatni ktory jest najwyzej.
     W przypadku remisow najnizej / najwyzej zawsze interesuje nas w przypadku poczatku(pierwszy), a w przypadku konca(ostatni), zeby byla jak najwieksza
     szansa, ze beda w przedziale pomiedzy nimi i oraz j. Jesli jest w przedziale, to wyn = max(wyn, gora - dolek), a jak nie ma to musimy sprawdzic czy jedno wczesniej / jedno dalej jest to czego brakuje.
     jak nie ma, to nic nie zmieniamy z wynikiem, a jak jest do wyn = max(wyn, gora - dolek - 1), -1 jest, bo o jeden trzeba przeduzyc. Takie rozumowanie odplalamy, dla kazdej pary i oraz j, gdzie i,j to
     dowolne rozne litery dostepnego alfabetu, w w przypadku zadania od a - z.

     Kluczowe jest spostrzerzenie, ze taki przedzial zawsze bedzie dobry, bo jak nie bedzie w nim chociaz jednego wystapienia i oraz j, to sprawdzimy przedzial o dlugosci o jeden mniejszej.

     O rozwiazywaniu tego typu zadan moim zdaniem najlepiej rysowac sobie na kartce wykres(i idzie jedno w dol(-1), a j jedno w gore(+1))
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    for (int i = 0; i < n; ++i)
        stat[(int)ciag[i]-97].push_back(i);

    for (char i = 'a'; i <= 'z'; ++i)
    {
        for (char j = 'a'; j <= 'z'; ++j)
        {
            if (i == j)
                continue;
            if (stat[(int)i-97].size() == 0 || stat[(int)j-97].size() == 0)
                continue;
            wskI = 0, wskJ = 0, t_min = 0, t_max = 0, idx_min = 0, idx_max = 0, bilans = 0, czy_jest_I = false, czy_jest_J = false;
            znaki.clear();
            znaki.push_back('K'); // jakies byle co
            while(true)
            {
                if (wskI == stat[(int)i-97].size() && wskJ == stat[(int)j-97].size())
                    break;
                else if (wskI == stat[(int)i-97].size())
                {
                    znaki.push_back(j);
                    wskJ++;
                }
                else if (wskJ == stat[(int)j-97].size())
                {
                    znaki.push_back(i);
                    wskI++;
                }
                else if (stat[(int)i-97][wskI] < stat[(int)j-97][wskJ])
                {
                    znaki.push_back(i);
                    wskI++;
                }
                else
                {
                    znaki.push_back(j);
                    wskJ++;
                }
            }
            for (int k = 1; k < znaki.size(); ++k)
            {
                if (znaki[k] == i)
                    bilans++;
                else
                    bilans--;

                if (bilans < t_min)
                {
                    t_min = bilans;
                    idx_min = k;
                }
                if (bilans >= t_max)
                {
                    t_max = bilans;
                    idx_max = k;
                }
            }

            for (int k = min(idx_min, idx_max) + 1; k <= max(idx_min, idx_max); ++k)
            {
                if (znaki[k] == i)
                    czy_jest_I = true;
                else if (znaki[k] == j)
                    czy_jest_J = true;
            }

            int idx_lewo = min(idx_min, idx_max), idx_prawo = -1;
            if (max(idx_min, idx_max) != znaki.size()-1)
                idx_prawo = max(idx_min, idx_max) + 1;

            if (czy_jest_I == true && czy_jest_J == true)
                wyn = max(wyn, t_max - t_min);
            else if (czy_jest_I == false)
            {
                if (znaki[idx_lewo] == i)
                    wyn = max(wyn, t_max - t_min - 1);
                else if (idx_prawo != -1)
                    if (znaki[idx_prawo] == i)
                        wyn = max(wyn, t_max - t_min - 1);
            }
            else if (czy_jest_J == false)
            {
                if (znaki[idx_lewo] == j)
                    wyn = max(wyn, t_max - t_min - 1);
                else if (idx_prawo != -1)
                    if (znaki[idx_prawo] == j)
                        wyn = max(wyn, t_max - t_min - 1);
            }

        }
    }

    cout << wyn << '\n';

    return 0;
}
