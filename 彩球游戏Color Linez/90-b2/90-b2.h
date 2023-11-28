/*2152402 软件 段婷婷*/
#pragma once

//公用函数部分：函数实现在90-b2-tools.cpp
void input_XY(int& X, int& Y);
void init_cnt_color(int(*map)[9], const int X, const int Y, int* cnt_color);
void init_balls(int(*map)[9], const int X, const int Y, const int cnt);

bool dfs(const int fr_x, const int fr_y, const int to_x, const int to_y, bool(*vis)[9], const int(*map)[9], const int X, const int Y, const int color, int(*path)[9], const int step, int(*rem)[9]);

bool judge_transverse(int(*map)[9], const int X, const int Y, const int x, const int y);
bool judge_portrait(int(*map)[9], const int X, const int Y, const int x, const int y);
bool judge_diagonal1(int(*map)[9], const int X, const int Y, const int x, const int y);
bool judge_diagonal2(int(*map)[9], const int X, const int Y, const int x, const int y);
int judge(int(*map)[9], const int X, const int Y, int* cnt_color, bool show = 0);
void new_balls(int(*map)[9], const int X, const int Y, const int cnt, const int* next_color, int* cnt_color, bool show);

void wait_for_end();
void wait_for_enter(const char* s);
void chlwr(char& ch);

//内部数组方式实现的函数
void sol_for_opt1();
void sol_for_opt2();
void basic_solution();

void input_move(int& fr_x, int& fr_y, int& to_x, int& to_y, const int X, const int Y, const int(*map)[9]);
void output_map(int(*map)[9], const int X, const int Y, int tag);
void output_vis(bool(*vis)[9], const int X, const int Y);
void output_path(int(*map)[9], bool(*vis)[9], const int X, const int Y);
bool move(const int fr_x, const int fr_y, const int to_x, const int to_y, int(*map)[9], const int X, const int Y, const int* next_color, int* cnt_color);

//cmd图形界面方式实现的函数
void draw_for_opt4();
void draw_for_opt5();
void draw_for_opt6();
void complete_solution();

void show_graph(const int(*map)[9], const int X, const int Y, const int COL, const int ROW);
void show_graph1(const int(*map)[9], const int X, const int Y);
void move_by_path(const int fr_x, const int fr_y, const int to_x, const int to_y, bool(*vis)[9], int(*map)[9], const int X, const int Y, int(*path)[9]);

void show_points(const int x, const int y, const int points);
void show_next_color(const int x, const int y, const int* next_color);
void show_proportion(const int x, const int y, const int* cnt_color, const int cnt_tot, const int* cnt_delete);