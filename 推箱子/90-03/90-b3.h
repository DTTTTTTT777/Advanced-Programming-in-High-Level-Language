/*2152402 软件 段婷婷*/
#pragma once

//主菜单函数，放在90-b3-main.cpp中------------------------------------------------------------------
int menu();  //显示主菜单并返回用户选择

//和弹出式菜单相关的函数，放在90-b3-popmenu.cpp中-----------------------------------------------
void show_popmenu(char(*file)[4], int n, int beg, int cur);  //显示弹出式菜单
void choose_levels(char(*file)[4], int n);  //选择关卡（光标上下移动并更新弹出式菜单）

//内部数组方式实现的各函数，放在90-b3-base.cpp中-------------------------------------------------
bool open_stage();  //判断stage文件夹能否打开
int read_stage();  //读取stage文件夹中的文件
void read_file(char* name);  //读取选择关卡对应的文件

//和cmd图形界面方式显示相关的函数，放在90-b3-console.cpp中-------------------------------------
bool show_graph(char* s, int row, char* name); //显示第row行的图形

//辅助函数，放在90-b3-base.cpp中
void wait_for_enter();
void wait_for_end();