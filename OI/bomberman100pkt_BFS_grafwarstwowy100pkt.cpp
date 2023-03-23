#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum Kierunek
{
    GORA, DOL, LEWO, PRAWO
};

enum Stan
{
    BEZ_BOMBY, PO_BOMBIE, POCZATEK_BOMBY_GORA, POCZATEK_BOMBY_DOL, POCZATEK_BOMBY_LEWO, POCZATEK_BOMBY_PRAWO, KONIEC_BOMBY_GORA, KONIEC_BOMBY_DOL, KONIEC_BOMBY_LEWO, KONIEC_BOMBY_PRAWO
};

struct Pole
{
    int y;
    int x;
};

struct Element_kolejki
{
    int y;
    int x;
    Stan kierunek_drogi;
};

int n = 0, delta_SIZE = 4;
Pole poczatek = {-1,-1}, koniec = {-1,-1};
vector<vector<char>> plansza;

vector<vector<int>> dp_bez_bomby;
vector<vector<int>> dp_poczatek_bomby_gora;
vector<vector<int>> dp_poczatek_bomby_dol;
vector<vector<int>> dp_poczatek_bomby_prawo;
vector<vector<int>> dp_poczatek_bomby_lewo;
vector<vector<int>> dp_koniec_bomby_gora;
vector<vector<int>> dp_koniec_bomby_dol;
vector<vector<int>> dp_koniec_bomby_prawo;
vector<vector<int>> dp_koniec_bomby_lewo;
vector<vector<int>> dp_po_bombie;

vector<vector<Element_kolejki>> dp_bez_bomby_odtwarzanie;
vector<vector<Element_kolejki>> dp_poczatek_bomby_gora_odtwarzanie;
vector<vector<Element_kolejki>> dp_poczatek_bomby_dol_odtwarzanie;
vector<vector<Element_kolejki>> dp_poczatek_bomby_prawo_odtwarzanie;
vector<vector<Element_kolejki>> dp_poczatek_bomby_lewo_odtwarzanie;
vector<vector<Element_kolejki>> dp_koniec_bomby_gora_odtwarzanie;
vector<vector<Element_kolejki>> dp_koniec_bomby_dol_odtwarzanie;
vector<vector<Element_kolejki>> dp_koniec_bomby_prawo_odtwarzanie;
vector<vector<Element_kolejki>> dp_koniec_bomby_lewo_odtwarzanie;
vector<vector<Element_kolejki>> dp_po_bombie_odtwarzanie;
vector<Pole> droga;

