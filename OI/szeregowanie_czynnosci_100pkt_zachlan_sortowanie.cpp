#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef double ld;

struct Czynnosc
{
    ld a;
    ld b;
    int idx;
    bool operator < (const Czynnosc &czynnosc) const
    {
        return czynnosc.a / czynnosc.b < a / b;
    }
};

int n = 0;
ld a_i = 0, b_i = 0;
vector<Czynnosc> czynnosci;

int main()
{
    // O(N lg N), mamy dwie czynnosci, sprwadzamy ktora powinna sie wykonac przed ktora, zeby bylo szybciej, sprowadzamy to do wzoru z operatora,
    // nierownosc jest przechodnia, to gwarantuje nam, ze to dziala, dobrze omowil to Pan Mikolaj Bulge na OKI zawansowane 2022/2023 w temacie zachlanow.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    czynnosci.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> czynnosci[i].a >> czynnosci[i].b;
        czynnosci[i].idx = i+1;
    }

    sort(czynnosci.begin(), czynnosci.end());

    for (int i = 0; i < n; ++i)
        cout << czynnosci[i].idx << '\n';

    return 0;
}