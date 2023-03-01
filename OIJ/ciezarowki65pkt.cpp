#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
typedef double ld;
typedef int ll;

struct Ciezarowka
{
    ld x;
    int v;
};

int n = 0, A = 0, B = 0, x_i = 0, v_i = 0, idx_najszybciej_dogoniacej = 0;
ld T_MAX = 1e10, t = T_MAX, wyn = 0;
vector<Ciezarowka> ciezarowki; // Zakladamy, ze ostatnia na vectorze, to te z nesseserem, poczatkowo o x = A, v = 0.

inline ld kiedy_dogoni(Ciezarowka &c1, Ciezarowka &c2) // Kiedy c1 dogoni c2
{
    bool czy_c1_jedzie_w_prawo = true, czy_c2_jedzie_w_prawo = true;
    if (ciezarowki[ciezarowki.size()-1].x < c1.x)
        czy_c1_jedzie_w_prawo = false;
    if (B < c2.x)
        czy_c2_jedzie_w_prawo = false;
    if (czy_c1_jedzie_w_prawo == czy_c2_jedzie_w_prawo)
    {
        if (c1.v <= c2.v)
            return -1;
        return abs(c1.x - c2.x) / (ld)(abs(c1.v - c2.v));
    }
    else
    {
        return abs(c1.x - c2.x) / (ld)(c1.v + c2.v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> A >> B;
    for (int i = 0; i < n; ++i)
    {
        cin >> x_i >> v_i;
        ciezarowki.push_back({x_i,v_i});
    }
    ciezarowki.push_back({A,0});

    while(true)
    {
        t = T_MAX, idx_najszybciej_dogoniacej = -1;
        for (int i = 0; i < ciezarowki.size()-1; ++i)
        {
            ld kiedy = kiedy_dogoni(ciezarowki[i],ciezarowki[ciezarowki.size()-1]);
            if (kiedy < t and kiedy != -1 and ciezarowki[i].v > ciezarowki[ciezarowki.size()-1].v)
            {
                t = kiedy;
                idx_najszybciej_dogoniacej = i;
            }
        }
        ld kiedy_dojedzie_do_bajtogrodu = abs(B-ciezarowki[ciezarowki.size()-1].x) / (ld)(ciezarowki[ciezarowki.size()-1].v);
        if (kiedy_dojedzie_do_bajtogrodu <= t)
        {
            wyn += kiedy_dojedzie_do_bajtogrodu;
            break;
        }
        else
        {
            wyn += t;
            Ciezarowka do_dodanie = ciezarowki[idx_najszybciej_dogoniacej];
            ciezarowki.erase(ciezarowki.begin() + idx_najszybciej_dogoniacej);
            for (int i = 0; i < ciezarowki.size()-1; ++i)
            {
                if (ciezarowki[i].x < ciezarowki[ciezarowki.size()-1].x)
                    ciezarowki[i] = {ciezarowki[i].x + ciezarowki[i].v * t,ciezarowki[i].v};
                else
                    ciezarowki[i] = {ciezarowki[i].x - ciezarowki[i].v * t,ciezarowki[i].v};
            }
            if (do_dodanie.x < ciezarowki[ciezarowki.size()-1].x)
                do_dodanie = {do_dodanie.x + do_dodanie.v * t,do_dodanie.v};
            else
                do_dodanie = {do_dodanie.x - do_dodanie.v * t,do_dodanie.v};
            ciezarowki.pop_back();
            ciezarowki.push_back(do_dodanie);
        }
    }

    cout << setprecision(9) << fixed << wyn << endl;

    return 0;
}
