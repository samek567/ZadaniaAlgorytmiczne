#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string A;
    string B;

    cin >> A >> B;

    A = "0"+A; // Latiejsze idxy
    B = "0"+B; // Latwiejsze idxy

    int szachownica[A.size()][B.size()];

    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            szachownica[i][j] = 0;
        }
    }

    for (int i = 1; i < A.size(); ++i)
    {
        for (int j = 1; j < B.size(); ++j)
        {
            if (A[i] == B[j])
            {
                szachownica[i][j] = szachownica[i-1][j-1] + 1;
            }
            else
            {
                szachownica[i][j] = max(szachownica[i-1][j],szachownica[i][j-1]);
            }
        }
    }

    /*
    cout << "Wypisuje stan po aktualizacji: " << endl;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            cout << szachownica[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << szachownica[A.size()-1][B.size()-1];
    return 0;
}