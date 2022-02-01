#pragma once

#include<iostream>
#include<string>
#include"constant.h"
#include"statement.h"

/*景点信息查询*/
void Search_Location(MGraph *g, int s) {
	IMAGE JD;
	loadimage(&JD, LPCTSTR(jd[s-1]), 500, 258);
	if (s==11||s==12){
		putimage(g->vexs[s - 1].x - 500, g->vexs[s - 1].y - 258, &JD);
	}
	else if (s == 10){
		putimage(g->vexs[s - 1].x - 500, g->vexs[s - 1].y, &JD);
	}
	else if (s == 1){
		putimage(g->vexs[s - 1].x , g->vexs[s - 1].y-258, &JD);
	}
	else{
		putimage(g->vexs[s - 1].x, g->vexs[s - 1].y, &JD);
	}

	string jd_res = "景点名称：";
	jd_res += g->vexs[s - 1].name;
	jd_res += "\n景点简介：";
	jd_res += g->vexs[s - 1].intro;
	MessageBox(GetHWnd(), jd_res.c_str(), "查询景点信息", MB_OK);
	system("pause");
	background(g);
}


void search(MGraph *g){
	char s[10];
	int i;
	int N = 1;
	string res = "景点已关闭.\n关闭原因：";
	InputBox(s, 10, "请输入要查询的景点：");
	for (i = 0; i < g->vexNum; i++){
		if (strcmp(s, g->vexs[i].name) == 0){
			if (g->vexs[i].close == INFINITY){
				res += g->vexs[i].reason;
				N = 0;
				MessageBox(GetHWnd(), res.c_str(), NULL, MB_OK);
			}
			break;
		}
	}
	if (i == g->vexNum)
		MessageBox(GetHWnd(), "无此景点", NULL, MB_OK);
	else if (N)
		Search_Location(g, i+1);
}

