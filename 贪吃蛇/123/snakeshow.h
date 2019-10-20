#ifndef _SNAKESHOW_H_
#define _SNAKESHOW_H_

void view_print(int x, int y);           //界面打印函数

void view_delete(int x, int y);          //界面删除函数

void creatfood();                        //创建食物函数

void Finish();                           //未进入排行榜界面函数

void Win();                              //游戏胜利界面函数

void head_print(int x, int y,int flag);  //蛇头打印函数

void rank_show();                        //排行榜打印函数

void GoRank();                           //进入排行榜打印函数

int user_show(int select);               //用户排名界面显示

#endif // _SNAKESHOW_H_
