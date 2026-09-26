#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
bool prime(int n) {
    if (n==1)
        return false;
    else if (n==2) return true;
    else {
        for (int i=2;i<sqrt(n);i++) {
            if (n%i==0) return false;
    }
    }
    return true;
}
int main() {
    int n;
    printf("请输入一个正整数\n");
    scanf("%d",&n);
    if (prime(n)) printf("是素数");
    else printf("不是素数");

    return 0;
}
