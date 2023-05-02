#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

struct Element_seta
{
    int minn;
    int maxx;
    bool operator < (const Element_seta &element_seta) const
    {
        if (minn == element_seta.minn)
            return maxx < element_seta.maxx;
        return minn < element_seta.minn;
    }
};

int n = 0, q = 0, a = 0, b = 0, k = 317, wyn = 0;
vector<int> A;
map<Element_seta,int> S;
vector<int> ile_wystapien;
vector<vector<int>> wystapienia;

inline void napelniaj_wieksze_sqrt()
{
    for (int i = 1; i <= n; ++i)
    {
        if (ile_wystapien[i] > k)
        {
            int idx_ost = -1e8;
            for (int j = 0; j < n; ++j)
            {
                if (A[j] == i)
                    idx_ost = j;
                else if (idx_ost != -1e8)
                {
                    int minn = i, maxx = A[j];
                    if (maxx < minn)
                        swap(minn,maxx);
                    if (auto it = S.find({minn,maxx}) == S.end())
                        S.insert({{minn,maxx},j-idx_ost});
                    else
                        S[{minn,maxx}] = min(S[{minn,maxx}],j-idx_ost);
                }
            }

            idx_ost = 1e8;
            for (int j = n-1; j >= 0; --j)
            {
                if (A[j] == i)
                    idx_ost = j;
                else if (idx_ost != 1e8)
                {
                    int minn = i, maxx = A[j];
                    if (maxx < minn)
                        swap(minn,maxx);
                    if (auto it = S.find({minn,maxx}) == S.end())
                        S.insert({{minn,maxx},idx_ost-j});
                    else
                        S[{minn,maxx}] = min(S[{minn,maxx}],idx_ost-j);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    A.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    ile_wystapien.assign(n+1,0);
    wystapienia.assign(n+1,{});
    for (int i = 0; i < n; ++i)
    {
        ile_wystapien[A[i]]++;
        wystapienia[A[i]].push_back(i);
    }

    napelniaj_wieksze_sqrt();

    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        if (a > b)
            swap(a,b);
        int wyn = 1e9;

        if (ile_wystapien[a] <= k and ile_wystapien[b] <= k)
        {
            if (ile_wystapien[a] == 0 or ile_wystapien[b] == 0)
                break;
            int wsk_A = 0;
            for (int i = 0; i < wystapienia[b].size(); ++i)
            {
                while(wsk_A < ile_wystapien[a]-1)
                {
                    if (wystapienia[a][wsk_A+1] < wystapienia[b][i])
                        wsk_A++;
                    else
                        break;
                }
                if (wystapienia[a][wsk_A] < wystapienia[b][i])
                    wyn = min(wyn, wystapienia[b][i] - wystapienia[a][wsk_A]);
            }

            wsk_A = wystapienia[a].size()-1;
            for (int i = wystapienia[b].size()-1; i >= 0; --i)
            {
                while(wsk_A > 0)
                {
                    if (wystapienia[a][wsk_A-1] > wystapienia[b][i])
                        wsk_A--;
                    else
                        break;
                }
                if (wystapienia[a][wsk_A] > wystapienia[b][i])
                    wyn = min(wyn, wystapienia[a][wsk_A] - wystapienia[b][i]);
            }
        }
        else
        {
            if (auto it = S.find({a,b}) != S.end())
                wyn = S[{a,b}];
        }

        cout << wyn << '\n';
    }

    return 0;
}