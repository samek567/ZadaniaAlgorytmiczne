#include <iostream>
#include <vector>

using namespace std;

int n = 0, INF = 1e9;
vector<int> A;
vector<int> dp_lewo;
vector<int> dp_prawo;

int main()
{
    // O(N), programowanie dynamiczne
    /* dp_lewo[i] - ile najmniej trzeba poprzestawiac zapalek, zeby
       wszystkie zapalki od 0 do i byly zapalone oraz i-ta byla skierowana w lewo,
       dp_prawo[i] - ile najmniej trzeba poprzestawiac zapalek, zeby
       wszystkie zapalki od 0 do i byly zapalone oraz i-ta byla skierowana w prawo
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    A.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    dp_lewo.assign(n,INF);
    dp_prawo.assign(n,INF);

    dp_lewo[0] = 0, dp_prawo[0] = 0;
    if(A[0] == 1)
        dp_lewo[0]++;
    else
        dp_prawo[0]++;

    for (int i = 1; i < n; ++i)
    {
        dp_prawo[i] = dp_prawo[i-1];
        dp_lewo[i] = min(dp_lewo[i-1],dp_prawo[i-1]);
        if (A[i] == 1)
            dp_lewo[i]++;
        else
            dp_prawo[i]++;
    }

    cout << min(dp_lewo[n-1],dp_prawo[n-1]) << '\n';

    return 0;
}
