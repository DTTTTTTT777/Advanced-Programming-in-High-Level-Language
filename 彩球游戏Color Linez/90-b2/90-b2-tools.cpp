/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<windows.h>
#include "cmd_console_tools.h"
using namespace std;
void input_XY(int& X, int& Y) //输入行数和列数
{
    cct_cls();
    int tmp[2];
    const char indi[2][20] = { "请输入行数(7-9)" ,"请输入列数(7-9)" };
    for (int i = 0;i < 2;++i) {
        while (1) {
            cout << indi[i] << endl;
            cin >> tmp[i];
            if (!cin.good())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            if (tmp[i] >= 7 && tmp[i] <= 9)
                break;
        }
    }
    X = tmp[0];
    Y = tmp[1];
}
void init_balls(int(*map)[9], const int X, const int Y, const int cnt) //初始生成cnt个球
{
    int x, y, cur_cnt = 0;
    while (cur_cnt < cnt)
        while (1) {
            x = rand() % X;
            y = rand() % Y;
            if (map[x][y] == 0) {
                map[x][y] = rand() % 7 + 1;
                ++cur_cnt;
                break;
            }
        }
}
void new_balls(int(*map)[9], const int X, const int Y, const int cnt, const int* next_color, int* cnt_color, bool show)
{
    int n = min(cnt, X * Y - cnt_color[0]);
    for (int i = 0;i < n;++i) {
        while (1) {
            int x = rand() % X, y = rand() % Y;
            if (map[x][y] == 0) {
                map[x][y] = next_color[i];
                if (show)
                    cct_showstr(2 + 4 * y, 2 + 2 * x, "○", 7 + map[x][y], 7);
                ++cnt_color[next_color[i]];
                break;
            }
        }
    }
    cnt_color[0] += n;
}
void wait_for_end() //输入End结束
{
    cct_setcolor();
    cout << endl << "本小题结束，请输入End继续....";
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
        cout << "输入错误，请重新输入";
        Sleep(100);
        cct_gotoxy(0, y + 1);
        cout << setw(20) << " ";
    }
}
void chlwr(char& ch)
{
    if (ch < 'a')
        ch += 32;
}
void wait_for_enter(const char* s)
{
    cout << endl << s;
    int X = 0, Y = 0, ret, maction, keycode1, keycode2;
    while (1)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT && keycode1 == 13)
            break;
    }
}

const int DX[4] = { 0,0,1,-1 }, DY[4] = { 1,-1,0,0 };
bool dfs(const int fr_x, const int fr_y, const int to_x, const int to_y, bool(*vis)[9], const int(*map)[9], const int X, const int Y, const int color, int(*path)[9], const int step, int(*rem)[9])
{
    rem[fr_x][fr_y] = step;
    if (fr_x == to_x && fr_y == to_y) {
        return 1;
    }
    bool ret = 0;
    for (int i = 0;i < 4;++i) {
        int tx = fr_x + DX[i], ty = fr_y + DY[i];
        if (tx < 0 || tx >= X || ty < 0 || ty >= Y || map[tx][ty] != 0 || vis[tx][ty])
            continue;
        vis[tx][ty] = 1;
        if ((rem[tx][ty] == -1 || rem[tx][ty] > step + 1) && dfs(tx, ty, to_x, to_y, vis, map, X, Y, color, path, step + 1, rem)) {
            path[fr_x][fr_y] = tx * Y + ty;
            ret = 1;
            //return 1;
        }
        vis[tx][ty] = 0;
    }
    return ret;
}
bool judge_transverse(int(*map)[9], const int X, const int Y, const int x, const int y)
{
    for (int j = y;j < y + 5;++j)
        if (map[x][j] != map[x][y])
            return 0;
    return 1;
}
bool judge_portrait(int(*map)[9], const int X, const int Y, const int x, const int y)
{
    for (int i = x;i < x + 5;++i)
        if (map[i][y] != map[x][y])
            return 0;
    return 1;
}
bool judge_diagonal1(int(*map)[9], const int X, const int Y, const int x, const int y)
{
    for (int k = 1;k < 5;++k)
        if (map[x + k][y + k] != map[x][y])
            return 0;
    return 1;
}
bool judge_diagonal2(int(*map)[9], const int X, const int Y, const int x, const int y)
{
    for (int k = 1;k < 5;++k)
        if (map[x - k][y + k] != map[x][y])
            return 0;
    return 1;
}
int judge(int(*map)[9], const int X, const int Y, int* cnt_color, bool show)
{
    for (int i = 0;i < X;++i)
        for (int j = 0;j < Y;++j) {
            if (map[i][j] == 0 || cnt_color[map[i][j]] < 5)
                continue;
            if (j + 4 < Y && judge_transverse(map, X, Y, i, j)) {
                cnt_color[map[i][j]] -= 5;
                cnt_color[0] -= 5;
                int ret = map[i][j];
                for (int y = j;y < j + 5;++y) {
                    map[i][y] = 0;
                    if (show)
                        cct_showstr(2 + 4 * y, 2 + 2 * i, "  ", 7, 7);
                }
                return ret;
            }
            else if (i + 4 < X && judge_portrait(map, X, Y, i, j)) {
                cnt_color[map[i][j]] -= 5;
                cnt_color[0] -= 5;
                int ret = map[i][j];
                for (int x = i;x < i + 5;++x) {
                    map[x][j] = 0;
                    if (show)
                        cct_showstr(2 + 4 * j, 2 + 2 * x, "  ", 7, 7);
                }
                return ret;
            }
            else if (i + 4 < X && j + 4 < Y && judge_diagonal1(map, X, Y, i, j)) {
                cnt_color[map[i][j]] -= 5;
                cnt_color[0] -= 5;
                int ret = map[i][j];
                for (int k = 0;k < 5;++k) {
                    map[i + k][j + k] = 0;
                    if (show)
                        cct_showstr(2 + 4 * (j + k), 2 + 2 * (i + k), "  ", 7, 7);
                }
                return ret;
            }
            else if (i - 4 >= 0 && j + 4 < Y && judge_diagonal2(map, X, Y, i, j)) {
                cnt_color[map[i][j]] -= 5;
                cnt_color[0] -= 5;
                int ret = map[i][j];
                for (int k = 0;k < 5;++k) {
                    map[i - k][j + k] = 0;
                    if (show)
                        cct_showstr(2 + 4 * (j + k), 2 + 2 * (i - k), "  ", 7, 7);
                }
                return ret;
            }
        }
    return 0;
}

const int TYPE = 7;
void init_cnt_color(int(*map)[9], const int X, const int Y, int* cnt_color)
{
    for (int i = 0;i <= TYPE;++i)
        cnt_color[i] = 0;
    for (int i = 0;i < X;++i)
        for (int j = 0;j < Y;++j)
            if (map[i][j] != 0)
                ++cnt_color[map[i][j]];
    for (int i = 1;i <= TYPE;++i)
        cnt_color[0] += cnt_color[i];
}