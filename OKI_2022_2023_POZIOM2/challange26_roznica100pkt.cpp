#include <iostream>
#include <vector>

using namespace std;

int n, wyn = 0, wsk_I = 0, wsk_J = 0, klucz_I = 0, klucz_J = 0, bilans = 0, maxx = 0, minn = 0;
bool czy_jest_gora_max = false, czy_jest_dol_max = false, czy_jest_gora_min = false, czy_jest_dol_min = false;
char znak;
string ciag;
vector<int> stat[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    for (int i = 0; i < n; ++i)
        stat[(int)ciag[i]-97].push_back(i);

    for (char i = 'a'; i <= 'z'; ++i)
    {
        for (char j = i+1; j <= 'z'; ++j)
        {
            if (stat[(int)i-97].size() == 0 or stat[(int)j-97].size() == 0)
                continue;
            wsk_I = 0, wsk_J = 0, klucz_I = (int)i - 97, klucz_J = (int)j - 97;
            bilans = 0, maxx = 0, minn = 0, czy_jest_gora_max = false, czy_jest_dol_max = false, czy_jest_gora_min = false, czy_jest_dol_min = false;
            while(true)
            {
                if (wsk_I == stat[klucz_I].size() and wsk_J == stat[klucz_J].size())
                    break;
                else if (wsk_I == stat[klucz_I].size())
                {
                    znak = j;
                    wsk_J++;
                }
                else if (wsk_J == stat[klucz_J].size())
                {
                    znak = i;
                    wsk_I++;
                }
                else if (stat[klucz_I][wsk_I] < stat[klucz_J][wsk_J])
                {
                    znak = i;
                    wsk_I++;
                }
                else
                {
                    znak = j;
                    wsk_J++;
                }
                if (znak == i)
                    bilans++;
                else
                    bilans--;

                if (czy_jest_gora_max == true and czy_jest_dol_max == true)
                    wyn = max(wyn, bilans - minn);
                else
                    wyn = max(wyn, bilans - minn - 1);
                if (czy_jest_gora_min == true and czy_jest_dol_min == true)
                    wyn = max(wyn, maxx - bilans);
                else
                    wyn = max(wyn, maxx - bilans - 1);

                if (bilans < minn)
                {
                    minn = bilans;
                    czy_jest_gora_max = false, czy_jest_dol_max = false;
                }
                else
                {
                    if (znak == i)
                        czy_jest_gora_max = true;
                    else
                        czy_jest_dol_max = true;
                }
                if (bilans > maxx)
                {
                    maxx = bilans;
                    czy_jest_gora_min = false, czy_jest_dol_min = false;
                }
                else
                {
                    if (znak == i)
                        czy_jest_gora_min = true;
                    else
                        czy_jest_dol_min = true;
                }
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}