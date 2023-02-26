#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Element
{
    int suma;
    int gorny;
    int dolny;
    bool operator < (const Element &element) const
    {
        return suma > element.suma;
    }
};

int n = 0, k = 0, wczytana_liczba = 0, maxx = 0;
ll wyn = 0, suma = 0;
vector<int> A;
vector<int> B;
vector<int> pojedyncze;
vector<Element> podwojne;
vector<ll> dp_podwojne;
vector<int> maxy_sufixowe;
vector<int> miny_prefixowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    A.assign(n,0);
    B.assign(n,0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    for (int i = 0; i < n; ++i)
    {
        if (A[i] >= B[i])
        {
            pojedyncze.push_back(A[i]);
            pojedyncze.push_back(B[i]);
        }
        else
            podwojne.push_back({A[i] + B[i], A[i], B[i]});
    }

    sort(pojedyncze.begin(), pojedyncze.end(), greater<ll>());
    sort(podwojne.begin(), podwojne.end());

    dp_podwojne.assign((2*n)+1,0);

    if (podwojne.size() > 0)
    {
        maxy_sufixowe.assign(podwojne.size(),-1e9-20);
        miny_prefixowe.assign(podwojne.size(),1e9+20);

        maxy_sufixowe[podwojne.size()-1] = podwojne[podwojne.size()-1].gorny;
        for (int i = podwojne.size()-2; i >= 0; --i)
            maxy_sufixowe[i] = max(podwojne[i].gorny, maxy_sufixowe[i+1]);

        miny_prefixowe[0] = podwojne[0].dolny;
        for (int i = 1; i < podwojne.size(); ++i)
            miny_prefixowe[i] = min(podwojne[i].dolny, miny_prefixowe[i-1]);

        dp_podwojne[1] = maxy_sufixowe[0];
    }

    for (int i = 2; i <= podwojne.size() * 2; ++i)
    {
        if (i % 2 == 0)
        {
            suma += podwojne[i/2-1].suma;
            dp_podwojne[i] = suma;
        }
        else
            dp_podwojne[i] = suma + max(maxy_sufixowe[i/2],podwojne[i/2].suma - miny_prefixowe[i/2-1]);
    }

    suma = 0;
    int do_kiedy = min(k,(int)pojedyncze.size());
    for (int i = 0; i <= do_kiedy; ++i)
    {
        wyn = max(wyn, suma + dp_podwojne[k-i]);
        suma += pojedyncze[i];
    }

    cout << wyn << '\n';

    return 0;
}