#include "snakerecord.h"
#include "list.h"
#include "public.h"
#include "snakeshow.h"

char *name = {0};
extern pNode *phead;
extern FILE *pfp;
extern FILE *dfp;
extern FILE *bfp;
extern int score;

extern int ptype;
extern int btype;
extern int dtype;


/*****************************************************************************************************************
* 函数名称：int data_to_file()
* 功能描述：
*			 实现 数据写入文件 的功能
* 参数说明：
*
*
* 返回值：0
******************************************************************************************************************/

int data_to_file()
{
    char *scores = {0};
    int i = 0;
    int count = 0;
    int sum = 0;
    int count2 = 0;
    user *person = NULL;
    user *data = NULL;
    pNode *thead = NULL;
    pNode* temp = NULL;
    pNode* p = NULL;
    user *a = NULL;
    user *b = NULL;
    user *g = NULL;
    int curren_sorce = 0;
    int a_num =0;
    int b_num = 0;
    char *s = {0};

    name = (char *)malloc(sizeof(char *));
    scores = (char *)malloc(sizeof(char *));
    person = (user *)malloc(sizeof(user));
    data = (user *)malloc(sizeof(user));
    memset(person,0,sizeof(user));
    s = (char *)malloc(sizeof(char *));

    a=(user *)malloc(sizeof(user));
    b=(user *)malloc(sizeof(user));
    g = (user *)malloc(sizeof(user));

    thead = (pNode *)malloc(sizeof(pNode *));

    thead = LIST_Init(NULL);

    //判断是否为前10的模块//
    if(btype == 1)
    {
       thead=FILE_read(bfp,sizeof(user));
    }
    else if(ptype == 1)
    {
       thead=FILE_read(pfp,sizeof(user));
    }
    else if(dtype == 1)
    {
       thead=FILE_read(dfp,sizeof(user));
    }

    count = LIST_GetCount(thead);
/*
    for(i = 1; i<=count; i++)
    {
        data = LIST_GetNode(i,thead);
        if(score > data->score)
        {
            sum++;
        }
    }
*/
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

           //     memset(l,0,sizeof(user *));
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
    sum = 0;
    count2 = count;
    printf("count = %d\n",count);
    printf("myscore = %d\n",score);
    for(i = 1; i <= count; i++)
    {
        g = (user *)LIST_GetNode(i,thead);
        printf("%s %s\n",g->name,g->score);
        if(i == 10)
        {
            curren_sorce = atoi(g->score);
            if(score > curren_sorce)
            {
                sum = 1;
            }
        }
    }

    ////////////////////////
    if(sum ==1 || count2 < 10)
    {
        system("cls");
        printf("Yeath!Get on the list!\n");
        printf("please input your name:\n");
        glb_putString(name,10,2,1);
        scores = itoa(score,scores,10);
        strcpy(person->name,name);
        strcpy(person->score,scores);
        LIST_Add(person,phead);

        if(btype == 1)
        {
            FILE_add(bfp,person,sizeof(user));
        }
        else if(ptype == 1)
        {
            FILE_add(pfp,person,sizeof(user));
        }
        else if(dtype == 1)
        {
            FILE_add(dfp,person,sizeof(user));
        }
        GoRank();
    }
    else
    {
        Finish();
    }
    return 0;
}



