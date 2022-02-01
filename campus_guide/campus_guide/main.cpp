#pragma once

#include <iostream>
#include <graphics.h>
#include "constant.h"
#include "statement.h"


using namespace std;

int main(){
	initgraph(win_width, win_heigh);
	for (int i = 0; i < 256; i += 5){
		setbkcolor(RGB(i, i, i));
		cleardevice();
		Sleep(30);
	}
	MGraph g;
	Creat_Map(&g);
	short_path_floyd(&g);
	login(&g);
	system("pause");
	closegraph();
	return 0;
}