#include <stdio.h>
void hanoi(int n,char a,char b,char c) { //a:初始柱，b:assist柱，c:目标柱
    if (n==1) {
        printf("%c->%c\n",a,c);
    }
    else {
        hanoi(n-1,a,c,b);        
        printf("%c->%c\n",a,c);
        hanoi(n-1,b,a,c);
    }
}
int main() {
    char a='A',b='B',c='C';
    hanoi(64,a,b,c);
    return 0;
}

