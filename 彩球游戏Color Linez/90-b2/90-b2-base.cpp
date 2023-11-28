/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
#include<windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
const int TYPE = 7;

void output_map(int(*map)[9], const int X, const int Y, int tag) // �������
{
    const int WIDTH = 5;
    if (tag == 0)
        cout << endl << "��ʼ���飺" << endl;
    else if (tag == 1)
        cout << endl << "�ƶ�������飨��ͬɫ��ʶ����" << endl;
    else
        cout << endl << "��ǰ���飺" << endl;
    cout << "  ��";
    for (int i = 0;i < Y;++i)
        cout << setw(WIDTH - 1) << i + 1;
    cout << endl << "��" << "��";
    for (int i = 0;i < Y;++i)
        cout << "����";
    cout << endl;
    cout << setfill(' ');
    for (int i = 0;i < X;++i){
        cout <<"  ��" << endl;
        cout << char('A' + i) << " ��";
        for (int j = 0;j < Y;++j) {
            if (map[i][j] == 0)
                 cout << setw(WIDTH - 1) << map[i][j];
            else {
                cout << setw(WIDTH - 2) << " ";
                int x, y;
                cct_getxy(x, y);
                cct_showch(x, y, map[i][j] + '0', 14, map[i][j], 1);
                cct_setcolor();
            }
        }
        cout << endl;
    }
}

void sol_for_opt1()
{
	int map[9][9], X, Y;
    memset(map, 0, sizeof(map));
	input_XY(X, Y);
    init_balls(map, X, Y, 5);
    output_map(map, X, Y, 0);
    wait_for_end();
}

