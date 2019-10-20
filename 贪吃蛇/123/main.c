#include <stdio.h>
#include <stdlib.h>
#include "public.h"
#include "view.h"
#include "list.h"
#include "file.h"


#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4

#define DARKER -3


extern int speed;
int sign = 0;
pNode *phead = NULL;

FILE *bfp = NULL;  //简单
FILE *pfp = NULL;  //普通
FILE *dfp = NULL;  //困难

int btype = 0;    //简单
int ptype = 0;    //普通
int dtype = 0;    //困难

extern int score;

int main()
{
    phead=LIST_Init(NULL);

    while(1)
    {
        system("cls");
        while(1)
        {
            system("cls");
            main_menu();
            gotoxy(0,0);
            switch(select_interface(3))    //游戏菜单选择
            {
            case ONE:
                {
                    score = 0;     //数据清0
                    btype = 0;
                    ptype = 0;
                    dtype = 0;

                    system("cls");
                    sub_menu();
                    gotoxy(0,0);
                    switch(select_interface(4))    //游戏难度选择
                    {
                    case ONE:
                        {
                            bfp = FILE_open("data/beginer.txt");
                            sign = 3;
                            speed = 200;
                            btype = 1;
                        }
                        break;
                    case TWO:
                        {
                            pfp = FILE_open("data/player.txt");
                            sign = 3;
                            speed = 100;
                            ptype = 1;
                        }
                        break;
                    case THREE:
                        {
                            dfp = FILE_open("data/darker.txt");
                            sign = 2;
                            speed = 100;
                            dtype = 1;
                        }
                        break;
                    case FOUR:
                        {
                            continue;
                        }
                        break;
                    default:
                        {

                        }
                        break;
                    }
                    ////////////////游戏功能模块//////////////////////
                    load();
                    system("cls");
                    while(1)
                    {
                        show_game();
                        creatfood();
                        if (ClickControl() == 0)
                        {
                            break;
                            //return 0;
                        }
                        else
                        {
                            break;
                        }
                    }

                    fclose(bfp);
                    fclose(pfp);
                    fclose(dfp);
                    //////////////////////////////////////////////////
                }
                break;
            case TWO:   //排行榜的显示
                {
                    system("cls");
                   // rank_show();
                   user_show(1);
                   user_show(2);
                   user_show(3);
                    getch();
                }
                break;
            case THREE: //退出游戏
                {
                    exits();
                    exit(0);
                }
                break;
            default:
                {

                }
                break;
            }
        }
    }
    return 0;
}
