#include <cstdio>
#include <cstdlib>
#include <windows.h>


int main() {
	const int sleep=100;
	for(int i=1;i<=60;i++){
		for(int j=1;j<i;j++)
		{printf(" ");
		}
	printf("h");
	Sleep(sleep);
	system("cls");
	 
	}
	for(int i=60;i>0;i--){
		for(int j=1;j<i;j++)
		{printf(" ");
		}
	printf("h");
	Sleep(sleep);
	system("cls"); 
	
	}
    return 0;
}
