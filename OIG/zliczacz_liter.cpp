#include <iostream>
#include<string>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    string ciag;

    int licznik_a = 0;
    int licznik_b = 0;
    int licznik_c = 0;
    int licznik_d = 0;
    int licznik_e = 0;
    int licznik_f = 0;
    int licznik_g = 0;
    int licznik_h = 0;
    int licznik_i = 0;
    int licznik_j = 0;
    int licznik_k = 0;
    int licznik_l = 0;
    int licznik_m = 0;
    int licznik_n = 0;
    int licznik_o = 0;
    int licznik_p = 0;
    int licznik_q = 0;
    int licznik_r = 0;
    int licznik_s = 0;
    int licznik_t = 0;
    int licznik_u = 0;
    int licznik_v = 0;
    int licznik_w = 0;
    int licznik_x = 0;
    int licznik_y = 0;
    int licznik_z = 0;

    int licznik_A = 0;
    int licznik_B = 0;
    int licznik_C = 0;
    int licznik_D = 0;
    int licznik_E = 0;
    int licznik_F = 0;
    int licznik_G = 0;
    int licznik_H = 0;
    int licznik_I = 0;
    int licznik_J = 0;
    int licznik_K = 0;
    int licznik_L = 0;
    int licznik_M = 0;
    int licznik_N = 0;
    int licznik_O = 0;
    int licznik_P = 0;
    int licznik_Q = 0;
    int licznik_R = 0;
    int licznik_S = 0;
    int licznik_T = 0;
    int licznik_U = 0;
    int licznik_V = 0;
    int licznik_W = 0;
    int licznik_X = 0;
    int licznik_Y = 0;
    int licznik_Z = 0;


    cin >> n;
    getline(cin, ciag);

    for (int i = 0; i < n; i++)
    {
        getline(cin, ciag);
        //cout << ciag << endl;
        ciag.erase(std::remove(ciag.begin(), ciag.end(), ' '), ciag.end());
        //cout << ciag << endl;

        for (int i = 0; i < ciag.length(); i++)
        {
            if (ciag[i] == 'a')
            {
                licznik_a++;
            }
            else if (ciag[i] == 'b')
            {
                licznik_b++;
            }
            else if (ciag[i] == 'c')
            {
                licznik_c++;
            }
            else if (ciag[i] == 'd')
            {
                licznik_d++;
            }
            else if (ciag[i] == 'e')
            {
                licznik_e++;
            }
            else if (ciag[i] == 'f')
            {
                licznik_f++;
            }
            else if (ciag[i] == 'g')
            {
                licznik_g++;
            }
            else if (ciag[i] == 'h')
            {
                licznik_h++;
            }
            else if (ciag[i] == 'i')
            {
                licznik_i++;
            }
            else if (ciag[i] == 'j')
            {
                licznik_j++;
            }
            else if (ciag[i] == 'k')
            {
                licznik_k++;
            }
            else if (ciag[i] == 'l')
            {
                licznik_l++;
            }
            else if (ciag[i] == 'm')
            {
                licznik_m++;
            }
            else if (ciag[i] == 'n')
            {
                licznik_n++;
            }
            else if (ciag[i] == 'o')
            {
                licznik_o++;
            }
            else if (ciag[i] == 'p')
            {
                licznik_p++;
            }
            else if (ciag[i] == 'q')
            {
                licznik_q++;
            }
            else if (ciag[i] == 'r')
            {
                licznik_r++;
            }
            else if (ciag[i] == 's')
            {
                licznik_s++;
            }
            else if (ciag[i] == 't')
            {
                licznik_t++;
            }
            else if (ciag[i] == 'u')
            {
                licznik_u++;
            }
            else if (ciag[i] == 'v')
            {
                licznik_v++;
            }
            else if (ciag[i] == 'w')
            {
                licznik_w++;
            }
            else if (ciag[i] == 'x')
            {
                licznik_x++;
            }
            else if (ciag[i] == 'y')
            {
                licznik_y++;
            }
            else if (ciag[i] == 'z')
            {
                licznik_z++;
            }



            else if (ciag[i] == 'A')
            {
                licznik_A++;
            }
            else if (ciag[i] == 'B')
            {
                licznik_B++;
            }
            else if (ciag[i] == 'C')
            {
                licznik_C++;
            }
            else if (ciag[i] == 'D')
            {
                licznik_D++;
            }
            else if (ciag[i] == 'E')
            {
                licznik_E++;
            }
            else if (ciag[i] == 'F')
            {
                licznik_F++;
            }
            else if (ciag[i] == 'G')
            {
                licznik_G++;
            }
            else if (ciag[i] == 'H')
            {
                licznik_H++;
            }
            else if (ciag[i] == 'I')
            {
                licznik_I++;
            }
            else if (ciag[i] == 'J')
            {
                licznik_J++;
            }
            else if (ciag[i] == 'K')
            {
                licznik_K++;
            }
            else if (ciag[i] == 'L')
            {
                licznik_L++;
            }
            else if (ciag[i] == 'M')
            {
                licznik_M++;
            }
            else if (ciag[i] == 'N')
            {
                licznik_N++;
            }
            else if (ciag[i] == 'O')
            {
                licznik_O++;
            }
            else if (ciag[i] == 'P')
            {
                licznik_P++;
            }
            else if (ciag[i] == 'Q')
            {
                licznik_Q++;
            }
            else if (ciag[i] == 'R')
            {
                licznik_R++;
            }
            else if (ciag[i] == 'S')
            {
                licznik_S++;
            }
            else if (ciag[i] == 'T')
            {
                licznik_T++;
            }
            else if (ciag[i] == 'U')
            {
                licznik_U++;
            }
            else if (ciag[i] == 'V')
            {
                licznik_V++;
            }
            else if (ciag[i] == 'W')
            {
                licznik_W++;
            }
            else if (ciag[i] == 'X')
            {
                licznik_X++;
            }
            else if (ciag[i] == 'Y')
            {
                licznik_Y++;
            }
            else if (ciag[i] == 'Z')
            {
                licznik_Z++;
            }
        }

    }

    if (licznik_a > 0)
    {
        cout << "a " << licznik_a;
        cout << endl;
    }
    if (licznik_b > 0)
    {
        cout << "b " << licznik_b;
        cout << endl;
    }
    if (licznik_c > 0)
    {
        cout << "c " << licznik_c;
        cout << endl;
    }
    if (licznik_d > 0)
    {
        cout << "d " << licznik_d;
        cout << endl;
    }
    if (licznik_e > 0)
    {
        cout << "e " << licznik_e;
        cout << endl;
    }
    if (licznik_f > 0)
    {
        cout << "f " << licznik_f;
        cout << endl;
    }
    if (licznik_g > 0)
    {
        cout << "g " << licznik_g;
        cout << endl;
    }
    if (licznik_h > 0)
    {
        cout << "h " << licznik_h;
        cout << endl;
    }
    if (licznik_i > 0)
    {
        cout << "i " << licznik_i;
        cout << endl;
    }
    if (licznik_j > 0)
    {
        cout << "j " << licznik_j;
        cout << endl;
    }
    if (licznik_k > 0)
    {
        cout << "k " << licznik_k;
        cout << endl;
    }
    if (licznik_l > 0)
    {
        cout << "l " << licznik_l;
        cout << endl;
    }
    if (licznik_m > 0)
    {
        cout << "m " << licznik_m;
        cout << endl;
    }
    if (licznik_n > 0)
    {
        cout << "n " << licznik_n;
        cout << endl;
    }
    if (licznik_o > 0)
    {
        cout << "o " << licznik_o;
        cout << endl;
    }
    if (licznik_p > 0)
    {
        cout << "p " << licznik_p;
        cout << endl;
    }
    if (licznik_q > 0)
    {
        cout << "q " << licznik_q;
        cout << endl;
    }
    if (licznik_r > 0)
    {
        cout << "r " << licznik_r;
        cout << endl;
    }
    if (licznik_s > 0)
    {
        cout << "s " << licznik_s;
        cout << endl;
    }
    if (licznik_t > 0)
    {
        cout << "t " << licznik_t;
        cout << endl;
    }
    if (licznik_u > 0)
    {
        cout << "u " << licznik_u;
        cout << endl;
    }
    if (licznik_v > 0)
    {
        cout << "v " << licznik_v;
        cout << endl;
    }
    if (licznik_w > 0)
    {
        cout << "w " << licznik_w;
        cout << endl;
    }
    if (licznik_x > 0)
    {
        cout << "x " << licznik_x;
        cout << endl;
    }
    if (licznik_y > 0)
    {
        cout << "y " << licznik_y;
        cout << endl;
    }
    if (licznik_z > 0)
    {
        cout << "z " << licznik_z;
        cout << endl;
    }




    if (licznik_A > 0)
    {
        cout << "A " << licznik_A;
        cout << endl;
    }
    if (licznik_B > 0)
    {
        cout << "B " << licznik_B;
        cout << endl;
    }
    if (licznik_C > 0)
    {
        cout << "C " << licznik_C;
        cout << endl;
    }
    if (licznik_D > 0)
    {
        cout << "D " << licznik_D;
        cout << endl;
    }
    if (licznik_E > 0)
    {
        cout << "E " << licznik_E;
        cout << endl;
    }
    if (licznik_F > 0)
    {
        cout << "F " << licznik_F;
        cout << endl;
    }
    if (licznik_G > 0)
    {
        cout << "G " << licznik_G;
        cout << endl;
    }
    if (licznik_H > 0)
    {
        cout << "H " << licznik_H;
        cout << endl;
    }
    if (licznik_I > 0)
    {
        cout << "I " << licznik_I;
        cout << endl;
    }
    if (licznik_J > 0)
    {
        cout << "J " << licznik_J;
        cout << endl;
    }
    if (licznik_K > 0)
    {
        cout << "K " << licznik_K;
        cout << endl;
    }
    if (licznik_L > 0)
    {
        cout << "L " << licznik_L;
        cout << endl;
    }
    if (licznik_M > 0)
    {
        cout << "M " << licznik_M;
        cout << endl;
    }
    if (licznik_N > 0)
    {
        cout << "N " << licznik_N;
        cout << endl;
    }
    if (licznik_O > 0)
    {
        cout << "O " << licznik_O;
        cout << endl;
    }
    if (licznik_P > 0)
    {
        cout << "P " << licznik_P;
        cout << endl;
    }
    if (licznik_Q > 0)
    {
        cout << "Q " << licznik_Q;
        cout << endl;
    }
    if (licznik_R > 0)
    {
        cout << "R " << licznik_R;
        cout << endl;
    }
    if (licznik_S > 0)
    {
        cout << "S " << licznik_S;
        cout << endl;
    }
    if (licznik_T > 0)
    {
        cout << "T " << licznik_T;
        cout << endl;
    }
    if (licznik_U > 0)
    {
        cout << "U " << licznik_U;
        cout << endl;
    }
    if (licznik_V > 0)
    {
        cout << "V " << licznik_V;
        cout << endl;
    }
    if (licznik_W > 0)
    {
        cout << "W " << licznik_W;
        cout << endl;
    }
    if (licznik_X > 0)
    {
        cout << "X " << licznik_X;
        cout << endl;
    }
    if (licznik_Y > 0)
    {
        cout << "Y " << licznik_Y;
        cout << endl;
    }
    if (licznik_Z > 0)
    {
        cout << "Z " << licznik_Z;
        cout << endl;
    }

    return 0;
}