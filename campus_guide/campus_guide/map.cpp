#pragma once;

#include"constant.h";
#include"statement.h"


void map(MGraph *g){
	int flag = login(g);
	if (flag == 1){
		background(g);
		setbkcolor(WHITE);
		LOGFONT f;//������ʽָ��
		gettextstyle(&f);//��ȡ������ʽ
		strcpy_s(f.lfFaceName, _T("����"));//�����˿��壬Ҳ��������balabala
		f.lfQuality = ANTIALIASED_QUALITY;//�����
		settextstyle(&f);//�������趨
		settextcolor(BLUE);//�����ı���ɫx`
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID);
		RECT R1 = { r3[0][0], r3[0][1], r3[0][2], r3[0][3] };
		RECT R2 = { r3[1][0], r3[1][1], r3[1][2], r3[1][3] };
		drawtext("��������", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext("�رվ���", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		rectangle(r3[0][0], r3[0][1], r3[0][2], r3[0][3]);
		rectangle(r3[1][0], r3[1][1], r3[1][2], r3[1][3]);//���Ͽ��
		int t = 0, event = 0;
		MOUSEMSG m;
		while (true)
		{
			m = GetMouseMsg();
			switch (m.uMsg){
			case WM_LBUTTONDOWN:
				if (button_judge3(m.x, m.y)!=0){
					t = button_judge3(m.x, m.y);
					if (t == 1);

					if (t == 2);

				}
				break;
			case WM_MOUSEMOVE:
				setrop2(R2_XORPEN);//��Ԫ��դ�����򱳾�ɫ�仯
				setlinecolor(LIGHTCYAN);//����ɫ
				setlinestyle(PS_SOLID, 3);//���ߣ�ʵ�ߣ�10��
				setfillcolor(BLUE);//���ɫ
				if (button_judge3(m.x, m.y) != 0){
					if (event != button_judge3(m.x, m.y)){
						event = button_judge3(m.x, m.y);
						fillrectangle(r3[event - 1][0], r3[event - 1][1], r3[event - 1][2], r3[event - 1][3]);
					}
				}
				else if (event != 0){
					if (event != 0){
						fillrectangle(r3[event - 1][0], r3[event - 1][1], r3[event - 1][2], r3[event - 1][3]);
						event = 0;
					}
				}
				break;
			default:break;
			}
		}
	}
	if (flag == 2){
		background(g);
		setbkcolor(WHITE);
		LOGFONT f;//������ʽָ��
		gettextstyle(&f);//��ȡ������ʽ
		strcpy_s(f.lfFaceName, _T("����"));//�����˿��壬Ҳ��������balabala
		f.lfQuality = ANTIALIASED_QUALITY;//�����
		settextstyle(&f);//�������趨
		settextcolor(BLUE);//�����ı���ɫx`
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID);
		RECT R1 = { r2[0][0], r2[0][1], r2[0][2], r2[0][3] };
		RECT R2 = { r2[1][0], r2[1][1], r2[1][2], r2[1][3] };
		RECT R3 = { r2[2][0], r2[2][1], r2[2][2], r2[2][3] };
		RECT R4 = { r2[3][0], r2[3][1], r2[3][2], r2[3][3] };
		RECT R5 = { r2[4][0], r2[4][1], r2[4][2], r2[4][3] };
		RECT R6 = { r2[5][0], r2[5][1], r2[5][2], r2[5][3] };
		drawtext("������Ϣ��ѯ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext("���������·��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext("����������·��", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext("�ྰ�����·��", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext("�ؽڵ��ѯ", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext("�鿴����", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		rectangle(r2[0][0], r2[0][1], r2[0][2], r2[0][3]);
		rectangle(r2[1][0], r2[1][1], r2[1][2], r2[1][3]);
		rectangle(r2[2][0], r2[2][1], r2[2][2], r2[2][3]);
		rectangle(r2[3][0], r2[3][1], r2[3][2], r2[3][3]);
		rectangle(r2[4][0], r2[4][1], r2[4][2], r2[4][3]);
		rectangle(r2[5][0], r2[5][1], r2[5][2], r2[5][3]);
		int t = 0, event = 0;
		MOUSEMSG m;
		while (true)
		{
			m = GetMouseMsg();
			switch (m.uMsg){
			case WM_LBUTTONDOWN:
				if (button_judge3(m.x, m.y) != 0){
					t = button_judge3(m.x, m.y);
					if (t == 1);

					if (t == 2);

					if (t = 3);

					if (t = 4);

					if (t = 5);

					if (t = 6);

				}
				break;
			case WM_MOUSEMOVE:
				setrop2(R2_XORPEN);//��Ԫ��դ�����򱳾�ɫ�仯
				setlinecolor(LIGHTCYAN);//����ɫ
				setlinestyle(PS_SOLID, 3);//���ߣ�ʵ�ߣ�10��
				setfillcolor(BLUE);//���ɫ
				if (button_judge4(m.x, m.y) != 0){
					if (event != button_judge4(m.x, m.y)){
						event = button_judge4(m.x, m.y);
						fillrectangle(r2[event - 1][0], r2[event - 1][1], r2[event - 1][2], r2[event - 1][3]);
					}
				}
				else if (event != 0){
					if (event != 0){
						fillrectangle(r2[event - 1][0], r2[event - 1][1], r2[event - 1][2], r2[event - 1][3]);
						event = 0;
					}
				}
				break;
			default:break;
			}
		}
	}
	if (flag == -1){

	}
}