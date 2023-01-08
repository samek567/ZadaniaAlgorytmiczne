#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, q = 0, y_i = 0, x_i = 0, wyn = 0;
vector<int> Y; // Ile jest w i-tej kolumnie
vector<int> X; // Ile jest w i-tym wierszu
vector<int> przekatne_lewe;
vector<int> przekatne_prawe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    X.assign(n+1,0);
    Y.assign(m+1,0);
    przekatne_lewe.assign(n*3+m*3+100,0);
    przekatne_prawe.assign(n*3+m*3+100,0);

    for(int i = 0; i < q; ++i)
    {
        cin >> y_i >> x_i;
        Y[x_i]++;
        X[y_i]++;
        int przekatne_praw = y_i + x_i + (2 * (n - y_i));
        przekatne_prawe[przekatne_praw]++;
        przekatne_lewe[x_i + y_i]++;
        wyn = max(wyn,przekatne_prawe[przekatne_praw]);
        wyn = max(wyn,przekatne_lewe[x_i + y_i]);
        wyn = max(wyn,Y[x_i]);
        wyn = max(wyn,X[y_i]);
        printf("%d\n",wyn);
    }

    return 0;
}