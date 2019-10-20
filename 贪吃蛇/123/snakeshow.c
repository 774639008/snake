#include "snakeshow.h"
#include "public.h"
#include "list.h"

extern int score;
extern char* name;
extern FILE* pfp;
extern FILE* dfp;
extern FILE* bfp;


/*****************************************************************************************************************
* 函数名称：void show_game()
* 功能描述：
*			 实现 游戏界面显示 的功能
* 参数说明：
*
*
* 返回值：0
******************************************************************************************************************/

void show_game()
{
    int i;
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
    gotoxy(77, 12);
    printf("ESC return.\n");
    gotoxy(77, 10);
    printf("Direction keys control the direction\n");
    gotoxy(77,11);
    printf("press any keys stop.\n");

    head = (snake*)malloc(sizeof(snake));
    head->x = 16;
    head->y = 15;

    tail = (snake*)malloc(sizeof(snake));
    snake *p = (snake*)malloc(sizeof(snake));
    snake *q = (snake*)malloc(sizeof(snake));
    p->x = 16;
    p->y = 16;
    q->x = 16;
    q->y = 17;
    head->next = p;
    p->next = q;
    q->next = tail;
    tail->next = NULL;
    tail->x = 4;
    tail->y = 2;

}


/*****************************************************************************************************************
* 函数名称：void rank_show()
* 功能描述：
*			 实现 排行榜界面显示 的功能
* 参数说明：
*
*
* 返回值：0
******************************************************************************************************************/

void rank_show()
{
    int i = 0;
    int j = 0;
  //  int k = 0;
    int count = 0;
//    int t = 0;
    user *a = NULL;
    user *b = NULL;

    pNode *thead = NULL;

    user *l = NULL;
    user *g = NULL;
    user *d = NULL;
    int a_num =0;
    int b_num = 0;

    char *name  = NULL;
    char *salary = NULL;
    //STAFF_T *temp = NULL;


    char *s = {0};

    thead = (pNode *)malloc(sizeof(pNode *));
//    lhead = (pNode *)malloc(sizeof(pNode *));
    thead = LIST_Init(NULL);
     //开辟结构体空间
    s = (char *)malloc(sizeof(char *));
    g = (user *)malloc(sizeof(user));
    l = (user *)malloc(sizeof(user));
    d = (user *)malloc(sizeof(user));

    name = (char *)malloc(sizeof(char *));


    pfp = FILE_open("data/player.txt");
    thead=FILE_read(pfp,sizeof(user));

    count = LIST_GetCount(thead);
    printf("%d\n",count);

    printf("NO     Name      Score\n");
    printf("------------------------\n");



    //
    for(i = 1; i <= count; i++)
    {
            g = (user *)LIST_GetNode(i,thead);
            a_num = atoi(g->score);
            for(j = i+1; j<= count; j++)
            {
                l = (user *)LIST_GetNode(j,thead);
                b_num = atoi(l->score);
                if(a_num < b_num)
                {
                    printf("gsocre:%s lsocre:%s\n",g->score,l->score);
                    strcpy(s,g->score);
                    strcpy(name,g->name);

                    strcpy(g->score,l->score);
                    strcpy(g->name,l->name);

                    strcpy(l->score,s);
                    strcpy(l->name,name);
                }
            }
    }
    //

    for(i = 1; i <=count; i++)
    {
        d = (user *)LIST_GetNode(i,thead);
        printf("%d    %5s  %10s\n",i,d->name,d->score);
    }


    printf("press any key return\n");
}


/*****************************************************************************************************************
* 函数名称：int user_show(int select)
* 功能描述：
*			 实现 用户分数显示 的功能
* 参数说明：
*           select参数为难度系数
*
* 返回值：0
******************************************************************************************************************/

int user_show(int select)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    int t = 0;
    user *a = NULL;
    user *b = NULL;
    pNode* temp = NULL;
    pNode* p = NULL;
    pNode *thead = NULL;
    user *l = NULL;
    user *g = NULL;
    int a_num =0;
    int b_num = 0;

    char *name  = NULL;
    char *salary = NULL;
    char *s = {0};

    a=(user *)malloc(sizeof(user));
    b=(user *)malloc(sizeof(user));

    thead = (pNode *)malloc(sizeof(pNode *));

    thead = LIST_Init(NULL);
     //开辟结构体空间
    s = (char *)malloc(sizeof(char *));
    g = (user *)malloc(sizeof(user));
    l = (user *)malloc(sizeof(user));

    name = (char *)malloc(sizeof(char *));

    if(select == 1)
    {
        printf("--------beginer--------\n");
        bfp = FILE_open("data/beginer.txt");
        thead=FILE_read(bfp,sizeof(user));
    }
    else if(select == 2)
    {
        printf("--------player----------\n");
        pfp = FILE_open("data/player.txt");
        thead=FILE_read(pfp,sizeof(user));
    }
    else
    {
        printf("--------darker----------\n");
        dfp = FILE_open("data/darker.txt");
        thead=FILE_read(dfp,sizeof(user));
    }

    count = LIST_GetCount(thead);

    for (temp = thead; temp->next != NULL; temp = temp->next)
    {
        for (p = thead; p->next != NULL; p = p->next)
        {
            if(p->pData != NULL)
            {
                a = (user *)(p->pData);

                b = (user *)(p->next->pData);

                a_num = atoi(a->score);
                b_num = atoi(b->score);
                memset(s,0,sizeof(char *));

                memset(l,0,sizeof(user *));
                memset(name,0,sizeof(char *));
                if (a_num < b_num)
                {
                    strcpy(s,a->score);
                    strcpy(name,a->name);

                    strcpy(a->score,b->score);
                    strcpy(a->name,b->name);

                    strcpy(b->score,s);
                    strcpy(b->name,name);
                }
            }
        }
    }
    printf("NO     Name      Score\n");
    if(count > 10)
    {
        count =10;
    }
    for(i = 1; i <= count; i++)
    {
        g = (user *)LIST_GetNode(i,thead);
        printf("%d    %5s  %8s\n",i,g->name,g->score);
    }
    printf("\n\n");
    return 0;
}


