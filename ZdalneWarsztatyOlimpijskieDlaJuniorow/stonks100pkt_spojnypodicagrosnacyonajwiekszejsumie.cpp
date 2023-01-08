#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, q = 0, x = 0, wczytana_liczba = 0, a_i = 0, b_i = 0;
ll dp_poprzednie = 0, max_dp = 0;
vector<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba - x);
    }
    max_dp = max(0,liczby[0]);
    dp_poprzednie = max_dp;
    for (int i = 1; i < n; ++i)
    {
        dp_poprzednie = max(dp_poprzednie + (ll)liczby[i], (ll)liczby[i]);
        max_dp = max(max_dp,dp_poprzednie);
    }
    printf("%lld ",max_dp);
    for (int i = 0; i < q; ++i)
    {
        cin >> a_i >> b_i;
        liczby[a_i-1] = b_i - x;
        max_dp = max(0,liczby[0]);
        dp_poprzednie = max_dp;
        for (int j = 1; j < n; ++j)
        {
            dp_poprzednie = max(dp_poprzednie + (ll)liczby[j], (ll)liczby[j]);
            max_dp = max(max_dp,dp_poprzednie);
        }
        printf("%lld ",max_dp);
    }
    return 0;
}
