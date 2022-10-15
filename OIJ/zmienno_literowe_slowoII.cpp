#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int zamiana(char literka)
{
    return int(literka) - int('a');
}


int main () {
    string ciag = "";
    cin >> ciag;
    long long P[26][ciag.length()];


    for(int i = 0; i < 26;i++)
    {
        if(zamiana(ciag[0]) == i)
        {
            P[i][0] = 1;
        }
        else P[i][0] = 0;
    }
    for(long long i = 1; i < ciag.length();i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(zamiana(ciag[i]) == j)
            {
                P[j][i] = P[j][i - 1] + 1;
            }
            else P[j][i] = P[j][i - 1];
        }
    }
    /*
    for(int i = 0; i < ciag.length();i++)
    {
        for(int j = 0; j < 26; j++)
        {
            cout << P[j][i] << " ";
        }
        cout << "\n";
    }
    */
    long long Lj = 0;
    long long Rj = 0;
    long long wynik = 0;
    for(long long j = 1; j < ciag.length();j++)
    {
        //Lj = j - P[ciag[j]][j] + 1;
        Lj = j - P[zamiana(ciag[j])][j] + 1;
        // ile jest b przed nami P[ciag[j]][ciag.length() - 1] - P[ciag[j]][j]
        //Rj = ciag.length() - j - 1 -(P[ciag[j]][ciag.length() - 1] - P[ciag[j]][j]);
        Rj = ciag.length() - j - 1 -(P[zamiana(ciag[j])][ciag.length() - 1] - P[zamiana(ciag[j])][j]);
        //cout << "j: " << j << " Lj: " << Lj << " Rj: " << Rj << "\n";
        wynik = wynik + Lj * Rj;
    }
    cout << wynik << " ";
    long long L[26];
    long long F[26];
    long long index = 0;
    for(int i = 0; i < 26; i++)
    {
        index = 0;
        while(P[i][index] == 0)
        {
            index++;
            if(index == ciag.length())
            {
                index = -1;
                break;
            }
        }
        F[i] = index;
        index = ciag.length() - 1;
        while(P[i][index] == P[i][index - 1])
        {
            index--;
            if(index == 0)
            {
                if(P[i][index] == 0)
                    index = -1;
                else
                    index = 0;
                break;
            }
        }
        L[i] = index;
    }
    /*
      for(int i = 0; i < 26;i++)
      {
          cout << F[i] << " ";
      }
      cout << "\n";
      for(int i = 0; i < 26;i++)
      {
          cout << L[i] << " ";
      }
      cout << "\n";
      */
    wynik = 0;
    for(int i = 0; i < 26;i++)
    {
        for(int j = 0; j < 26;j++)
        {
            if(F[i] != -1 && L[j] != -1 && L[j] > F[i])
            {
                for(int k = 0; k < 26;k++)
                {
                    if(k != i && k != j)
                    {
                        if(P[k][L[j]] != P[k][F[i]])
                        {
                            wynik++;
                        }

                    }
                }
            }
        }
    }
    cout << wynik;
    return 0;
}