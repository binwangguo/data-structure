#pragma once

#include<graphics.h>
#include"constant.h"
#include"statement.h"


void close_jd(MGraph *g){
	int t = 0, o = 0;
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && button_judge(m.x, m.y, g)){
			t = button_judge(m.x, m.y, g);
			g->vexs[t - 1].close = INFINITY;
			InputBox(g->vexs[t - 1].reason, 100, "�����뾰��ر�ԭ��");
			o = 1;
		}
		if (o == 1) break;
	}
}

void open_jd(MGraph *g){
	int t = 0, o = 0;
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && button_judge(m.x, m.y, g)){
			t = button_judge(m.x, m.y, g);
			if (g->vexs[t - 1].close == INFINITY){
				g->vexs[t - 1].close = 0;
				MessageBox(GetHWnd(), "�����Իָ�5", "�ָ�����", MB_OK);

			}
			else
				MessageBox(GetHWnd(), "����δ���ر�", "�ָ�����", MB_OK);
			o = 1;
		}
		if (o == 1) break;
	}
}

void set_anounce(){

	char info[200];
	FILE * wf;
	wf = fopen("Information.txt", "at+");
	if (wf)
	{
		InputBox(info, 200, "�����빫�����ݣ�");
		fprintf(wf, "%s\n", info);
		fclose(wf);
	}
	fclose(wf);
}

void get_anounce(){
	int i = 1;
	char info[200];
	string res;
	FILE *rf;
	rf = fopen("Information.txt", "r");
	if (rf){
		while (!feof(rf)){
			fscanf(rf, "%c", &info[i]);
			if (i)
			res += info[i];
			i++;
		}
		res.pop_back();
	}
	MessageBox(GetHWnd(), res.c_str(), "����", MB_OK);
}