/*2152402 ��� ������*/
#pragma once

//���˵�����������90-b3-main.cpp��------------------------------------------------------------------
int menu();  //��ʾ���˵��������û�ѡ��

//�͵���ʽ�˵���صĺ���������90-b3-popmenu.cpp��-----------------------------------------------
void show_popmenu(char(*file)[4], int n, int beg, int cur);  //��ʾ����ʽ�˵�
void choose_levels(char(*file)[4], int n);  //ѡ��ؿ�����������ƶ������µ���ʽ�˵���

//�ڲ����鷽ʽʵ�ֵĸ�����������90-b3-base.cpp��-------------------------------------------------
bool open_stage();  //�ж�stage�ļ����ܷ��
int read_stage();  //��ȡstage�ļ����е��ļ�
void read_file(char* name);  //��ȡѡ��ؿ���Ӧ���ļ�

//��cmdͼ�ν��淽ʽ��ʾ��صĺ���������90-b3-console.cpp��-------------------------------------
bool show_graph(char* s, int row, char* name); //��ʾ��row�е�ͼ��

//��������������90-b3-base.cpp��
void wait_for_enter();
void wait_for_end();