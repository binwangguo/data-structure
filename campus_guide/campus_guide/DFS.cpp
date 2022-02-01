#pragma once;

#include<iostream>
#include<graphics.h>
#include<string>
#include<vector>
#include"constant.h"
#include"statement.h"

using namespace std;

int pathStack[M];                                                            
int top;                                                                      
int visited[M];                                                               
int cnt = 1;                                                                    
string paths_res;
void Dfs_Print(MGraph *g, int sNum, int eNum) {
	int dis = 0;                                                              
	pathStack[top] = sNum;                                                    
	top++;
	visited[sNum] = 1;                                                       
	for (int i = 0; i < g->vexNum; i++) {
		if (g->edge[sNum][i] > 0 && g->edge[sNum][i] != INFINITY && !visited[i]) {
			
			if (i == eNum) {                                                  
				paths_res += "第";
				paths_res += to_string(cnt++);
				paths_res += "条路：";
				for (int j = 0; j < top; j++) {
					paths_res += g->vexs[pathStack[j]].name;
					paths_res += "->";
					if (j < top - 1)
						dis = dis + g->edge[pathStack[j]][pathStack[j + 1]];        
				}
				dis = dis + g->edge[pathStack[top - 1]][eNum];                      
				paths_res += g->vexs[eNum].name;
				paths_res += "\n总长度(m)：";
				paths_res += to_string(dis);
				paths_res += "\n";

			}
			else {
				Dfs_Print(g, i, eNum);                                              
				top--;                                                              
				visited[i] = 0;                                                    
			}
		}
	}
}

void all_path(MGraph *g){
	cnt = 1;                                                       
	top = 0;                                                         
	memset(pathStack, 0, sizeof(pathStack));                         
	memset(visited, 0, sizeof(visited));                             
	MOUSEMSG m;
	vector<int> v;
	while (true){
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && button_judge(m.x, m.y, g)){
			int t = button_judge(m.x, m.y, g);
			MessageBox(GetHWnd(), g->vexs[t - 1].name, "选择", MB_OK);
			v.push_back(t-1);
			FlushMouseMsgBuffer();
		}
		if (v.size() == 2)
			break;
	}
	Dfs_Print(g, v[0], v[1]);
	MessageBox(GetHWnd(), paths_res.c_str(), "所有路径", MB_OK);
	paths_res.clear();
}


int visi[M], coila[M] = { 0 };		
int coiloNum;		
void dfs_coila(MGraph *g, int i){
	int child = 0;	
	if (visi[i] != ROOT)
		visi[i] = 1;
	for (int j = 0; j < g->vexNum; j++){
		if (g->edge[i][j] != 0 && g->edge[i][j] != INFINITY&&!visi[j])
		{				
			child++;	
			dfs_coila(g, j);
		}
	}
	if (visi[i] == ROOT&&child >= 2)
	{
		coiloNum++;			
		coila[i] = COILA;	
	}
}

void coila_query(MGraph *g){
	string res = "关节点个数为：";
	coiloNum = 0;							
	for (int i = 0; i < g->vexNum; i++){	
		memset(visi, 0, sizeof(visi));		
		visi[i] = ROOT;						
		dfs_coila(g, i);					
	}
	res += to_string(coiloNum);
	res += "\n分别为：";
	for (int i = 0; i < g->vexNum; i++){
		if (coila[i] == COILA){
			res += g->vexs[i].name;
			res += "、";
		}
	}
	MessageBox(GetHWnd(), res.c_str(), "关节点查询", MB_OK);
}