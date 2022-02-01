#pragma once

#include <iostream>
#include "constant.h"

using namespace std;

void Creat_Map(MGraph *g){
	int i, j, k, e;
	FILE *rf;
	rf = fopen("map.txt", "r");
	if (rf){
		fscanf(rf, "%d%d", &g->vexNum, &g->edgNum);
		for (i = 0; i < g->vexNum; i++)
			fscanf(rf, "%d%s%s%d%d", &g->vexs[i].num, &g->vexs[i].name, &g->vexs[i].intro, &g->vexs[i].x, &g->vexs[i].y);
		for (i = 0; i < g->vexNum; i++){
			for (j = 0; j < g->vexNum; j++){
				if (i == j)
					g->edge[i][j] = 0;
				else
					g->edge[i][j] = INFINITY;
			}
		}
		for (k = 0; k < g->edgNum; k++){
			fscanf(rf, "%d%d%d", &i, &j, &e);
			g->edge[i][j] = g->edge[j][i] = e;
		}
		fclose(rf);
	}
	else
		g->edgNum = 0;
}