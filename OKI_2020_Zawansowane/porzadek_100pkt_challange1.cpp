#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, t = 0, ile = 0, a = 0, b = 0;
ll sum = 0;
string ciag;
vector<int> sumy_prefiksowe_N;
vector<int> sumy_prefiksowe_R;
vector<int> ile_lapie;
vector<ll> sumy_prefixowe_wyn;

int main()
{
    // O(N + T), sumy prefiksowe + statystyki
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ciag;
    ile_lapie.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == 'R')
            sum++;
        sumy_prefiksowe_R.push_back(sum);
    }
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ciag[i] == 'N')
            sum++;
        sumy_prefiksowe_N.push_back(sum);
    }
    sum = 0;
    for (int i = n-1; i >= 0; --i)
    {
        if (ciag[i] == 'N')
            sum++;
        else
            ile_lapie[i] = sum;
    }
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += ile_lapie[i];
        sumy_prefixowe_wyn.push_back(sum);
    }
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        a--;
        b--;
        int ile_na_przedziale_R = 0, ile_na_przedziale_N = 0;
        ll suma_na_przedziale = 0, wyn = 0;
        if (a == 0)
            ile_na_przedziale_R = sumy_prefiksowe_R[b];
        else
            ile_na_przedziale_R = sumy_prefiksowe_R[b] - sumy_prefiksowe_R[a-1];
        if (b != n-1)
            ile_na_przedziale_N = sumy_prefiksowe_N[n-1] - sumy_prefiksowe_N[b];
        if (a == 0)
            suma_na_przedziale = sumy_prefixowe_wyn[b];
        else
            suma_na_przedziale = sumy_prefixowe_wyn[b] - sumy_prefixowe_wyn[a-1];
        wyn = suma_na_przedziale - (ll)ile_na_przedziale_R * (ll)ile_na_przedziale_N;
        cout << wyn << '\n';
    }
    return 0;
}