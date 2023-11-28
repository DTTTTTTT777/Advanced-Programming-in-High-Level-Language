/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<io.h>
#include<string.h>
#include"cmd_console_tools.h"
#include"90-b3.h"

using namespace std;

void read_file(char* name)//��ȡѡ��ؿ���Ӧ���ļ�
{
    char file[35] = ".\\Stage\\Sokoban-Level-";
    strcat(file, name);
    strcat(file, ".txt");
    ifstream fin(file);
    if (!fin.is_open()) {
        cct_gotoxy(0, 0);
        cout << "�ļ���ʧ��";
        cct_gotoxy(0, 40);
        exit(-1);
    }
    int row = 0;
    char s[17];
    while (!fin.eof() && ++row <= 14) {
        fin.getline(s, 16, '\n');
        if (!show_graph(s, row, name)) {
            fin.close();
            return;
        }
    }
    fin.close();

    cct_setcolor();
    cct_gotoxy(0, 45);
    cout << "�ؿ���ʾ��ɣ���C/c����..";
    char ch;
    while (1) {
        ch = _getch();
        if (ch == 'c' || ch == 'C')
            break;
    }
}

bool open_stage()//�ж�stage�ļ����ܷ��
{
    _finddata_t file;
    long HANDLE;
    HANDLE = _findfirst(".\\Stage", &file);

    if (HANDLE == -1) {
        _findclose(HANDLE);
        return 0;
    }
    _findclose(HANDLE);
    return 1;
}

int read_stage()//��ȡstage�ļ����е��ļ�
{
    _finddata_t file;
    long HANDLE;
    HANDLE = _findfirst(".\\Stage\\Sokoban-Level-*.txt", &file);

    char file_names[500][4];
    int file_num = 0;

    if (HANDLE == -1)
        return -1;

    //��ʼ��ȡ�ļ�
    do {
        char name[260];
        strcpy(name, file.name);
        if (strlen(name) == 21) {
            for (int i = 14;i < 17;++i)
                file_names[file_num][i - 14] = name[i];
            file_names[file_num][3] = '\0';
            ++file_num;
        }
    } while (_findnext(HANDLE, &file) != -1);
    _findclose(HANDLE);

    //���ļ������ļ������ֵ�������
    for (int k = 1;k < file_num;++k)
        for (int i = 0;i < file_num - k;++i)
            if (strcmp(file_names[i], file_names[i + 1]) > 0)
                swap(file_names[i], file_names[i + 1]);

    if (file_num != 0) {
        choose_levels(file_names, file_num);
    }

    return file_num != 0;
}

void wait_for_enter()
{
    int X1 = 0, Y1 = 0, ret, maction, keycode1, keycode2;
    while (1) {
        ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);
        if (keycode1 == 13)
            break;
    }
}


void wait_for_end() //����End����
{
    cct_setcolor();
    cct_gotoxy(0, 42);
    cout << endl << "��С�������������End����....";
    int x, y;
    cct_getxy(x, y);
    char s[10];
    const char end[4] = "END";
    fgets(s, 9, stdin);
    while (1) {
        cct_gotoxy(x, y);
        cout << setw(20) << " ";
        cct_gotoxy(x, y);
        fgets(s, 9, stdin);
        bool tag = 1;
        for (int i = 0;i < 3;++i)
            if (s[i] != end[i] && s[i] != end[i] + 32) {
                tag = 0;
                break;
            }
        if (tag)
            break;
        cct_gotoxy(0, y + 1);
        cout << "�����������������";
    }
}