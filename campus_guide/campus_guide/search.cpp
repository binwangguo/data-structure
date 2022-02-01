#pragma once

#include<iostream>
#include<string>
#include"constant.h"
#include"statement.h"

/*������Ϣ��ѯ*/
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

	string jd_res = "�������ƣ�";
	jd_res += g->vexs[s - 1].name;
	jd_res += "\n�����飺";
	jd_res += g->vexs[s - 1].intro;
	MessageBox(GetHWnd(), jd_res.c_str(), "��ѯ������Ϣ", MB_OK);
	system("pause");
	background(g);
}


void search(MGraph *g){
	char s[10];
	int i;
	int N = 1;
	string res = "�����ѹر�.\n�ر�ԭ��";
	InputBox(s, 10, "������Ҫ��ѯ�ľ��㣺");
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
		MessageBox(GetHWnd(), "�޴˾���", NULL, MB_OK);
	else if (N)
		Search_Location(g, i+1);
}

