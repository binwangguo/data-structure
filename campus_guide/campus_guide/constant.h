#pragma once

#include<iostream>
#include<graphics.h>

using namespace std;

#define INFINITY 10000
#define M 20

const int ROOT = -1;		
const int COILA = 1;		

const short win_width = 1500;
const short win_heigh = 745;

const int r[3][4] = { { 550, 200, 950, 300 }, { 550, 400, 950, 500 }, { 550, 50, 950, 150 } };
const int r2[7][4] = { { 1390, 30, 1490, 70 }, { 1390, 120, 1490, 160 }, { 1390, 210, 1490, 250 }, { 1390, 300, 1490, 340 }, { 1390, 390, 1490, 430 }, { 1390, 470, 1490, 510 } ,{1390,650,1490,700} };
const int r3[4][4] = { { 1390, 30, 1490, 70 }, { 1390, 120, 1490, 160 }, {1390,210,1490,250}, { 1390, 650, 1490, 700 } };

const char jd[M][10] = { "1.jpg", "2.jpg", "3.jpg", "4.jpg", "5.jpg", "6.jpg", "7.jpg", "8.jpg", "9.jpg", "10.jpg", "11.jpg", "12.jpg"};

typedef struct vexs{
	int num;
	char name[20];
	char intro[200];

	int close;                                               
	char reason[100];                                        
	int x, y;
};
typedef int edgtype;
typedef struct MGraph{
	vexs vexs[M];
	edgtype edge[M][M];
	int vexNum, edgNum;
}MGraph;

