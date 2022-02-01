#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"constant.h"
#include"statement.h"

using namespace std;

int dist[M][M];                                                    
int path[M][M];                                                    
void short_path_floyd(MGraph *g) {
	int i, j, k;
	for (i = 0; i < g->vexNum; i++)                                
		for (j = 0; j < g->vexNum; j++) {
		dist[i][j] = g->edge[i][j];
		if (i != j && dist[i][j] < INFINITY) path[i][j] = i;
		else path[i][j] = -1;                                  
		}
	for (k = 0; k < g->vexNum; k++)                                
		for (i = 0; i < g->vexNum; i++)
			for (j = 0; j < g->vexNum; j++)                        
				if (dist[i][j] >(dist[i][k] + dist[k][j])) {
		dist[i][j] = dist[i][k] + dist[k][j];
		path[i][j] = k;                                
				}
}

vector<int> path_res;
string ws_res;
void short_path(MGraph *g, int sNum, int eNum){
	if (path[sNum][eNum] == -1 || path[sNum][eNum] == eNum || path[sNum][eNum] == sNum)
		return;
	else {
		short_path(g, sNum, path[sNum][eNum]);                 
		path_res.push_back(g->vexs[path[sNum][eNum]].num - 1);
		ws_res += g->vexs[path[sNum][eNum]].name;
		ws_res += "->";
		short_path(g, path[sNum][eNum], eNum);                 
	}
}
void enter_path(MGraph *g, int sNum, int eNum){
	path_res.push_back(sNum);
	ws_res += g->vexs[sNum].name;
	ws_res += "->";
	short_path(g, sNum, eNum);
	path_res.push_back(eNum);
	ws_res += g->vexs[eNum].name;
	ws_res += "\n\n全长(m)：";
	ws_res += to_string(dist[sNum][eNum]);
	ws_res += "\n\n";
}

void shortpath_print(MGraph *g){
	for (int i = 0; i < path_res.size() - 1; i++) {
		draw_path(g, path_res[i], path_res[i + 1]);
	}
	MessageBox(GetHWnd(), ws_res.c_str(), "最短路径", MB_OK);
	system("pause");
	for (int i = 0; i < path_res.size() - 1; i++) {
		delet_path(g, path_res[i], path_res[i + 1]);
	}
	path_res.clear();
	ws_res.clear();
}

void morepath_print(MGraph *g){
	for (int i = 0; i < path_res.size() - 1; i++){
		draw_path(g, path_res[i], path_res[i + 1]);
	}
}
void morepath_msg(MGraph *g){
	MessageBox(GetHWnd(), ws_res.c_str(), "最佳路径", MB_OK);
	system("pause");
	for (int i = 0; i < path_res.size() - 1; i++) {
		delet_path(g, path_res[i], path_res[i + 1]);
	}
	path_res.clear();
	ws_res.clear();
}