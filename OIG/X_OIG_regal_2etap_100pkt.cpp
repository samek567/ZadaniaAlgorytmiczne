#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
string wczytany_ciag;
vector<int> rozmiary_pudelek;

int main()
{
    // Mozna tez przeciazyc wlasny operator sortowania na stringach. I sortowac po sizie, bez znaczenia.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_ciag;
        rozmiary_pudelek.push_back(wczytany_ciag.size());
    }

    sort(rozmiary_pudelek.begin(),rozmiary_pudelek.end());

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < rozmiary_pudelek[i]; ++j)
        {
            printf("O");
        }
        printf("\n");
    }
    return 0;
}