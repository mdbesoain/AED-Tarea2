
#include <math.h>
#include <stdio.h>


void find_position(int a, int b)
{
    int ma = 1, mb = 1;         // initial (current) node
    int la = 0, lb = 1;         // left ancestor
    int ra = 1, rb = 0;         // right ancestor
    while(ma != a && mb != b)
    {
        if (b * ma < a * mb)
        {
            printf("R");
            la = ma; lb = mb;
            ma = ma + ra; mb = mb + rb;
        }
        else if (b * ma > a * mb)
        {
           printf("L");
            ra = ma; rb = mb;
            ma = ma + la; mb = mb + lb;
        }
        else
            break;
    }
}


int main() {
    int a,b;

   printf("insert den");
   scanf("%d",&a);
   printf("insert den");
   scanf("%d",&b);  
   find_position(a,b);
}