#include <iostream>
#include <climits>

using namespace std;

struct punkt {
    int zachod;
    int wschod;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;

    int liczba = 0;
    int t_maks_zachod = 0;
    int t_maks_wschod = 0;
    int wysokosci[n];
    punkt odpowiedzi[n];

    for (int i = 0; i < n; i++)
    {
        cin >> liczba;
        wysokosci[i] = liczba;
    }

    for (int i = 0; i < n; i++)
    {
        if (wysokosci[i] > t_maks_zachod)
        {
            t_maks_zachod = wysokosci[i];
        }
        odpowiedzi[i].zachod = t_maks_zachod;
    }

    for (int i = n-1; i >= 0; i--)
    {
        if (wysokosci[i] > t_maks_wschod)
        {
            t_maks_wschod = wysokosci[i];
        }
        odpowiedzi[i].wschod = t_maks_wschod;
    }

    for (int i = 0; i < n; i++)
    {
        cout << odpowiedzi[i].zachod << " " << odpowiedzi[i].wschod << endl;
    }
    return 0;
}