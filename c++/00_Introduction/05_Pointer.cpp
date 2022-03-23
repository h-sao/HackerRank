#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    auto aa = *a;
    auto bb = *b;
    int minus;
    if(aa > bb){
        minus = aa - bb;
    }else{
        minus = bb - aa;
    }
    *a += *b;
    *b = minus;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
