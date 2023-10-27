#include <stdio.h>

int main()
{
    int i, j;
    double matriz[3][3];

    double detM, detN, det;
    
    for (i=0; i<3; i++ ){
        for ( j=0; j<3; j++ ){
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    detM = matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1];
    detN = matriz[0][2]*matriz[1][1]*matriz[2][0] + matriz[0][0]*matriz[1][2]*matriz[2][1] + matriz[0][1]*matriz[1][0]*matriz[2][2];

    det = detM - detN;
    printf("\n%.1f\n", det);
    return 0;
}
