#include <stdio.h>
#include <conio.h>
#include <windows.h>
void pause(){      //click any button to continue(<conio.h>)
    printf("continue\n");
    _getch();
    printf("success\n");
}
void gotoxy(short a,short b){    //移动光标
    HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=a;
    pos.Y=b;
    SetConsoleCursorPosition(hconsole,pos);
}
char map[6][7]={
    {'#','P','#','#','#','#','#'},{'#',' ','#','#',' ','#','#'},
    {'#',' ',' ',' ',' ',' ','E'},{'#',' ','#','#',' ','#','#'},
    {'#',' ',' ','#',' ',' ','#'},{'#','#','#','#','#','#','#'}
};
void walkto(short *a,short *b){     //操作位移
    int ch;
    ch=_getch();
    gotoxy(*a,*b);
    printf(" ");
    if (ch==0||ch==224){
        ch=_getch();
        switch (ch){
            case 72:
                if (map[*b-1][*a]!='#')     //注意二维数组取坐标与直角坐标系不一样！map[列][行]
                    (*b)--;
                //UP
                break;
            case 80:
                //DOWN
                if (map[*b+1][*a]!='#')
                    (*b)++;
                break;
            case 75:
                if (map[*b][*a-1]!='#')
                    (*a)--;//left
                break;
            case 77:
                //printf("right");
                if (map[*b][*a+1]!='#')
                    (*a)++;
                break;
        }
    }
    else return;
}
int main() {
    for(int i=0;i<6;i++) {
        for (int j=0;j<7;j++) {
            printf("%c",map[i][j]);
        }printf("\n");
    }//输出地图

    short x=1,y=0;
    short *a=&x,*b=&y;
    while (1) {
        walkto(a,b);
        gotoxy(x,y);
        printf("P");
        if (x==6&&y==2) {
            printf("游戏成功！");
            break;
        }
    }
    return 0;
}