queue<Element_kolejki> Q;
vector<int> delta_Y = {0,0,1,-1};
vector<int> delta_X = {-1,1,0,0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    plansza.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        plansza[i].assign(n,'e');
        for (int j = 0; j < n; ++j)
        {
            cin >> plansza[i][j];
            if (plansza[i][j] == 'P')
                poczatek = {i,j};
            else if (plansza[i][j] == 'K')
                koniec = {i,j};
        }
    }

    dp_bez_bomby.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_bez_bomby[i].assign(n,-1);
    dp_poczatek_bomby_gora = dp_bez_bomby;
    dp_poczatek_bomby_dol = dp_bez_bomby;
    dp_poczatek_bomby_lewo = dp_bez_bomby;
    dp_poczatek_bomby_prawo = dp_bez_bomby;
    dp_koniec_bomby_gora = dp_bez_bomby;
    dp_koniec_bomby_dol = dp_bez_bomby;
    dp_koniec_bomby_lewo = dp_bez_bomby;
    dp_koniec_bomby_prawo = dp_bez_bomby;
    dp_po_bombie = dp_bez_bomby;

    dp_bez_bomby_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_bez_bomby_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_poczatek_bomby_gora_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_poczatek_bomby_gora_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_poczatek_bomby_dol_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_poczatek_bomby_dol_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_poczatek_bomby_lewo_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_poczatek_bomby_lewo_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_poczatek_bomby_prawo_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_poczatek_bomby_prawo_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_koniec_bomby_dol_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_koniec_bomby_dol_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_koniec_bomby_gora_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_koniec_bomby_gora_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_koniec_bomby_lewo_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_koniec_bomby_lewo_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_koniec_bomby_prawo_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_koniec_bomby_prawo_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});

    dp_po_bombie_odtwarzanie.assign(n,{});
    for (int i = 0; i < n; ++i)
        dp_po_bombie_odtwarzanie[i].assign(n,{-1,-1,BEZ_BOMBY});


    dp_bez_bomby[poczatek.y][poczatek.x] = 0;
    Q.push({poczatek.y, poczatek.x, BEZ_BOMBY});

    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        Q.pop();
        if (spr.y == koniec.y and spr.x == koniec.x)
        {
            int wyn = 0;
            Element_kolejki odtw = spr;
            if (spr.kierunek_drogi == BEZ_BOMBY)
                wyn = dp_bez_bomby[spr.y][spr.x];
            else if (spr.kierunek_drogi == PO_BOMBIE)
                wyn = dp_po_bombie[spr.y][spr.x];
            else if (spr.kierunek_drogi == POCZATEK_BOMBY_GORA)
                wyn = dp_poczatek_bomby_gora[spr.y][spr.x];
            else if (spr.kierunek_drogi == POCZATEK_BOMBY_DOL)
                wyn = dp_poczatek_bomby_dol[spr.y][spr.x];
            else if (spr.kierunek_drogi == POCZATEK_BOMBY_LEWO)
                wyn = dp_poczatek_bomby_lewo[spr.y][spr.x];
            else if (spr.kierunek_drogi == POCZATEK_BOMBY_PRAWO)
                wyn = dp_poczatek_bomby_prawo[spr.y][spr.x];
            else if (spr.kierunek_drogi == KONIEC_BOMBY_GORA)
                wyn = dp_koniec_bomby_gora[spr.y][spr.x];
            else if (spr.kierunek_drogi == KONIEC_BOMBY_DOL)
                wyn = dp_koniec_bomby_dol[spr.y][spr.x];
            else if (spr.kierunek_drogi == KONIEC_BOMBY_LEWO)
                wyn = dp_koniec_bomby_lewo[spr.y][spr.x];
            else if (spr.kierunek_drogi == KONIEC_BOMBY_PRAWO)
                wyn = dp_koniec_bomby_prawo[spr.y][spr.x];
            cout << wyn << '\n';

            while(true)
            {
                if (odtw.y == poczatek.y and odtw.x == poczatek.x)
                    break;
                droga.push_back({odtw.y,odtw.x});
                if (odtw.kierunek_drogi == BEZ_BOMBY)
                    odtw = dp_bez_bomby_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == POCZATEK_BOMBY_GORA)
                    odtw = dp_poczatek_bomby_gora_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == POCZATEK_BOMBY_DOL)
                    odtw = dp_poczatek_bomby_dol_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == POCZATEK_BOMBY_LEWO)
                    odtw = dp_poczatek_bomby_lewo_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == POCZATEK_BOMBY_PRAWO)
                    odtw = dp_poczatek_bomby_prawo_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == KONIEC_BOMBY_GORA)
                    odtw = dp_koniec_bomby_gora_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == KONIEC_BOMBY_DOL)
                    odtw = dp_koniec_bomby_dol_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == KONIEC_BOMBY_LEWO)
                    odtw = dp_koniec_bomby_lewo_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == KONIEC_BOMBY_PRAWO)
                    odtw = dp_koniec_bomby_prawo_odtwarzanie[odtw.y][odtw.x];
                else if (odtw.kierunek_drogi == PO_BOMBIE)
                    odtw = dp_po_bombie_odtwarzanie[odtw.y][odtw.x];
            }

            vector<vector<bool>> czy_jest_w_drodze;
            czy_jest_w_drodze.assign(n,{});
            for (int i = 0; i < n; ++i)
                czy_jest_w_drodze[i].assign(n,false);

            vector<vector<int>> sumy_prefiksowe_wiersze;
            sumy_prefiksowe_wiersze.assign(n,{});
            for (int i = 0; i < n; ++i)
                sumy_prefiksowe_wiersze[i].assign(n,-1);

            vector<vector<int>> sumy_prefiksowe_kolumny;
            sumy_prefiksowe_kolumny.assign(n,{});
            for (int i = 0; i < n; ++i)
                sumy_prefiksowe_kolumny[i].assign(n,-1);

            int suma = 0;
            bool czy_mamy = false;

            for (int i = 0; i < droga.size(); ++i)
            {
                if (plansza[droga[i].y][droga[i].x] == '#')
                {
                    czy_jest_w_drodze[droga[i].y][droga[i].x] = true;
                    ++suma;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                int sum = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (czy_jest_w_drodze[i][j] == true)
                        ++sum;
                    if (plansza[i][j] == 'X')
                        sum = 0;
                    sumy_prefiksowe_wiersze[i][j] = sum;
                }
                sum = 0;
                for (int j = n-1; j >= 0; --j)
                {
                    if (czy_jest_w_drodze[i][j] == true)
                        ++sum;
                    if (plansza[i][j] == 'X')
                        sum = 0;
                    sumy_prefiksowe_wiersze[i][j] += sum;
                }
                for (int j = 0; j < n; ++j)
                    if (czy_jest_w_drodze[i][j] == true)
                        --sumy_prefiksowe_wiersze[i][j];
            }

            for (int i = 0; i < n; ++i)
            {
                int sum = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (czy_jest_w_drodze[j][i] == true)
                        ++sum;
                    if (plansza[j][i] == 'X')
                        sum = 0;
                    sumy_prefiksowe_kolumny[j][i] = sum;
                }
                sum = 0;
                for (int j = n-1; j >= 0; --j)
                {
                    if (czy_jest_w_drodze[j][i] == true)
                        ++sum;
                    if (plansza[j][i] == 'X')
                        sum = 0;
                    sumy_prefiksowe_kolumny[j][i] += sum;
                }
                for (int j = 0; j < n; ++j)
                    if (czy_jest_w_drodze[j][i] == true)
                        --sumy_prefiksowe_kolumny[j][i];
            }

            for (int i = 0; i < n and czy_mamy == false; ++i)
            {
                for (int j = 0; j < n and czy_mamy == false; ++j)
                {
                    if (plansza[i][j] == 'X')
                        continue;
                    int ile_kontroluje = sumy_prefiksowe_wiersze[i][j] + sumy_prefiksowe_kolumny[i][j];
                    if (czy_jest_w_drodze[i][j] == true)
                        --ile_kontroluje;
                    if (ile_kontroluje == suma)
                    {
                        cout << i+1 << ' ' << j+1 << '\n';
                        czy_mamy = true;
                    }
                }
            }

            reverse(droga.begin(), droga.end());
            Pole odt = poczatek;
            for (int i = 0; i < droga.size(); ++i)
            {
                if (droga[i].y < odt.y)
                    cout << 'G';
                else if (droga[i].y > odt.y)
                    cout << 'D';
                else if (droga[i].x > odt.x)
                    cout << 'P';
                else
                    cout << 'L';
                odt = droga[i];
            }
            return 0;
        }
        if (spr.kierunek_drogi == BEZ_BOMBY)
        {
            for (int i = 0; i < delta_SIZE; ++i)
            {
                int y = spr.y + delta_Y[i], x = spr.x + delta_X[i];
                if (y >= 0 and y < n and x >= 0 and x < n)
                {
                    if (plansza[y][x] != 'X' and plansza[y][x] != '#')
                    {
                        if (dp_bez_bomby[y][x] == -1)
                        {
                            dp_bez_bomby[y][x] = dp_bez_bomby[spr.y][spr.x] + 1;
                            dp_bez_bomby_odtwarzanie[y][x] = {spr.y,spr.x,BEZ_BOMBY};
                            Q.push({y,x,BEZ_BOMBY});
                        }
                    }
                    if (plansza[y][x] == '#')
                    {
                        if (dp_poczatek_bomby_dol[y][x] == -1)
                        {
                            dp_poczatek_bomby_dol[y][x] = dp_bez_bomby[spr.y][spr.x] + 1;
                            dp_poczatek_bomby_dol_odtwarzanie[y][x] = {spr.y,spr.x,BEZ_BOMBY};
                            Q.push({y,x,POCZATEK_BOMBY_DOL});
                        }
                        if (dp_poczatek_bomby_gora[y][x] == -1)
                        {
                            dp_poczatek_bomby_gora[y][x] = dp_bez_bomby[spr.y][spr.x] + 1;
                            dp_poczatek_bomby_gora_odtwarzanie[y][x] = {spr.y,spr.x,BEZ_BOMBY};
                            Q.push({y,x,POCZATEK_BOMBY_GORA});
                        }
                        if (dp_poczatek_bomby_lewo[y][x] == -1)
                        {
                            dp_poczatek_bomby_lewo[y][x] = dp_bez_bomby[spr.y][spr.x] + 1;
                            dp_poczatek_bomby_lewo_odtwarzanie[y][x] = {spr.y,spr.x,BEZ_BOMBY};
                            Q.push({y,x,POCZATEK_BOMBY_LEWO});
                        }
                        if (dp_poczatek_bomby_prawo[y][x] == -1)
                        {
                            dp_poczatek_bomby_prawo[y][x] = dp_bez_bomby[spr.y][spr.x] + 1;
                            dp_poczatek_bomby_prawo_odtwarzanie[y][x] = {spr.y,spr.x,BEZ_BOMBY};
                            Q.push({y,x,POCZATEK_BOMBY_PRAWO});
                        }
                    }
                }
            }
        }
        else if (spr.kierunek_drogi == PO_BOMBIE)
        {
            for (int i = 0; i < delta_SIZE; ++i)
            {
                int y = spr.y + delta_Y[i], x = spr.x + delta_X[i];
                if (y >= 0 and y < n and x >= 0 and x < n)
                {
                    if (plansza[y][x] != 'X' and plansza[y][x] != '#')
                    {
                        if (dp_po_bombie[y][x] == -1)
                        {
                            dp_po_bombie[y][x] = dp_po_bombie[spr.y][spr.x] + 1;
                            dp_po_bombie_odtwarzanie[y][x] = {spr.y,spr.x,PO_BOMBIE};
                            Q.push({y,x,PO_BOMBIE});
                        }
                    }
                }
            }
        }
        else if (spr.kierunek_drogi == POCZATEK_BOMBY_LEWO)
        {
            int y = spr.y, x = spr.x - 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_poczatek_bomby_lewo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_poczatek_bomby_lewo[y][x] = dp_poczatek_bomby_lewo[spr.y][spr.x] + 1;
                    dp_poczatek_bomby_lewo_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_LEWO};
                    Q.push({y,x,POCZATEK_BOMBY_LEWO});
                }
            }
            y = spr.y - 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_gora[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_gora[y][x] = dp_poczatek_bomby_lewo[spr.y][spr.x] + 1;
                    dp_koniec_bomby_gora_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_LEWO};
                    Q.push({y,x,KONIEC_BOMBY_GORA});
                }
            }
            y = spr.y + 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_dol[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_dol[y][x] = dp_poczatek_bomby_lewo[spr.y][spr.x] + 1;
                    dp_koniec_bomby_dol_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_LEWO};
                    Q.push({y,x,KONIEC_BOMBY_DOL});
                }
            }
        }
        else if (spr.kierunek_drogi == POCZATEK_BOMBY_PRAWO)
        {
            int y = spr.y, x = spr.x + 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_poczatek_bomby_prawo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_poczatek_bomby_prawo[y][x] = dp_poczatek_bomby_prawo[spr.y][spr.x] + 1;
                    dp_poczatek_bomby_prawo_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_PRAWO};
                    Q.push({y,x,POCZATEK_BOMBY_PRAWO});
                }
            }
            y = spr.y - 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_gora[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_gora[y][x] = dp_poczatek_bomby_prawo[spr.y][spr.x] + 1;
                    dp_koniec_bomby_gora_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_PRAWO};
                    Q.push({y,x,KONIEC_BOMBY_GORA});
                }
            }
            y = spr.y + 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_dol[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_dol[y][x] = dp_poczatek_bomby_prawo[spr.y][spr.x] + 1;
                    dp_koniec_bomby_dol_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_PRAWO};
                    Q.push({y,x,KONIEC_BOMBY_DOL});
                }
            }
        }
        else if (spr.kierunek_drogi == POCZATEK_BOMBY_GORA)
        {
            int y = spr.y - 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_poczatek_bomby_gora[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_poczatek_bomby_gora[y][x] = dp_poczatek_bomby_gora[spr.y][spr.x] + 1;
                    dp_poczatek_bomby_gora_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_GORA};
                    Q.push({y,x,POCZATEK_BOMBY_GORA});
                }
            }
            y = spr.y, x = spr.x + 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_prawo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_prawo[y][x] = dp_poczatek_bomby_gora[spr.y][spr.x] + 1;
                    dp_koniec_bomby_prawo_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_GORA};
                    Q.push({y,x,KONIEC_BOMBY_PRAWO});
                }
            }
            y = spr.y, x = spr.x - 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_lewo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_lewo[y][x] = dp_poczatek_bomby_gora[spr.y][spr.x] + 1;
                    dp_koniec_bomby_lewo_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_GORA};
                    Q.push({y,x,KONIEC_BOMBY_LEWO});
                }
            }
        }
        else if (spr.kierunek_drogi == POCZATEK_BOMBY_DOL)
        {
            int y = spr.y + 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_poczatek_bomby_dol[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_poczatek_bomby_dol[y][x] = dp_poczatek_bomby_dol[spr.y][spr.x] + 1;
                    dp_poczatek_bomby_dol_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_DOL};
                    Q.push({y,x,POCZATEK_BOMBY_DOL});
                }
            }
            y = spr.y, x = spr.x + 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_prawo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_prawo[y][x] = dp_poczatek_bomby_dol[spr.y][spr.x] + 1;
                    dp_koniec_bomby_prawo_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_DOL};
                    Q.push({y,x,KONIEC_BOMBY_PRAWO});
                }
            }
            y = spr.y, x = spr.x - 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_lewo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_lewo[y][x] = dp_poczatek_bomby_dol[spr.y][spr.x] + 1;
                    dp_koniec_bomby_lewo_odtwarzanie[y][x] = {spr.y, spr.x, POCZATEK_BOMBY_DOL};
                    Q.push({y,x,KONIEC_BOMBY_LEWO});
                }
            }
        }

        else if (spr.kierunek_drogi == KONIEC_BOMBY_LEWO)
        {
            int y = spr.y, x = spr.x - 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_lewo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_lewo[y][x] = dp_koniec_bomby_lewo[spr.y][spr.x] + 1;
                    dp_koniec_bomby_lewo_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_LEWO};
                    Q.push({y,x,KONIEC_BOMBY_LEWO});
                }
            }
            y = spr.y - 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_lewo[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_LEWO};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
            y = spr.y + 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_lewo[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_LEWO};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
        }
        else if (spr.kierunek_drogi == KONIEC_BOMBY_PRAWO)
        {
            int y = spr.y, x = spr.x + 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_prawo[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_prawo[y][x] = dp_koniec_bomby_prawo[spr.y][spr.x] + 1;
                    dp_koniec_bomby_prawo_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_PRAWO};
                    Q.push({y,x,KONIEC_BOMBY_PRAWO});
                }
            }
            y = spr.y - 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_prawo[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_PRAWO};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
            y = spr.y + 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_prawo[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_PRAWO};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
        }
        else if (spr.kierunek_drogi == KONIEC_BOMBY_GORA)
        {
            int y = spr.y - 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_gora[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_gora[y][x] = dp_koniec_bomby_gora[spr.y][spr.x] + 1;
                    dp_koniec_bomby_gora_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_GORA};
                    Q.push({y,x,KONIEC_BOMBY_GORA});
                }
            }
            y = spr.y, x = spr.x + 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_gora[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_GORA};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
            y = spr.y, x = spr.x - 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_gora[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_GORA};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
        }
        else if (spr.kierunek_drogi == KONIEC_BOMBY_DOL)
        {
            int y = spr.y + 1, x = spr.x;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_koniec_bomby_dol[y][x] == -1 and plansza[y][x] != 'X')
                {
                    dp_koniec_bomby_dol[y][x] = dp_koniec_bomby_dol[spr.y][spr.x] + 1;
                    dp_koniec_bomby_dol_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_DOL};
                    Q.push({y,x,KONIEC_BOMBY_DOL});
                }
            }
            y = spr.y, x = spr.x + 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_dol[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_DOL};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
            y = spr.y, x = spr.x - 1;
            if (y >= 0 and y < n and x >= 0 and x < n)
            {
                if (dp_po_bombie[y][x] == -1 and plansza[y][x] != 'X' and plansza[y][x] != '#')
                {
                    dp_po_bombie[y][x] = dp_koniec_bomby_dol[spr.y][spr.x] + 1;
                    dp_po_bombie_odtwarzanie[y][x] = {spr.y, spr.x, KONIEC_BOMBY_DOL};
                    Q.push({y,x,PO_BOMBIE});
                }
            }
        }
    }

    cout << "NIE" << '\n';

    return 0;
}