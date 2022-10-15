#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    vector<string> bizuterie;
    string aktualny_ciag;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> aktualny_ciag;
        bizuterie.push_back(aktualny_ciag);
    }

    sort(bizuterie.begin(),bizuterie.end(),[](const std::string &s1, const std::string &s2) {
        if (s1.size() != s2.size()) {
            return s1.size() < s2.size();
        } else {
            return s1 < s2;
        }
    });

    for (int i = 0; i < n; i++)
    {
        cout << bizuterie[i] << endl;
    }


    return 0;
}