#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int n = 0, wyn = 0;
ll wczytana_liczba = 0, val = 0;
const ll P = 50000000, a = 49999987, b = 22334563;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<bool> spr(P,false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        val = ((wczytana_liczba % a) * b) % a;
        if (spr[val] == false)
            wyn++;
        spr[val] = true;
    }
    printf("%d",wyn);
    return 0;
}