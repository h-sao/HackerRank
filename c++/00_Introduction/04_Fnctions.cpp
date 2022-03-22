#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int ckeck_max(int x, int y){
    if(x > y){
        return x;
    }
    return y;
}
int max_of_four(int a, int b, int c, int d){
    auto ans = a;
    ans = ckeck_max(ans, b);
    ans = ckeck_max(ans, c);
    return ckeck_max(ans, d);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
