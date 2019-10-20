#include "list.h"
#include "public.h"


/*****************************************************************************************************************
* �������ƣ�pNode *LIST_Init(void* Node)
* ����������
*			 ʵ�� ͷ����ʼ�� �Ĺ���
* ����˵����
*           void* Node --��������
* ����ֵ��pnew
******************************************************************************************************************/

pNode *LIST_Init(void* Node)
{
		pNode *pnew;
		pnew = (pNode *)malloc(sizeof(pNode));
		memset(pnew,0,sizeof(pNode));

		//��������� ָ����ΪNULL
		if(NULL == pnew)
		{
				printf("���ٿռ�ʧ��");
		}
		else
		{
				pnew->pData = Node;
				pnew->next = NULL;
		}

		return pnew;
}


/*****************************************************************************************************************
* �������ƣ�int LIST_Add(void* Node, pNode *head)
* ����������
*			 ʵ�� ������� �Ĺ���
* ����˵����
*           void* Node --��������  pNode *head --����ͷ���
* ����ֵ��pnew
******************************************************************************************************************/

int LIST_Add(void* Node, pNode *head)
{
		pNode *pnew = NULL;
		pNode *ptemp = head;
		pnew = LIST_Init(Node);

		//�ҵ�β���
		while( NULL != ptemp->next)
		{
				ptemp=ptemp->next;
		}

		ptemp->next = pnew;
		return 1;
}


/*****************************************************************************************************************
* �������ƣ�void LIST_Print(pNode *head)
* ����������
*			 ʵ�� �����ӡ �Ĺ���
* ����˵����
*            pNode *head --����ͷ���
* ����ֵ��pnew
******************************************************************************************************************/

void LIST_Print(pNode *head)
{
//		pNode *ptemp = head->next;

		//ѭ����ptemp��Ϊ��
//		while(NULL != ptemp)
//		{
//				printf("%s\n",((Person *)ptemp->pData)->szUsername);
//				ptemp = ptemp->next;
//		}
}


/*****************************************************************************************************************
* �������ƣ�int LIST_GetCount(pNode *head)
* ����������
*			 ʵ�� ��ȡͷ������ �Ĺ���
* ����˵����
*            pNode *head --����ͷ���
* ����ֵ��pnew
******************************************************************************************************************/


int LIST_GetCount(pNode *head)
{
		int count = 0;
		pNode *ptemp = head->next;

		//���Ϊ�ս���ѭ��
		while(NULL != ptemp)
		{
				ptemp = ptemp->next;
				count++;
		}

		return count;
}


/*****************************************************************************************************************
* �������ƣ�void LIST_Free(pNode *head)
* ����������
*			 ʵ�� �ͷ����� �Ĺ���
* ����˵����
*            pNode *head --����ͷ���
* ����ֵ��
******************************************************************************************************************/


void LIST_Free(pNode *head)
{
		pNode *ptemp = head->next;

		//ֱ����㲻Ϊ�ս���ѭ��
		while(NULL != ptemp)
		{
				ptemp = head->next;
				free(head->pData);		//�ͷ�������
				free(head);				//�ͷ�ͷ���
				head=ptemp;
		}

}


/*****************************************************************************************************************
* �������ƣ�int LIST_Del( int iIndex, pNode *head)
* ����������
*			 ʵ�� ͷ���ɾ�� �Ĺ���
* ����˵����
*            int iIndex --ɾ���ĵڼ������	pNode *head --����ͷ���
* ����ֵ��pnew
******************************************************************************************************************/

int LIST_Del( int iIndex, pNode *head)
{
		pNode *p = head->next,*p1 = head; //p1��һ�������Զ��p
		int count = 0; //�����ƽ��

		//ֱ�����Ϊ��ʱ����ѭ��
		while(p != NULL)
		{
				count++;

				//1.һ�������ȥ�ҵ�iIndex
				if(count == iIndex)
				{
						//2.���´��ӽ��
						p1->next = p->next;

						//3.�ͷ��ڴ�ռ�
						free(p->pData); //�ͷ�p��data
						free(p);		//�ͷ���p��data����p
						return 1;		//�ͷųɹ�
				}

				p1 = p1->next;
				p = p->next;
		}
		return -1;		//ɾ��ʧ��
}


/*****************************************************************************************************************
* �������ƣ�void *LIST_GetNode(int iIndex, pNode *head)
* ����������
*			 ʵ�� ͷ���ɾ�� �Ĺ���
* ����˵����
*            int iIndex --����ڼ������	pNode *head --����ͷ���
* ����ֵ��pnew
******************************************************************************************************************/

void *LIST_GetNode(int iIndex, pNode *head)
{
		//�������ظ������Ǹ�������
		pNode *p =head->next;
		int count = 0;	 //�����ƽ��

		//ֱ�����Ϊ��ʱ����ѭ��
		while(p != NULL)
		{
				count++;

				if(count == iIndex)
				{
						return p->pData; //���ظ���������
				}

				p = p->next;
		}
		return NULL;
}
/*

//�������������ѡ�񣬲��룬ð�ݣ�
int Sort_List(pNode* head)
{
    STAFF_T *a = NULL;
    STAFF_T *b = NULL;
    pNode* temp = NULL;
    pNode* p = NULL;
    char *t = {0};
    a = (STAFF_T *)malloc(sizeof(STAFF_T));
    b = (STAFF_T *)malloc(sizeof(STAFF_T));
    t = (char *)malloc(sizeof(char *));
    //int size = Size_List(head);
    //ѡ������
    /*for (Node* temp = head->next; temp != NULL; temp = temp->next){
        for (Node* p = temp; p != NULL; p = p->next){
            if (temp->data > p->data){
                printf("��%d��%d\n", temp->data, p->data);
                t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
        }
    }*/
    //��������
    /*for (Node* temp = head->next->next; temp != NULL; temp = temp->next){
        for (Node* p = head; p->next != NULL; p = p->next){
            if (p->next->data > temp->data)
            {
                printf("��%d��%d\n", temp->data, p->next->data);
                t = temp->data;
                temp->data = p->next->data;
                p->next->data = t;
            }
        }
    }*/
    //ð������
/*
    for (temp = head->next; temp->next != NULL; temp = temp->next)
    {
        for (p = head->next; p->next != NULL; p = p->next)
        {
                a= (STAFF_T *)(p->pData);
                b = (STAFF_T *)(p->next->pData);
            if (a->NO > b->NO){
                strcpy(t,a->NO);
                strcpy(a->NO,b->NO);
                strcpy(b->NO,t);
            }
        }
    }
    return 0;
}
*/
