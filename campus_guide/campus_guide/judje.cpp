#pragma once

#include<iostream>
#include"constant.h"

//�ж�������ڵ�¼�����λ��
int button_judge2(int x,int y){
	if (x > r[0][0] && x<r[0][2] && y>r[0][1] && y<r[0][3])
		return 1;
	if (x > r[1][0] && x<r[1][2] && y>r[1][1] && y<r[1][3])
		return 2;
	return 0;
}

//�ж�������ڹ���Ա�����λ��
int button_judge3(int x, int y){
	if (x > r3[0][0] && x<r3[0][2] && y>r3[0][1] && y<r3[0][3])
		return 1;
	if (x > r3[1][0] && x<r3[1][2] && y>r3[1][1] && y<r3[1][3])
		return 2;
	if (x > r3[2][0] && x<r3[2][2] && y>r3[2][1] && y<r3[2][3])
		return 3;
	if (x > r3[3][0] && x<r3[3][2] && y>r3[3][1] && y < r3[3][3])
		return 4;
	return 0;
}

//�ж���������οͽ����λ��
int button_judge4(int x, int y){
	if (x > r2[0][0] && x<r2[0][2] && y>r2[0][1] && y<r2[0][3])
		return 1;
	if (x > r2[1][0] && x<r2[1][2] && y>r2[1][1] && y<r2[1][3])
		return 2;
	if (x > r2[2][0] && x<r2[2][2] && y>r2[2][1] && y<r2[2][3])
		return 3;
	if (x > r2[3][0] && x<r2[3][2] && y>r2[3][1] && y<r2[3][3])
		return 4;
	if (x > r2[4][0] && x<r2[4][2] && y>r2[4][1] && y<r2[4][3])
		return 5;
	if (x > r2[5][0] && x<r2[5][2] && y>r2[5][1] && y<r2[5][3])
		return 6;
	if (x > r2[6][0] && x<r2[6][2] && y>r2[6][1] && y < r2[6][3])
		return 7;
	return 0;
}

//�ж�����Ƿ��ڵ�ͼ�еص��λ��
int button_judge(int x, int y, MGraph *g)
{
	for (int i = 0; i < g -> vexNum; i++)
	{
		if (x > g->vexs[i].x - 40 && x < g->vexs[i].x + 40 && y > g->vexs[i].y - 40 && y < g->vexs[i].y + 40)
			return i + 1;
	}
	return 0;
}

//�ж�����Ƿ������ӻ���ɾ���ص�Ĵ��ڴ�
int button_judge1(int x, int y)
{
	if (x > r2[0][0] && x < r2[0][2] && y > r2[0][1] && y < r2[0][3])return 1;
	if (x > r2[1][0] && x < r2[1][2] && y > r2[1][1] && y < r2[1][3])return 2;
	return 0;
} 

