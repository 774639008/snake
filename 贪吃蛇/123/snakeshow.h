#ifndef _SNAKESHOW_H_
#define _SNAKESHOW_H_

void view_print(int x, int y);           //�����ӡ����

void view_delete(int x, int y);          //����ɾ������

void creatfood();                        //����ʳ�ﺯ��

void Finish();                           //δ�������а���溯��

void Win();                              //��Ϸʤ�����溯��

void head_print(int x, int y,int flag);  //��ͷ��ӡ����

void rank_show();                        //���а��ӡ����

void GoRank();                           //�������а��ӡ����

int user_show(int select);               //�û�����������ʾ

#endif // _SNAKESHOW_H_
