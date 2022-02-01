#pragma once

void Creat_Map(MGraph *g); 

int login(MGraph *g); 

void draw_locate(MGraph *g); 
void draw_path(MGraph *g, int v1, int v2); 
void delet_path(MGraph *g, int v1, int v2); 
void background(MGraph *g); 

void search(MGraph* g); 

void two_locate(MGraph *g); 
void more_locate(MGraph *g); 
void short_path_floyd(MGraph *g);
void short_path(MGraph *g, int sNum, int eNum);
void enter_path(MGraph *g, int sNum, int eNum);
void shortpath_print(MGraph *g);
void morepath_print(MGraph *g);
void morepath_msg(MGraph *g);

int button_judge(int x, int y, MGraph *G); 
int button_judge1(int x, int y); 
int button_judge2(int x, int y); 
int button_judge3(int x, int y); 
int button_judge4(int x, int y); 

void coila_query(MGraph *g); 
void all_path(MGraph *g); 
void Dfs_Print(MGraph *g, int sNum, int eNum);

void close_jd(MGraph *g); 
void open_jd(MGraph *g); 
void set_anounce(); 
void get_anounce(); 