#include <conio.h>
#include <string.h>
#include "public.h"

void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++)
    {
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",277);
    }
     //getch();
}

void exits(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("Exit...");
    gotoxy(30,15);
    for(r=1;r<=20;r++)
    {
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",277);
    }
     //getch();
}

int glb_putString(char acStr[100], int iMaxlen, int iputType, int isPlainttext)
{
		char ch;				//����ch������getch();
		int iLenth = 0;			//����һ���ַ���������������ĸ���

		while(1)
		{
				ch = getch();
				if(ch == '\r')		//�س� ɾ��
				{
						acStr[iLenth] = '\0';
						break;
				}
				if(ch == '\t')
				{
						acStr[iLenth] = '\0';
						break;
				}
				if(ch == '\b')		//ɾ���ַ�
				{
						if(iLenth > 0)
						{
							printf("\b \b");
							iLenth--;				//��ɾҪ������
							acStr[iLenth] = '\0';
						}
				}
				if(ch == 27)
				{
					return 27;
				}
				if(iLenth < iMaxlen)				//�жϳ����Ƿ�С����󳤶�
				{
						switch(iputType)             //���������1Ϊ����,2Ϊ��ĸ,3Ϊ��������ĸ
						{
						case 1:
							{
									if(ch >= '0' && ch <= '9')			//ֻ����������
									{
											if(isPlainttext)
											{
													putchar(ch);	//����
											}
											else
											{
													putchar('*');	//����
											}
											acStr[iLenth]= ch;		//������ַ��������acStr[ilenth]
											iLenth++;				//���м�������ĸ���
									}
							}
							break;
						case 2:
							{
									if(ch >= 'a' && ch <= 'z')		//ֻ��������ĸ
									{
											if(isPlainttext)
											{
													putchar(ch);	//����
											}
											else
											{
													putchar('*');	//����
											}
											acStr[iLenth]= ch;		//������ַ��������acStr[ilenth]
											iLenth++;				//���м�������ĸ���
									}
							}
							break;
						case 3:
							{
									if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z'|| ch >= 'A' && ch <= 'Z')	//����������ĸ������
									{
											if(isPlainttext)
											{
													putchar(ch);	//����
											}
											else
											{
													putchar('*');	//����
											}
											acStr[iLenth] = ch;		//������ַ��������acStr[ilenth]
											iLenth++;				//���м�������ĸ���
									}
							}
							break;
						default:
							{
									printf("�������\n");
							}
							break;
						}
					}
				else
				{
					continue;
				}
		}
		return 0;
}

/*****************************************************************************************************************
* �������ƣ�int gotoxy(int x,int y)
* ����������
*			 ʵ�� ��� �Ĺ���
* ����˵����
*           int x --x����   int y  --y����
* ����ֵ��0
******************************************************************************************************************/

int gotoxy(int x,int y)
{
		HANDLE handle;								//���þ��
		COORD coord;								//���ù��
		coord.X=x;									//����x����
		coord.Y=y;									//����y����
		handle=GetStdHandle(STD_OUTPUT_HANDLE);		//��ȡ��׼���
		SetConsoleCursorPosition(handle,coord);		//���ù�����
		return 0;
}


/*****************************************************************************************************************
* �������ƣ�int select_interface(int max)
* ����������
*			 ʵ�� ���ѡ�� �Ĺ���
* ����˵����
*
* ����ֵ��0
******************************************************************************************************************/
int select_interface(int max)			//�������ת�Լ�����ѡ��
{
	int quit=0;
	int s=1;
	while(1)
	{
		switch(getch())		//����
		{
		case 72:			//��
		case 75:			//��
			if(s==1) s=max;
			else s--;
			break;

		case 80:			//��
		case 77:			//��
			if(s==max) s=1;
			else s++;
			break;

		case '\r':			//ȷ��
			quit = 1;
			break;

		case 'q':			//�˳�
		case 'Q':
			exit(0);

		case 27:			//����
			return -3;
			break;

		default :
			break;
		}

		switch(s)			//�����ת
		{
		case 1:
			gotoxy(0,0);
			break;
		case 2:
			gotoxy(0,1);
			break;
		case 3:
			gotoxy(0,2);
			break;
		case 4:
			gotoxy(0,3);
			break;
		case 5:
			gotoxy(0,4);
			break;
		case 6:
			gotoxy(0,5);
			break;
		default :
			break;
		}
		if(quit==1) break;
	}
	return s;
}
/*
void public_num(char *pcBuf)
{
	*pcBuf = getch();
	return *pcBuf;
}
*/
//��װֻ����һ������
char *public_num(char *acBuf)
{
	char ch = 0,ch1 = 0;
	int i = 0;
	int lenth = 10;
    while (1)
	{
		ch = getch();
		if(ch == '\r')
		{
			*acBuf = 0;
			break;
		}
		else if (ch >= '0' && ch <= '9')
		{
		  if(i < lenth)
		  {
			putchar(ch);
			*acBuf = 0;
			*acBuf++ = ch;
			i++;
		  }
		}
		else if((unsigned char)ch>=0xa1 && (unsigned char)ch<=0xfe)
		{
			ch1 = getch();
			printf("%c%c",ch,ch1);
			*acBuf++ = ch;
			*acBuf++ = ch1;
		}
		else if (ch == '\b')
		{
			if (i>0)
			{
				if((unsigned char)ch>=0xa1 && (unsigned char)ch<=0xfe)
				{
					printf("\b \b\b \b");
					*acBuf-- = 0;
					*acBuf = 0;

				}
				else
				{
					printf("\b \b");
					*acBuf--;
					*acBuf = 0;
				}
				i--;
			}
		}
		else
		{
			continue;
		}
		return acBuf;
	}
	return 0;
}

/*
void public_num(char *pcBuf)
{
	*pcBuf = getch();
	return *pcBuf;
}
*/
//��װֻ����һ������
void public_char(char *acBuf)
{
	char ch = 0,ch1 = 0;
	int i = 0;
	int lenth = 10;
    while (1)
	{
		ch = getch();
		if(ch == '\r')
		{
			*acBuf = 0;
			break;
		}
		else if (ch >= '0' && ch <= '9')
		{
		  if(i < lenth)
		  {
			putchar(ch);
			*acBuf = 0;
			*acBuf++ = ch;
			i++;
		  }
		}
		else if((unsigned char)ch>=0xa1 && (unsigned char)ch<=0xfe)
		{
			ch1 = getch();
			printf("%c%c",ch,ch1);
			*acBuf++ = ch;
			*acBuf++ = ch1;
		}
		else if (ch == '\b')
		{
			if (i>0)
			{
				if((unsigned char)ch>=0xa1 && (unsigned char)ch<=0xfe)
				{
					printf("\b \b\b \b");
					*acBuf-- = 0;
					*acBuf = 0;

				}
				else
				{
					printf("\b \b");
					*acBuf--;
					*acBuf = 0;
				}
				i--;
			}
		}
		else
		{
			continue;
		}
	}
}
