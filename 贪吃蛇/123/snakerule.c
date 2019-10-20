#include "snakerule.h"
#include "public.h"
#include "list.h"
#include "file.h"
#include "snakerecord.h"

extern char *name;
extern int score;
extern char click;
extern int speed;
extern int sign;
int flag = 1;


/*****************************************************************************************************************
* 函数名称：int Judge()
* 功能描述：
*			 实现 判定游戏结果 的功能
* 参数说明：
*
*
* 返回值：1
******************************************************************************************************************/

int Judge()
{
    int count = 0;
    int i = 0;

    if(sign != 3)
    {
            if (head->x == 0|| head->x == 56 || head->y == 0 || head->y == 26)
            {
                data_to_file();
                return 0;
            }
    }
    if(score == 160)
    {
        Win();
        return 0;
    }


    snake *p = head->next;
    while (1)
    {
        if (p->next == NULL)
        {
            break;
        }
        if (head->x == p->x&&head->y == p->y)
        {
            system("cls");
            data_to_file();
            return 0;
        }
        p = p->next;
    }
    return 1;
}


/*****************************************************************************************************************
* 函数名称：int MovingBody()
* 功能描述：
*			 实现 移动蛇身 的功能
* 参数说明：
*
*
* 返回值：1
******************************************************************************************************************/

int MovingBody()
{
    int i = 0;
    int count = 0;

    int a = head->x,
    b = head->y;
    snake *p = head;

    //通过先清空后打印实现动画效果
    while (1)
    {
        if (p->next == NULL)
            break;
        view_delete(p->x, p->y);
    //    count++;
        p = p->next;
    }
    switch(click)
    {
    case KEY_UP:
        {
           if(flag == 1 ||flag == 3|| flag == 4)
           {
              head->y -= 1;
              ChangeBody(a,b);
              flag = 1;
            //  printf("up");
           }
           else
           {
              head->y += 1;
              ChangeBody(a,b);
           }
        }
        break;
    case KEY_DOWN:
        {
            if(flag == 2 ||flag == 3|| flag == 4)
            {
               head->y += 1;
               ChangeBody(a,b);
               flag = 2;
              // printf("down");
            }
            else
            {
               head->y -= 1;
               ChangeBody(a,b);
            }

        }
        break;
    case KEY_LEFT:
        {
            if(flag == 1|| flag == 2 || flag == 3)
            {
              head->x -= 2;
              ChangeBody(a,b);
              flag = 3;
             //  printf("left");
            }
            else
            {
              head->x += 2;
              ChangeBody(a,b);
            }
        }
        break;
    case KEY_RIGHT:
        {
            if(flag == 1 || flag == 2|| flag == 4)
            {
              head->x += 2;
              ChangeBody(a,b);
              flag = 4;
      //         printf("right");
            }
            else
            {
               head->x -= 2;
              ChangeBody(a,b);
            }
        }
        break;
    case KEY_STOP:
        {
            return -1;
        }
        break;
    }
    p = head;
    if(sign == 3)
    {
        if(p->x >= 56)
            p->x = 0;
        else if(p->x <= 0)
            p->x = 56;

        if(p->y <=0)
            p->y = 26;
        else if(p->y >=26)
            p->y = 0;
    }
    while (1)
    {
        if (p->next == NULL)
            break;
        if(p == head)
        {
            head_print(p->x,p->y,flag);
        }
        else
        {
            view_print(p->x, p->y);
        }

        p = p->next;
    }
    p = head;

    gotoxy(0, 28);
    /*
    if (count <= 10)
    {
        speed = 150;
    }
    else if(count > 10 && count <= 20)
    {
        speed = 100;
    }
    else if (count > 20 && count <= 40)
    {
        speed = 50;
    }
    else
    {
        speed = 10;
    }
    */
    Sleep(speed);

    //刷新墙壁，防止被删掉
    for (i=0; i<58; i+=2)
    {
        view_print(i,0);
        view_print(i,26);
    }
    for (i = 1; i < 26; i++)
    {
        view_print(0,i);
        view_print(56,i);
    }

    return 0;
}
