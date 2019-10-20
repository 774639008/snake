#include "snakecontroller.h"
#include "public.h"
#include "snakeshow.h"


char name[20];
int score = 0;
char click = 1;
int speed;
extern int flag;

/*****************************************************************************************************************
* �������ƣ�int ClickControl(int sign)
* ����������
*			 ʵ�� ̰�����߼����� �Ĺ���
* ����˵����
*            sign�����ж��Ѷ�
*
* ����ֵ��1
******************************************************************************************************************/

int ClickControl(int sign)
{
    char c;
    click = 1;
    flag = 1;
    while (1)
    {
        if (Judge(sign)==0)
        {
           return 0;
        }

        if (kbhit())
        {
            click = getch();
        }
        if(MovingBody() == -1)
        {
            return -1;
        }
        Eating();
    }
    return 1;
}

/*****************************************************************************************************************
* �������ƣ�void Eating()
* ����������
*			 ʵ�� ̰���߳�ʳ�� �Ĺ���
* ����˵����
*
*
* ����ֵ��
******************************************************************************************************************/

void Eating()
{
    if(head->x == food.x&&head->y == food.y)
    {
        creatfood();
        snake *_new = (snake*)malloc(sizeof(snake));
        snake *p;
        p = head;
        while (1)
        {
            if(p->next->next == NULL)
                break;
            p = p->next;
        }
        p->next = _new;
        _new->next = tail;
        score += 1;
        gotoxy(77, 15);
        printf("SCORE:%d", score);
    }
}

/*****************************************************************************************************************
* �������ƣ�void ChangeBody(int a,int b)
* ����������
*			 ʵ�� ̰��������仯 �Ĺ���
* ����˵����
*            ����a������b
*
* ����ֵ��
******************************************************************************************************************/

void ChangeBody(int a,int b)
{
    snake *p = head->next;
    int mid1, mid2,_mid1,_mid2;
    mid1 = p->x;
    mid2 = p->y;
    while (1)
    {
        if (p->next->next == NULL)
            break;
        _mid1 = p->next->x;
        _mid2 = p->next->y;
        p->next->x = mid1;
        p->next->y = mid2;
        mid1 = _mid1;
        mid2 = _mid2;
        p = p->next;
    }
    p = head->next;

    //ʡ��
    if (p->next!= NULL)
	{
            p->x = a;
    		p->y = b;
    }
}


