#include <iostream>
#include <vector>

struct Pole
{
    int y;
    int x;
};

using namespace std;
typedef long long ll;

int n = 0, x_i = 0, y_i = 0;
ll suma = 0, min_wyn = 1e18+5;
vector<Pole> pola;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x_i >> y_i;
        pola.push_back({y_i,x_i});
    }
    if (n == 1)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i < n; ++i)
        suma += abs(pola[i-1].y - pola[i].y) + abs(pola[i-1].x - pola[i].x);
    if (n == 2)
    {
        printf("%lld",suma);
        return 0;
    }
    for (int i = 1; i < n-1; ++i)
    {
        suma -= abs(pola[i-1].y - pola[i].y) + abs(pola[i-1].x - pola[i].x);
        suma -= abs(pola[i].y - pola[i+1].y) + abs(pola[i].x - pola[i+1].x);
        suma += abs(pola[i-1].y - pola[i+1].y) + abs(pola[i-1].x - pola[i+1].x);
        min_wyn = min(min_wyn,suma);
        suma += abs(pola[i-1].y - pola[i].y) + abs(pola[i-1].x - pola[i].x);
        suma += abs(pola[i].y - pola[i+1].y) + abs(pola[i].x - pola[i+1].x);
        suma -= abs(pola[i-1].y - pola[i+1].y) + abs(pola[i-1].x - pola[i+1].x);
    }
    printf("%lld",min_wyn);
    return 0;
}
