/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include "cmd_console_tools.h"
#include "90-b2.h"

using namespace std;
const int TYPE = 7;

void show_graph1(const int(*map)[9], const int X, const int Y)
{
    cct_cls();
    const int COL = 50, ROW = 20;
    cct_setconsoleborder(COL, ROW, COL, ROW);
    cct_gotoxy(0, 0);
    cout << "屏幕：" << ROW << "行" << COL << "列";
    cct_setfontsize("新宋体", 40, 20);
    int x = 1, y = 0;
    cct_showstr(y, x, "╔", 7, 0, 1, 2);
    for (int j = 0;j <= Y;++j) {
        y += 2;
        cct_showstr(y, x, "═", 7, 0, 1, 3);
    }
    cct_showstr(y, x, "╗", 7, 0, 1, 3);

    for (int i = 0;i < X;++i) {
        ++x;
        y = 0;
        cct_showstr(y, x, "║", 7, 0, 1, 3);
        for (int j = 0;j < Y;++j) {
            y += 2;
            if (map[i][j] == 0)
                cct_showstr(y, x, " ", 7, 0, 1, 3);
            else
                cct_showstr(y, x, "○", map[i][j] + 7, 7, 1);
        }
        y += 2;
        cct_showstr(y, x, "║", 7, 0, 1, 3);
    }
    ++x;
    y = 0;
    cct_showstr(y, x, "╚", 7, 0, 1, 3);
    for (int j = 0;j <= Y;++j) {
        y += 2;
        cct_showstr(y, x, "═", 7, 0, 1, 3);
    }
    cct_showstr(y, x, "╝", 7, 0, 1, 3);
}
void show_graph(const int(*map)[9], const int X, const int Y, const int COL, const int ROW)
{
    cct_cls();
    cct_setconsoleborder(COL, ROW, COL, ROW + 1000);
    cct_gotoxy(0, 0);
    cout << "屏幕：" << ROW << "行" << COL << "列";
    cct_setfontsize("新宋体", 26, 13);
    int x = 1, y = 0;
    cct_showstr(y, x, "╔", 7, 0, 1);
    y += 2;
    cct_showstr(y, x, "═╦", 7, 0, Y - 1);
    y += 4 * (Y - 1);
    cct_showstr(y, x, "═╗", 7, 0, 1);
    for (int i = 0;i < X - 1;++i) {
        ++x;
        y = 0;
        cct_showstr(y, x, "║  ", 7, 0, Y);
        y += (Y) * 4 - 1;
        cct_showstr(y, x, " ║", 7, 0, 1);
        ++x;
        y = 0;
        cct_showstr(y, x, "╠", 7, 0, 1);
        y += 2;
        cct_showstr(y, x, "═╬", 7, 0, Y - 1);
        y += (Y - 1) * 4;
        cct_showstr(y, x, "═╣", 7, 0, 1);
    }
    ++x;
    y = 0;
    cct_showstr(y, x, "║  ", 7, 0, Y);
    y += (Y) * 4 - 1;
    cct_showstr(y, x, " ║", 7, 0, 1);
    ++x;
    y = 0;
    cct_showstr(y, x, "╚", 7, 0, 1);
    y += 2;
    cct_showstr(y, x, "═╩", 7, 0, Y - 1);
    y += 4 * (Y - 1);
    cct_showstr(y, x, "═╝", 7, 0, 1);
    for (int i = 0;i < X;++i)
        for (int j = 0;j < Y;++j)
            if (map[i][j] != 0) {
                cct_showstr(2 + 4 * j, 2 + 2 * i, "○", 7 + map[i][j], 7);
            }
    cct_gotoxy(0, 2 * X + 1);
}
void draw_for_opt4()
{
    int map[9][9], X, Y;
    memset(map, 0, sizeof(map));
    input_XY(X, Y);
    init_balls(map, X, Y, 5);
    output_map(map, X, Y, 0);

    wait_for_enter("按回车键显示图形...");
    show_graph1(map, X, Y);
    wait_for_end();
}

