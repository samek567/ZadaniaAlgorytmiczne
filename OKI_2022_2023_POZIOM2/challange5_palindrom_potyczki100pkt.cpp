#include <iostream>
#include <vector>

using namespace std;

long long n = 0, p = 199, mod1 = 1e9+7, BUFER_SIZE = 1e6, ile_mamy = 0, cnt = 0;
long long hash_przod = 0, hash_tyl = 0, p_hash_przod = 1, P = 1;
char wczytany_znak;
vector<char> STAT;

long long quick_pow(long long podstawa,long long wykladnik, long long mod)
{
    if (wykladnik == 0)
        return 1;
    long long val = quick_pow(podstawa,wykladnik/2, mod);
    if (wykladnik % 2 == 0)
    {
        return ((val * val) % mod);
    }
    else
    {
        return (((val * val) % mod) * podstawa) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n = 2*1e7+5;
    while (true)
    {
        if (!(cin >> wczytany_znak).good())
            break;
        if (isspace(wczytany_znak))
            break;
        hash_przod = (hash_przod + (long long)wczytany_znak * p_hash_przod) % mod1;
        p_hash_przod = (p_hash_przod * p) % mod1;
        STAT.push_back(wczytany_znak);
        if (STAT.size() == BUFER_SIZE)
        {
            P = quick_pow(p,n-ile_mamy-BUFER_SIZE,mod1);
            for (int j = BUFER_SIZE-1; j >= 0; --j)
            {
                hash_tyl = (hash_tyl + (long long)STAT[j] * P) % mod1;
                P = (P * p) % mod1;
            }
            STAT.clear();
            ile_mamy += BUFER_SIZE;
        }
        cnt++;
    }
    if (!STAT.empty())
    {
        P = quick_pow(p,n-ile_mamy-STAT.size(),mod1);
        for (int j = STAT.size()-1; j >= 0; --j)
        {
            hash_tyl = (hash_tyl + (long long)STAT[j] * P) % mod1;
            P = (P * p) % mod1;
        }
    }
    hash_przod = (hash_przod * quick_pow(p,n-cnt,mod1)) % mod1;

    if (hash_przod == hash_tyl)
        printf("TAK");
    else
        printf("NIE");

    return 0;
}