/*****************************************************************************************************************
* 函数名称：void creatfood()
* 功能描述：
*			 实现 生成食物显示 的功能
* 参数说明：
*
*
* 返回值：
******************************************************************************************************************/

void creatfood()
{
    srand((int)time(NULL));
    lable:
        food.y = rand() % (25 - 1 + 1) + 1;
        food.x = rand() % (54 - 2 + 1) + 2;
    if (food.x % 2 != 0)
    {
        food.x = food.x+1;
    }
    snake *judge = head;
    while (1)  //遍历排除蛇身重复
    {
        if (judge->next == NULL)
            break;
        if (food.x == judge->x&&food.y == judge->y)
        {
            goto lable;
        }
        judge = judge->next;
    }
    gotoxy(food.x, food.y);
    printf("*");
}

/*****************************************************************************************************************
* 函数名称：void view_delete(int x, int y)
* 功能描述：
*			 实现 界面块删除 的功能
* 参数说明：
*           x坐标，y坐标
*
* 返回值：
******************************************************************************************************************/

void view_delete(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}


/*****************************************************************************************************************
* 函数名称：void view_print(int x, int y)
* 功能描述：
*			 实现 界面打印 的功能
* 参数说明：
*           x坐标，y坐标
*
* 返回值：
******************************************************************************************************************/

void view_print(int x, int y)
{
	gotoxy(x,y);
	printf("+");
}


/*****************************************************************************************************************
* 函数名称：void head_print(int x, int y,int flag)
* 功能描述：
*			 实现 蛇头打印 的功能
* 参数说明：
*           x坐标，y坐标，flag蛇头位置标志位
*
* 返回值：
******************************************************************************************************************/

void head_print(int x, int y,int flag)
{
	gotoxy(x,y);
	if(flag == 1)
    {
        printf("^");
    }
    else if(flag == 2)
    {
        printf("V");
    }
    else if(flag == 3)
    {
        printf("<");
    }
    else if(flag == 4)
    {
        printf(">");
    }
}



/*****************************************************************************************************************
* 函数名称：void Finish()
* 功能描述：
*			 实现 未进入排行榜的结束打印界面 的功能
* 参数说明：
*
*
* 返回值：
******************************************************************************************************************/

void Finish()
{
    system("cls");
    gotoxy(15, 10);
    printf("/**********************************************/");
    gotoxy(15, 20);
    printf("/**********************************************/");
    gotoxy(18, 14);
    printf("GAME   OVER");
    gotoxy(20, 16);
    printf("Your Score is %d",score);
    gotoxy(0, 27);
    system("pause");
}



/*****************************************************************************************************************
* 函数名称：void GoRank()
* 功能描述：
*			 实现 进入排行榜的结束打印界面 的功能
* 参数说明：
*
*
* 返回值：
******************************************************************************************************************/

void GoRank()
{
    system("cls");
    gotoxy(15, 10);
    printf("/**********************************************/");
    gotoxy(15, 20);
    printf("/**********************************************/");
    gotoxy(18, 14);
    printf("Get on the list ");
    gotoxy(20, 16);
    printf("Your Score is %d",score);
    gotoxy(0, 27);
    system("pause");
}

/*****************************************************************************************************************
* 函数名称：void Win()
* 功能描述：
*			 实现 游戏胜利界面 的功能
* 参数说明：
*
*
* 返回值：
******************************************************************************************************************/

void Win()
{
    system("cls");
    gotoxy(15, 10);
    printf("/**********************************************/");
    gotoxy(15, 20);
    printf("/**********************************************/");
    gotoxy(18, 14);
    printf("Congraturation!!!!");
    gotoxy(20, 16);
    printf("Your Score is %d",score);
    gotoxy(0, 27);
    system("pause");
}




