#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Gracze {
    char ID;
    int wartosc;
    bool operator < (const Gracze& gracze) const {
        if (wartosc != gracze.wartosc)
        {
            return wartosc > gracze.wartosc;
        }
        else
        {
            return wartosc < gracze.wartosc;
        }
    }
};

int main() {
    int n = 0;
    int licznik = 0;
    int punkty = 0;
    vector<Gracze> gracze;
    vector<char> gracze_znaki;

    cin >> n;

    for (char i = 'A'; i <= 'Z'; i++)
    {
        //cout << i << " ";
        cin >> punkty;
        if (licznik >= n)
        {
            break;
        }
        gracze.push_back({i,punkty});
        //cout << i << " ";
        licznik++;
    }

    sort(gracze.begin(),gracze.end());

    /*
    for (int i = 0; i < gracze.size();i++)
    {
        cout << gracze[i].ID << " " << gracze[i].wartosc << endl;
    }
     */

    for (int i = 0; i < n-1; i++)
    {
        //cout << gracze[i].ID;
        gracze_znaki.push_back(gracze[i].ID);
        if (gracze[i].wartosc != gracze[i+1].wartosc)
        {
            break;
        }
    }

    sort(gracze_znaki.begin(),gracze_znaki.end());

    //cout << endl;

    for (int i = 0; i < gracze_znaki.size(); i ++)
    {
        cout <<gracze_znaki[i];
    }

    return 0;
}