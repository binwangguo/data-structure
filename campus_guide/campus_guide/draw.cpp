#pragma once

#include <iostream>
#include <graphics.h>
#include "constant.h"

using namespace std;

void draw_locate(MGraph *g){
	for (int i = 0; i < g->vexNum; i++){
		setfillcolor(RED);
		fillcircle(g->vexs[i].x, g->vexs[i].y, 5);
	}
}
void draw_path(MGraph *g, int v1, int v2){
	setrop2(R2_BLACK);
	setlinecolor(RED);
	setlinestyle(PS_DASH);
	line(g->vexs[v1].x, g->vexs[v1].y, g->vexs[v2].x, g->vexs[v2].y);
}
void delet_path(MGraph *g, int v1, int v2){
	setrop2(R2_WHITE);
	setlinecolor(WHITE);
	setlinestyle(PS_DASH);
	line(g->vexs[v1].x, g->vexs[v1].y, g->vexs[v2].x, g->vexs[v2].y);
}

void background(MGraph *g){
	IMAGE BJ;
	loadimage(&BJ, "µØÍ¼.jpg", 1248, 745);
	putimage(0, 0, &BJ);
	draw_locate(g);
}
