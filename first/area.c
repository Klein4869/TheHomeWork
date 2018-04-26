#include <stdio.h>
#include "math.h"

int isRect(int Aleft, int Atop, int Aright, int Abottom, int Bleft, int Btop, int Bright, int Bbottom){
    return !(Aleft>Bright||Atop<Bbottom||Abottom > Btop||Aright<Bleft);
}

int main(int argc, char const *argv[])
{
    int Width, Height;
    int Ax1, Ay1, Ax2, Ay2, Bx1, By1, Bx2, By2;
    int Max_A, Max_B, Min_A, Min_B;
    int Aleft, Aright, Atop, Abottom, Bleft, Bright, Btop, Bbottom;
    scanf("%d%d%d%d%d%d%d%d", &Ax1, &Ay1, &Ax2, &Ay2, &Bx1, &By1, &Bx2, &By2);
    if (Ax1 > Ax2){
        Max_A = Ax1;
        Min_A = Ax2;
    } else{
        Max_A = Ax2;
        Min_A = Ax1;
    }
    if (Bx1 > Bx2){
        Max_B = Bx1;
        Min_B = Bx2;
    }else{
        Max_B = Bx2;
        Min_B = Bx1;
    }
    int Max , Min;
    if (Max_A > Max_B){
        Max = Max_B;
    } else{
        Max = Max_A;
    }
    if (Min_A > Min_B){
        Min = Min_A;
    } else{
        Min = Min_B;
    }
    if (Max - Min < 0){
        printf("0\n");
        return 0;
    } else{
        Width = Max - Min;
    }
    if (Ay1 > Ay2){
        Max_A = Ay1;
        Min_A = Ay2;
    } else{
        Max_A = Ay2;
        Min_A = Ay1;
    }
    if (By1 > By2){
        Max_B = By1;
        Min_B = By2;
    }else{
        Max_B = By2;
        Min_B = By1;
    }
    if (Max_A > Max_B){
        Max = Max_B;
    } else{
        Max = Max_A;
    }
    if (Min_A > Min_B){
        Min = Min_A;
    } else{
        Min = Min_B;
    }
    if (Max - Min < 0){
        printf("0\n");
        return 0;
    } else{
        Height = Max - Min;
    }
    printf("%d\n", Width*Height);
    return 0;
}