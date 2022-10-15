#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    int ile_zespolow = 0;
    vector<int> gracze;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int aktualny_gracz = 0;
        cin >> aktualny_gracz;
        gracze.push_back(aktualny_gracz);
        //cout << gracze[i] << " ";
    }

    sort(gracze.begin(),gracze.end(), greater<int>());

    //cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (i < n - 2)
        {
            if (gracze[i] - gracze[i+2] <= 1)
            {
                ile_zespolow += 1;
                i += 2;
            }
        }
        //cout << gracze[i] << " ";

    }

    //cout << endl;

    cout << ile_zespolow;

    return 0;
}