void output_vis(bool(*vis)[9], const int X, const int Y)
{
    const int WIDTH = 5;
    cout << endl << "���ҽ�����飺" << endl;
    cout << "  ��";
    for (int i = 0;i < Y;++i)
        cout << setw(WIDTH - 1) << i + 1;
    cout << endl << "��" << "��";
    for (int i = 0;i < Y;++i)
        cout << "����";
    cout << endl;
    cout << setfill(' ');
    for (int i = 0;i < X;++i) {
        cout << "  ��" << endl;
        cout << char('A' + i) << " ��";
        for (int j = 0;j < Y;++j) {
            if (vis[i][j] == 0)
                cout << setw(WIDTH - 1) << 0;
            else
                cout << setw(WIDTH - 1) << '*';
        }
        cout << endl;
    }
}
void output_path(int(*map)[9], bool(*vis)[9], const int X, const int Y)
{
    const int WIDTH = 5;
    cout << endl << "�ƶ�·������ͬɫ��ʶ����" << endl;
    cout << "  ��";
    for (int i = 0;i < Y;++i)
        cout << setw(WIDTH - 1) << i + 1;
    cout << endl << "��" << "��";
    for (int i = 0;i < Y;++i)
        cout << "����";
    cout << endl;
    cout << setfill(' ');
    for (int i = 0;i < X;++i) {
        cout << "  ��" << endl;
        cout << char('A' + i) << " ��";
        for (int j = 0;j < Y;++j) {
            if (vis[i][j] == 0)
                cout << setw(WIDTH - 1) << map[i][j];
            else {
                cout << setw(WIDTH - 2) << " ";
                int x, y;
                cct_getxy(x, y);
                cct_showch(x, y, map[i][j] + '0', 14, 9, 1);
                cct_setcolor();
            }
        }
        cout << endl;
    }
}
void input_move(int& fr_x, int& fr_y, int& to_x, int& to_y, const int X, const int Y, const int(*map)[9]) 
{
    int x, y;
    char fr[10], to[10];
    cct_getxy(x, y);
    while (1) {
        cct_gotoxy(0, y);
        cout << setw(100) << " ";
        cct_gotoxy(0, y);
        cout << "������ĸ+������ʽ������c2������Ҫ�ƶ���ľ������꣺";
        fgets(fr, 9, stdin);
        chlwr(fr[0]);
        fr_x = fr[0] - 'a', fr_y = fr[1] - '1';
        if (fr_x < 0 || fr_x >= X || fr_y < 0 || fr_y >= Y) {
            cct_gotoxy(0, y + 1);
            cout << "����������������롣";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        if (map[fr_x][fr_y] == 0) {
            cct_gotoxy(0, y + 1);
            cout << "��ʼλ��Ϊ�գ�����������";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        break;
    }
    cout << "����Ϊ" << char('A' + fr_x) << "��" << char('1' + fr_y) << "��" << endl;
    cct_getxy(x, y);
    while (1) {
        cct_gotoxy(0, y);
        cout << setw(100) << " ";
        cct_gotoxy(0, y);
        cout << "������ĸ+������ʽ������c2������Ҫ�ƶ����Ŀ�����꣺";
        fgets(to, 9, stdin);
        chlwr(to[0]);
        to_x = to[0] - 'a', to_y = to[1] - '1';
        if (to_x < 0 || to_x >= X || to_y < 0 || to_y >= Y) {
            cct_gotoxy(0, y + 1);
            cout << "����������������롣";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        if (map[to_x][to_y] != 0) {
            cct_gotoxy(0, y + 1);
            cout << "��ʼλ�÷ǿգ�����������";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        break;
    }
    cout << "����Ϊ" << char('A' + to_x) << "��" << char('1' + to_y) << "��" << endl;
}
void sol_for_opt2()
{
    int map[9][9], X, Y, rem[9][9], path[9][9];
    bool vis[9][9];
    memset(map, 0, sizeof(map));

    input_XY(X, Y);
    init_balls(map, X, Y, int(X * Y * 0.6));
    output_map(map, X, Y, 0);
    cout << endl << "�������������ɫ�ֱ��ǣ�6 4 5" << endl;
    int fr_x, fr_y, to_x, to_y;
    input_move(fr_x, fr_y, to_x, to_y, X, Y, map);

    memset(vis, 0, sizeof(vis));
    memset(rem, -1, sizeof(rem));
    memset(path, -1, sizeof(path));
    vis[fr_x][fr_y] = 1;
    if (!dfs(fr_x, fr_y, to_x, to_y, vis, map, X, Y, 0, path, 0, rem))
        cout << "�޷��ҵ��ƶ�·��";
    else {
        int cur_x = fr_x, cur_y = fr_y;
        while (1) {
            vis[cur_x][cur_y] = 1;
            if (cur_x == to_x && cur_y == to_y)
                break;
            int tmp = path[cur_x][cur_y];
            if (tmp < 0) break;
            cur_y = tmp % Y;
            cur_x = (tmp - cur_y) / Y;
        }
        output_vis(vis, X, Y);
        output_path(map, vis, X, Y);
    }
    wait_for_end();
}

bool move(const int fr_x, const int fr_y, const int to_x, const int to_y, int(*map)[9], const int X, const int Y, const int* next_color, int*cnt_color)
{
    map[to_x][to_y] = map[fr_x][fr_y];
    map[fr_x][fr_y] = 0;
    bool tag = (bool)judge(map, X, Y, cnt_color);
    if (!tag)
        new_balls(map, X, Y, 3, next_color, cnt_color, 0);
    output_map(map, X, Y, 1);
    return tag;
}
void basic_solution() 
{
    int map[9][9], X, Y, path[9][9], rem[9][9];
    int next_color[3], cnt_color[TYPE + 1];
    int points = 0;
    bool vis[9][9];
    memset(map, 0, sizeof(map));

    input_XY(X, Y);
    init_balls(map, X, Y, 5);
    init_cnt_color(map, X, Y, cnt_color);
    output_map(map, X, Y, 0);


    while (cnt_color[0] < X * Y && cnt_color[0] > 0) {
        cout << endl << "��3���������ɫ�ֱ��ǣ�";
        for (int i = 0;i < 3;++i) {
            next_color[i] = rand() % TYPE + 1;
            cout << next_color[i] << " ";
        }
        cout << endl;
        int fr_x, fr_y, to_x, to_y;
        input_move(fr_x, fr_y, to_x, to_y, X, Y, map);
        memset(vis, 0, sizeof(vis));
        memset(path, -1, sizeof(path));
        memset(rem, -1, sizeof(rem));
        vis[fr_x][fr_y] = 1;
        if (!dfs(fr_x, fr_y, to_x, to_y, vis, map, X, Y, 0, path, 0, rem))
            cout << "�޷��ҵ��ƶ�·��";
        else {
            int cur_x = fr_x, cur_y = fr_y;
            while (1) {
                vis[cur_x][cur_y] = 1;
                if (cur_x == to_x && cur_y == to_y)
                    break;
                int tmp = path[cur_x][cur_y];
                if (tmp < 0) break;
                cur_y = tmp % Y;
                cur_x = (tmp - cur_y) / Y;
            }
            int get_pts = 0;
            if (move(fr_x, fr_y, to_x, to_y, map, X, Y, next_color, cnt_color)) {
                get_pts = 12;
                points += 12;
            }
            cout << "���ε÷֣�" << get_pts << " �ܵ÷֣�" << points << endl;
        }
        output_map(map, X, Y, 2);
    }
    if (cnt_color[0] != 0)
        cout << "�޿�λ���ƣ���Ϸ������" << endl;
    else
        cout << "������ƣ���Ϸ������" << endl;

    wait_for_end();
}

