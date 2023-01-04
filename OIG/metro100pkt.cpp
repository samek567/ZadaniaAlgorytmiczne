#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

struct Element
{
    int y;
    int x;
};

int n = 0, t = 0, a = 0, b = 0, numer_spojnej = 0;
vector<Element> stacje;
vector<int> w_jakiej_jest_spojnej;
unordered_map<int,set<int>> stat_y;
unordered_map<int,set<int>> stat_x;
vector<int> do_dodania;

void DFS(int v)
{
    // Idziemy po wszystkich x-ach i y-ach i usuwamy je z setow i puszczamy sie dalej w celu ustalenia spojnej.
    w_jakiej_jest_spojnej[v] = numer_spojnej;
    do_dodania.clear();
    for (int i = 0; i < do_dodania.size(); ++i)
        DFS(do_dodania[i]);
}

int main()
{
    // O(n log n), bo kazdy wierzcholek maksymalnie 2 razy przetworzymy (raz na mapie x, raz na y), a operacje na mapie maja koszt log n.
    // Dzielimy graf na Silnie spojne.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    w_jakiej_jest_spojnej.assign(n+1,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        stacje.push_back({a,b});
        if (auto it = stat_x.find(a) != stat_x.end())
            stat_x[a].insert(i+1);
        else
            stat_x.insert({a,{i+1}});
        if (auto it = stat_y.find(b) != stat_y.end())
            stat_y[b].insert(i+1);
        else
            stat_y.insert({b,{i+1}});
    }

    for (int i = 1; i <= n; ++i)
    {
        if (w_jakiej_jest_spojnej[i] == -1)
            DFS(i);
    }

    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b;
        if (w_jakiej_jest_spojnej[a] == w_jakiej_jest_spojnej[b])
            printf("TAK\n");
        else
            printf("NIE\n");
    }

    return 0;
}
