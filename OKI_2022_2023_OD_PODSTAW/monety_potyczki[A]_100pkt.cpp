#include <iostream>
#include <unordered_map>

using namespace std;

struct Element
{
    int min_idx;
    int max_idx;
};

int n = 0, k = 0, max_wyn = 0;
long long suma = 0;
char wczytany_znak;
unordered_map<long long,Element> stat;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> k;
    stat.insert({0,{-1,-1}});
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'O')
            suma++;
        else
            suma -= k;
        if (auto it = stat.find(suma) != stat.end())
            stat[suma].max_idx = i;
        else
            stat.insert({suma,{i,i}});
    }
    for (auto it = stat.begin(); it != stat.end(); ++it)
    {
        max_wyn = max(max_wyn,it->second.max_idx - it->second.min_idx);
    }
    printf("%d",max_wyn);

    return 0;
}