#pragma once

#include<iostream>
#include<Windows.h>
#include<graphics.h>
#include<vector>
#include"constant.h"
#include"statement.h"

using namespace std;

void two_locate(MGraph *g){
	MOUSEMSG m;
	vector<int> v;
	while (true){
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && button_judge(m.x,m.y,g)){
			int t = button_judge(m.x, m.y, g);
			MessageBox(GetHWnd(), g->vexs[t-1].name, "选择", MB_OK);
			v.push_back(t);
			FlushMouseMsgBuffer();
		}
		if (v.size() == 2)
			break;
	}
	enter_path(g, v[0] - 1, v[1] - 1);
	shortpath_print(g);
}

void more_locate(MGraph *g){
	MOUSEMSG m;
	vector<int> v;
	char d[2];
	InputBox(d, 2, "请输入所经过景点个数(大于等于2)：");
	int s = d[0]-48;
	if (s <2){
		MessageBox(GetHWnd(), "输入错误", NULL, MB_OK);
		return;
	}
	while (true){
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && button_judge(m.x, m.y, g)){
			int t = button_judge(m.x, m.y, g);
			MessageBox(GetHWnd(), g->vexs[t - 1].name, "选择", MB_OK);
			v.push_back(t);
		}
		if (v.size() == s)
			break;
	}
	for (int i = 0; i < v.size()-1; i++){
		enter_path(g, v[i] - 1, v[i+1] - 1);
		morepath_print(g);
	}
	morepath_msg(g);
}