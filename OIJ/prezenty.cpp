#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long suma_cukierkow = 0;
    long long ile_paczek = 0;

    cin >> n;


    //suma_cukierkow = ((1+n) * n) / 2; // Nawet nie musimy tego liczyc wystarczy nam wzor ponizej.

    //ile_paczek = suma_cukierkow / n; // Nawet nie musimy tego liczyc wystarczy nam wzor ponizej.

    if (n % 2 == 0)
    {
        ile_paczek = n / 2;
    }
    else
    {
        ile_paczek = (n + 1) / 2;
    }

    printf("%lld \n",ile_paczek);

    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            printf("2 %d %d \n",i,n-i+1);
        }
    }
    else
    {
        for (int i = 1; i <= (n-1) / 2; i++)
        {
            printf("2 %d %d \n",i,n-i);
        }
        printf("1 %d \n",n);
    }

    return 0;
}