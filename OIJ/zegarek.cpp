#include <iostream>
#include <string>

using namespace std;

int main() {
    int godziny = 0;
    int minuty = 0;
    int sekundy = 0;

    cin >> godziny >> minuty >> sekundy;

    // Ustalanie liczb o 1 wiekszych

    int sekundy_plus = sekundy+1;

    // Sprawdzanie czy nie przeskoczyla kolejna godzina lub minuta

    if (sekundy == 59)
    {
        sekundy_plus = 0;
        minuty += 1;
    }

    if (minuty == 60)
    {
        minuty = 0;
        godziny += 1;
    }

    if (godziny == 24)
    {
        godziny = 0;
        godziny = 0;
    }

    // Sprawdzanie czy trzeba dopisac 0


    string godziny_string = to_string(godziny);
    string minuty_string = to_string(minuty);
    string sekundy_string = to_string(sekundy_plus);


    if (godziny_string.length() == 1)
    {
        godziny_string = "0" + godziny_string;
    }
    if (minuty_string.length() == 1)
    {
        minuty_string = "0" + minuty_string;
    }
    if (sekundy_string.length() == 1)
    {
        sekundy_string = "0" + sekundy_string;
    }

    cout << godziny_string << ":" << minuty_string << ":" << sekundy_string;

    return 0;
}