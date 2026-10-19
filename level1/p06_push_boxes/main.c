#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
char map[7][30];
void pause(){      //click any button to continue(<conio.h>
    _getch();
}
void readmap(char *url) {
    FILE *a=fopen(url,"r");
    if (a==NULL) {
        printf("文件打开失败");
        return;
    }
    for (int i=0;i<7;i++) {
        fgets(map[i],30*sizeof(char),a);
    }
    for(int i=0;i<7;i++) {
        for (int j=0;j<30;j++) {
            if (map[i][j]=='\n') {
                map[i][j]='\0';
            }
            printf("%c",map[i][j]);
            if (map[i][j]=='\0') {
                break;
            }
        }printf("\n");
    }//输出地图
    fclose(a);
}
void putstep(int levelnumber,int step) {   //将游戏步数读入文件
    FILE *a=fopen("D:\\黄子卿\\c++\\数据结构与算法\\C-Cpp-2026\\level1\\p06_push_boxes\\step.txt","a");
    if (a==NULL) {
        printf("文件打开失败");
        return;
    }
    fprintf(a,"level");
    fprintf(a,"%d %d",levelnumber,step);
    fclose(a);
}
void gotoxy(short a,short b){    //移动光标
    HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=a;
    pos.Y=b;
    SetConsoleCursorPosition(hconsole,pos);
}

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
    printf("欢迎来到推箱子游戏，P代表玩家，B代表箱子，E代表出口，\n当P走到B上自动拾取箱子，显示C说明拾取成功，将所有箱子移至出口则通关\n\n");
    printf("点击空格键开始游戏");
    pause();
    system("cls");

    int sumlevel=2;//记录总关卡数
    int level=0,step=0,box=0;  //level记录第几关，step计步
    bool state=false;    //记录当前是否人手上有箱子
    char url1[]="D:\\黄子卿\\c++\\数据结构与算法\\C-Cpp-2026\\level1\\p06_push_boxes\\map1.txt";
    char url2[]="D:\\黄子卿\\c++\\数据结构与算法\\C-Cpp-2026\\level1\\p06_push_boxes\\map2.txt";
    char *url[2]={url1,url2};

    for (int i=0;i<sumlevel;i++){
    system("cls");     //把上一关的地图清理掉
    level++;
    readmap(url[i]);
    step=0;              //每一个level要重新计步数
    short x=1,y=1;
    short *a=&x,*b=&y;
    while (1) {
        step++;
        walkto(a,b);
        gotoxy(x,y);
        if (map[y][x]=='B') {   //B means box
            state=true;                //标识拿到箱子
        }
        if (state==true&&map[y][x]=='E') {    //带着箱子走到出口
            box++;
            state=false;
            x=1,y=1;
            gotoxy(x,y);
        }
        if (state) {
            printf("C");  //C means has caught box
        }else printf("P");   //P represent person

        if (box==2&&level<sumlevel) {
            putstep(level,step);
            box=0;
            system("cls");
            printf("通关！进入下一关！");
            Sleep(1000);
            break;
        }
        if (box==2&&level==sumlevel) {
            putstep(level,step);
            system("cls");
            break;
        }
      }
    }
    printf("游戏成功！");
    return 0;
}
