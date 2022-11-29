#include <iostream>
#include <vector>

using namespace std;

int n = 0;
long long wynik = 0;
char wczytany_znak;
vector<char> nazwisko_jasia;
vector<char> nazwisko_malgosi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        nazwisko_jasia.push_back(wczytany_znak);
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        nazwisko_malgosi.push_back(wczytany_znak);
    }


    for (int i = 0; i < n; ++i)
    {
        int idx_tej_samej = i;
        for (int j = i; j < n; ++j)
        {
            if (nazwisko_malgosi[i] == nazwisko_jasia[j])
            {
                idx_tej_samej = j;
                break;
            }
        }
        for (int j = idx_tej_samej; j > i; --j)
        {
            char przechowywany = nazwisko_jasia[j-1];
            nazwisko_jasia[j-1] = nazwisko_jasia[j];
            nazwisko_jasia[j] = przechowywany;
            wynik++;
        }
    }

    printf("%lld",wynik);

    return 0;
}