void draw_for_opt5()
{
    int map[9][9], X, Y;
    memset(map, 0, sizeof(map));
    input_XY(X, Y);
    init_balls(map, X, Y, 5);
    output_map(map, X, Y, 0);

    wait_for_enter("按回车键显示图形...");
    show_graph(map, X, Y, 50, 25);
    wait_for_end();
}

void draw_for_opt6()
{
    int map[9][9], X, Y, path[9][9], rem[9][9];
    bool vis[9][9];
    memset(map, 0, sizeof(map));

    input_XY(X, Y);
    init_balls(map, X, Y, int(X * Y * 0.6));
    show_graph(map, X, Y, 50, 25);
    cct_enable_mouse();
    cct_setcursor(CURSOR_INVISIBLE);
    int X1 = 0, Y1 = 0, ret, maction, keycode1, keycode2;
    int fr_x = -1, fr_y = -1, to_x, to_y;
    bool tag = 0;
    while (1) {
        while (1) {
            ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);
            if (ret == CCT_MOUSE_EVENT) {
                cct_gotoxy(0, X * 2 + 1);
                int x = (Y1 - 2) / 2, y = (X1 - 2) / 4;
                cct_setcolor();
                if (x < X && y < Y)
                    cout << endl << "[当前光标] " << char('A' + x) << "行" << char('1' + y) << "列";
                if (maction == MOUSE_LEFT_BUTTON_CLICK && (map[x][y] || tag)) {
                    if (map[x][y] != 0) {
                        if (fr_x != -1) {
                            cct_showstr(2 + 4 * fr_y, 2 + 2 * fr_x, "○", 7 + map[fr_x][fr_y], 7);
                        }
                        fr_x = x;
                        fr_y = y;
                        cct_showstr(2 + 4 * fr_y, 2 + 2 * fr_x, "◎", 7 + map[fr_x][fr_y], 7);
                        tag = 1;
                    }
                    if (tag && map[x][y] == 0) {
                        to_x = x;
                        to_y = y;
                        break;
                    }
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(path, -1, sizeof(path));
        memset(rem, -1, sizeof(rem));
        if (dfs(fr_x, fr_y, to_x, to_y, vis, map, X, Y, map[fr_x][fr_y], path, 0, rem)) {
            move_by_path(fr_x, fr_y, to_x, to_y, vis, map, X, Y, path);
            cct_gotoxy(0, X * 2 + 2);
            cct_setcolor();
            
            break;
        }
        else {
            cct_setcolor();
            cct_gotoxy(0, X * 2 + 3);
            cout << "[错误] 无法从[" << char('A' + fr_x) << char('1' + fr_y) << "]移到[" << char('A' + to_x) << char('1' + to_y) << "]";
            Sleep(300);
            cct_gotoxy(0, X * 2 + 3);
            cout << setw(30) << " ";
        }
    }
    cct_gotoxy(0, X * 2 + 1);
    cct_setcolor();
    
    wait_for_end();
}
void move_by_path(const int fr_x, const int fr_y, const int to_x, const int to_y, bool(*vis)[9], int(*map)[9], const int X, const int Y, int(*path)[9])
{
    map[to_x][to_y] = map[fr_x][fr_y];
    map[fr_x][fr_y] = 0;
    int cur_x = fr_x, cur_y = fr_y;
    int last_x = -1, last_y = -1;
    while (1) {
        int d_x = 0, d_y = 0;
        if (last_x != -1 && last_y != -1) {
            d_x = last_x - cur_x;
            d_y = last_y - cur_y;
        }
        cct_showstr(2 + 4 * cur_y + d_y * 2, 2 + 2 * cur_x + d_x, "◎", 7 + map[to_x][to_y], 7);
        Sleep(10);
        if (d_y != 0)
            cct_showstr(2 + 4 * cur_y + d_y * 2, 2 + 2 * cur_x + d_x, "║", 7, 0);
        else if (d_x != 0)
            cct_showstr(2 + 4 * cur_y + d_y, 2 + 2 * cur_x + d_x, "═", 7, 0);

        cct_showstr(2 + 4 * cur_y, 2 + 2 * cur_x, "◎", 7 + map[to_x][to_y], 7);
        Sleep(10);
        if (cur_x == to_x && cur_y == to_y)
            break;
        cct_showstr(2 + 4 * cur_y, 2 + 2 * cur_x, "  ", 7, 7);
        last_x = cur_x;
        last_y = cur_y;
        int tmp = path[cur_x][cur_y];
        if (tmp < 0) break;
        cur_y = tmp % Y;
        cur_x = (tmp - cur_y) / Y;
    }
    cct_showstr(2 + 4 * to_y, 2 + 2 * to_x, "○", 7 + map[to_x][to_y], 7);

    cct_gotoxy(0, X * 2 + 2);
    cct_setcolor();
}
void show_points(const int x, const int y, const int points) 
{
    cct_showstr(y, x, "╔═════╗", 7, 0);
    cct_showstr(y, x + 1, "║得分：    ║", 7, 0);
    cct_showstr(y, x + 2, "╚═════╝", 7, 0);
    cct_showint(y + 9, x + 1, points, 7, 0);
}
void show_next_color(const int x, const int y, const int* next_color)
{
    cct_showstr(y, x, "╔═╦═╦═╗", 7, 0);
    cct_showstr(y, x + 1, "║  ║  ║  ║", 7, 0);
    cct_showstr(y, x + 2, "╚═╩═╩═╝", 7, 0);
    for (int i = 0;i < 3;++i){
        int col = next_color[i];
        cct_showstr(y + 2 + 4 * i, x + 1, "○", 7 + col, 7);
    }
}
void show_proportion(const int x, const int y, const int* cnt_color, const int cnt_tot, const int* cnt_delete)
{
    cct_showstr(y, x, "╔═══════════╗", 7, 0);
    for (int i = 0;i <= TYPE;++i) {
        cct_showstr(y, x + i + 1, "║                      ║", 7, 0);
        cct_showstr(y + 2, x + i + 1, "○", 7 + i, 7);
        cct_showstr(y + 4, x + i + 1, ":", 7, 0);
        int cnt = i == 0 ? (cnt_tot - cnt_color[0]) : cnt_color[i];
        if (cnt < 10) {
            cct_showstr(y + 5, x + i + 1, "0", 7, 0);
            cct_showint(y + 6, x + i + 1, cnt, 7, 0);
        }
        else
            cct_showint(y + 5, x + i + 1, cnt, 7, 0);
        double pro = 1.0 * cnt / cnt_tot;
        char pro_s[15];
        pro_s[0] = '/';
        pro_s[1] = '(';
        if (int(pro * 10) % 10 == 0)
            pro_s[2] = '0';
        else pro_s[2] = '0' + (int(pro * 10) % 10);
        pro_s[3] = '0' + (int(pro * 100) % 10);
        pro_s[4] = '.';
        pro_s[5] = '0' + (int(pro * 1000) % 10);
        pro_s[6] = '0' + (int(pro * 10000) % 10);
        pro_s[7] = '%';
        pro_s[8] = ')';
        pro_s[9] = '\0';
        cct_showstr(y + 7, x + i + 1, pro_s, 7, 0);
        cct_showstr(y + 15, x + i + 1, ") 消除-", 7, 0);
        cct_showint(y + 22, x + i + 1, cnt_delete[i], 7, 0);
        
    }
    cct_showstr(y, x + 9, "╚═══════════╝", 7, 0);

}
void complete_solution()
{
    int map[9][9], X, Y;
    int next_color[3], cnt_color[TYPE + 1], cnt_delete[TYPE + 1];
    int points = 0;
    int rem[9][9], path[9][9];
    bool vis[9][9];
    memset(map, 0, sizeof(map));

    input_XY(X, Y);
    init_balls(map, X, Y, 5);
    show_graph(map, X, Y, 70, 25);
    init_cnt_color(map, X, Y, cnt_color);
    cct_enable_mouse();
    cct_setcursor(CURSOR_INVISIBLE);
    for (int i = 0;i < 3;++i) 
        next_color[i] = rand() % TYPE + 1;
    for (int i = 0;i <= TYPE;++i)
        cnt_delete[i] = 0;

    int X1 = 0, Y1 = 0, ret, maction, keycode1, keycode2;
    int fr_x = -1, fr_y = -1, to_x, to_y;
    bool tag = 0;

    while (cnt_color[0] < X * Y && cnt_color[0] > 0) {
        show_points(1, 4 * Y + 4, points);
        show_next_color(5, 4 * Y + 4, next_color);
        show_proportion(9, 4 * Y + 4, cnt_color, X * Y, cnt_delete);

        while (1) {
            ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);
            if (ret == CCT_MOUSE_EVENT) {
                cct_gotoxy(0, X * 2 + 1);
                int x = (Y1 - 2) / 2, y = (X1 - 2) / 4;
                cct_setcolor();
                if (x < X && y < Y)
                    cout << endl << "[当前光标] " << char('A' + x) << "行" << char('1' + y) << "列";
                if (maction == MOUSE_LEFT_BUTTON_CLICK && (map[x][y] || tag)) {
                    if (map[x][y] != 0) {
                        if (fr_x != -1) {
                            cct_showstr(2 + 4 * fr_y, 2 + 2 * fr_x, "○", 7 + map[fr_x][fr_y], 7);
                        }
                        fr_x = x;
                        fr_y = y;
                        cct_showstr(2 + 4 * fr_y, 2 + 2 * fr_x, "◎", 7 + map[fr_x][fr_y], 7);
                        tag = 1;
                    }
                    if (tag && map[x][y] == 0) {
                        to_x = x;
                        to_y = y;
                        break;
                    }
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        memset(path, -1, sizeof(path));
        memset(rem, -1, sizeof(rem));

        if (dfs(fr_x, fr_y, to_x, to_y, vis, map, X, Y, map[fr_x][fr_y], path, 0, rem)) {
            move_by_path(fr_x, fr_y, to_x, to_y, vis, map, X, Y, path);
            //break;

            int col = judge(map, X, Y, cnt_color, 1);

            if (col) {
                cnt_delete[col] += 5;
                points += 12;
            }
            else {
                new_balls(map, X, Y, 3, next_color, cnt_color, 1);
                col = judge(map, X, Y, cnt_color, 1);
                if (col) {
                    cnt_delete[col] += 5;
                    points += 12;
                }
            }
            for (int i = 0;i < 3;++i) {
                next_color[i] = rand() % TYPE + 1;
            }
        }
        else {
            cct_setcolor();
            cct_gotoxy(0, X * 2 + 3);
            cout << "[错误] 无法从[" << char('A' + fr_x) << char('1' + fr_y) << "]移到[" << char('A' + to_x) << char('1' + to_y) << "]";
            Sleep(300);
            cct_gotoxy(0, X * 2 + 3);
            cout << setw(30) << " ";
        }

    }
    show_points(1, 4 * Y + 4, points);
    show_next_color(5, 4 * Y + 4, next_color);
    show_proportion(9, 4 * Y + 4, cnt_color, X * Y, cnt_delete);

    cct_gotoxy(0, X * 2 + 4);
    cct_setcolor();

    if (cnt_color[0] != 0)
        cout << "无空位可移，游戏结束！" << endl;
    else
        cout << "无球可移，游戏结束！" << endl;

    wait_for_end();
}


