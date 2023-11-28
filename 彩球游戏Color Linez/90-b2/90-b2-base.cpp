/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
const int TYPE = 7;

void output_map(int(*map)[9], const int X, const int Y, int tag) // 输出数组
{
    const int WIDTH = 5;
    if (tag == 0)
        cout << endl << "初始数组：" << endl;
    else if (tag == 1)
        cout << endl << "移动后的数组（不同色标识）：" << endl;
    else
        cout << endl << "当前数组：" << endl;
    cout << "  │";
    for (int i = 0;i < Y;++i)
        cout << setw(WIDTH - 1) << i + 1;
    cout << endl << "─" << "┼";
    for (int i = 0;i < Y;++i)
        cout << "──";
    cout << endl;
    cout << setfill(' ');
    for (int i = 0;i < X;++i){
        cout <<"  │" << endl;
        cout << char('A' + i) << " │";
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
    cout << endl << "查找结果数组：" << endl;
    cout << "  │";
    for (int i = 0;i < Y;++i)
        cout << setw(WIDTH - 1) << i + 1;
    cout << endl << "─" << "┼";
    for (int i = 0;i < Y;++i)
        cout << "──";
    cout << endl;
    cout << setfill(' ');
    for (int i = 0;i < X;++i) {
        cout << "  │" << endl;
        cout << char('A' + i) << " │";
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
    cout << endl << "移动路径（不同色标识）：" << endl;
    cout << "  │";
    for (int i = 0;i < Y;++i)
        cout << setw(WIDTH - 1) << i + 1;
    cout << endl << "─" << "┼";
    for (int i = 0;i < Y;++i)
        cout << "──";
    cout << endl;
    cout << setfill(' ');
    for (int i = 0;i < X;++i) {
        cout << "  │" << endl;
        cout << char('A' + i) << " │";
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
        cout << "请以字母+数字形式【例：c2】输入要移动球的矩阵坐标：";
        fgets(fr, 9, stdin);
        chlwr(fr[0]);
        fr_x = fr[0] - 'a', fr_y = fr[1] - '1';
        if (fr_x < 0 || fr_x >= X || fr_y < 0 || fr_y >= Y) {
            cct_gotoxy(0, y + 1);
            cout << "输入错误，请重新输入。";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        if (map[fr_x][fr_y] == 0) {
            cct_gotoxy(0, y + 1);
            cout << "起始位置为空，请重新输入";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        break;
    }
    cout << "输入为" << char('A' + fr_x) << "行" << char('1' + fr_y) << "列" << endl;
    cct_getxy(x, y);
    while (1) {
        cct_gotoxy(0, y);
        cout << setw(100) << " ";
        cct_gotoxy(0, y);
        cout << "请以字母+数字形式【例：c2】输入要移动球的目的坐标：";
        fgets(to, 9, stdin);
        chlwr(to[0]);
        to_x = to[0] - 'a', to_y = to[1] - '1';
        if (to_x < 0 || to_x >= X || to_y < 0 || to_y >= Y) {
            cct_gotoxy(0, y + 1);
            cout << "输入错误，请重新输入。";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        if (map[to_x][to_y] != 0) {
            cct_gotoxy(0, y + 1);
            cout << "起始位置非空，请重新输入";
            Sleep(100);
            cct_gotoxy(0, y + 1);
            cout << setw(30) << " ";
            continue;
        }
        break;
    }
    cout << "输入为" << char('A' + to_x) << "行" << char('1' + to_y) << "列" << endl;
}
void sol_for_opt2()
{
    int map[9][9], X, Y, rem[9][9], path[9][9];
    bool vis[9][9];
    memset(map, 0, sizeof(map));

    input_XY(X, Y);
    init_balls(map, X, Y, int(X * Y * 0.6));
    output_map(map, X, Y, 0);
    cout << endl << "下三个彩球的颜色分别是：6 4 5" << endl;
    int fr_x, fr_y, to_x, to_y;
    input_move(fr_x, fr_y, to_x, to_y, X, Y, map);

    memset(vis, 0, sizeof(vis));
    memset(rem, -1, sizeof(rem));
    memset(path, -1, sizeof(path));
    vis[fr_x][fr_y] = 1;
    if (!dfs(fr_x, fr_y, to_x, to_y, vis, map, X, Y, 0, path, 0, rem))
        cout << "无法找到移动路径";
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
        cout << endl << "下3个彩球的颜色分别是：";
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
            cout << "无法找到移动路径";
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
            cout << "本次得分：" << get_pts << " 总得分：" << points << endl;
        }
        output_map(map, X, Y, 2);
    }
    if (cnt_color[0] != 0)
        cout << "无空位可移，游戏结束！" << endl;
    else
        cout << "无球可移，游戏结束！" << endl;

    wait_for_end();
}

