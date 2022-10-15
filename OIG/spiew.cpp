#include <iostream>

using namespace std;

int n = 0, ile_uczniow_pod_grupa = 0, wynik = 0;
char wczytany_znak;

void aktualizuj_wynik ()
{
    wynik += ile_uczniow_pod_grupa / 3;
    if (ile_uczniow_pod_grupa % 3 == 1 || ile_uczniow_pod_grupa % 3 == 2)
    {
        wynik++;
    }
    ile_uczniow_pod_grupa = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytany_znak;
        if (wczytany_znak == 'Z')
        {
            ile_uczniow_pod_grupa++;
        }
        else
        {
            aktualizuj_wynik();
        }
    }

    aktualizuj_wynik();

    cout << wynik;

    return 0;
}