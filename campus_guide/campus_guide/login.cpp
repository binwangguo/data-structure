#pragma once

#include<iostream>
#include<graphics.h>
#include<Windows.h>
#include"constant.h"
#include"statement.h"

int login(MGraph *g){
	setbkcolor(WHITE);
	LOGFONT f;//字体样式指针
	gettextstyle(&f);//获取字体样式
	strcpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿
	settextstyle(&f);//给字体设定
	settextcolor(BLUE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	RECT R1 = { r[0][0], r[0][1], r[0][2], r[0][3] };
	RECT R2 = { r[1][0], r[1][1], r[1][2], r[1][3] };
	RECT R3 = { r[2][0], r[2][1], r[2][2], r[2][3] };
	drawtext("校 园 导 览 系 统", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("游客登录", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("管理员登录", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	rectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
	rectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
	MOUSEMSG m;
	int t2, event = 0, flag = 0;
	char pswd[10];
	while (true)
	{
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_LBUTTONDOWN:
			setrop2(R2_NOTXORPEN);

			if (button_judge2(m.x, m.y) != 0)
			{
				t2 = button_judge2(m.x, m.y);
				if (t2 == 1)
				{
					background(g);
					setbkcolor(WHITE);
					LOGFONT f;//字体样式指针
					gettextstyle(&f);//获取字体样式
					strcpy_s(f.lfFaceName, _T("楷体"));
					f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿
					settextstyle(&f);//给字体设定
					settextcolor(BLUE);
					setlinecolor(BLACK);
					setlinestyle(PS_SOLID);
					RECT R1 = { r2[0][0], r2[0][1], r2[0][2], r2[0][3] };
					RECT R2 = { r2[1][0], r2[1][1], r2[1][2], r2[1][3] };
					RECT R3 = { r2[2][0], r2[2][1], r2[2][2], r2[2][3] };
					RECT R4 = { r2[3][0], r2[3][1], r2[3][2], r2[3][3] };
					RECT R5 = { r2[4][0], r2[4][1], r2[4][2], r2[4][3] };
					RECT R6 = { r2[5][0], r2[5][1], r2[5][2], r2[5][3] };
					RECT R7 = { r2[6][0], r2[6][1], r2[6][2], r2[6][3] };
					drawtext("景点信息查询", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					drawtext("两点最短路径", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					drawtext("两点所有路径", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					drawtext("多点最佳路径", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					drawtext("关节点查询", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					drawtext("查看公告", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					drawtext("返回", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
					rectangle(r2[0][0], r2[0][1], r2[0][2], r2[0][3]);
					rectangle(r2[1][0], r2[1][1], r2[1][2], r2[1][3]);
					rectangle(r2[2][0], r2[2][1], r2[2][2], r2[2][3]);
					rectangle(r2[3][0], r2[3][1], r2[3][2], r2[3][3]);
					rectangle(r2[4][0], r2[4][1], r2[4][2], r2[4][3]);
					rectangle(r2[5][0], r2[5][1], r2[5][2], r2[5][3]);
					rectangle(r2[6][0], r2[6][1], r2[6][2], r2[6][3]);
					int t = 0, event = 0;
					MOUSEMSG m;
					while (true)
					{
						m = GetMouseMsg();
						switch (m.uMsg){
						case WM_LBUTTONDOWN:
							if (button_judge4(m.x, m.y) != 0){
								t = button_judge4(m.x, m.y);
								if (t == 1)
									search(g);
								if (t == 2)
									two_locate(g);
								if (t == 3)
									all_path(g);
								if (t == 4)
									more_locate(g);
								if (t == 5)
									coila_query(g);
								if (t == 6)
									get_anounce();
								if (t == 7){
									cleardevice();
									login(g);
								}
							}
							break;
						case WM_MOUSEMOVE:
							setrop2(R2_XORPEN);
							setlinecolor(LIGHTCYAN);
							setlinestyle(PS_SOLID, 3);//画线：实线，10磅
							setfillcolor(BLUE);
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
							FlushMouseMsgBuffer();
						}
						
					}
				}
				if (t2 == 2)
				{
					InputBox(pswd, 10, "请输入密码：");

					if (strcmp(pswd, "123") == 0){
						
						background(g);
						setbkcolor(WHITE);
						LOGFONT f;//字体样式指针
						gettextstyle(&f);//获取字体样式
						strcpy_s(f.lfFaceName, _T("楷体"));
						f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿
						settextstyle(&f);//给字体设定
						settextcolor(BLUE);
						setlinecolor(BLACK);
						setlinestyle(PS_SOLID);
						RECT R1 = { r3[0][0], r3[0][1], r3[0][2], r3[0][3] };
						RECT R2 = { r3[1][0], r3[1][1], r3[1][2], r3[1][3] };
						RECT R3 = { r3[2][0], r3[2][1], r3[2][2], r3[2][3] };
						RECT R4  = { r3[3][0], r3[3][1], r3[3][2], r3[3][3] };
						drawtext("发布公告", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						drawtext("关闭景点", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						drawtext("恢复景点", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						drawtext("返回", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						rectangle(r3[0][0], r3[0][1], r3[0][2], r3[0][3]);
						rectangle(r3[1][0], r3[1][1], r3[1][2], r3[1][3]);
						rectangle(r3[2][0], r3[2][1], r3[2][2], r3[2][3]);
						rectangle(r3[3][0], r3[3][1], r3[3][2], r3[3][3]);
						int t = 0, event = 0;
						MOUSEMSG m;
						while (true)
						{
							m = GetMouseMsg();
							switch (m.uMsg){
							case WM_LBUTTONDOWN:
								if (button_judge3(m.x, m.y) != 0){
									t = button_judge3(m.x, m.y);
									if (t == 1)
										set_anounce();
									if (t == 2)
										close_jd(g);
									if (t == 3)
										open_jd(g);
									if (t == 4){
										cleardevice();
										login(g);
									}
								}
								break;
							case WM_MOUSEMOVE:
								setrop2(R2_XORPEN);
								setlinecolor(LIGHTCYAN);//亮青色
								setlinestyle(PS_SOLID, 3);//画线：实线，10磅
								setfillcolor(BLUE);
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
								FlushMouseMsgBuffer();
							}
							
						}
					}
					else
						MessageBox(GetHWnd(), "密码错误", NULL, MB_OK);
				}
			}
			break;
		case WM_MOUSEMOVE:
			setrop2(R2_XORPEN);
			setlinecolor(LIGHTCYAN);//亮青色
			setlinestyle(PS_SOLID, 3);//画线：实线，10磅
			setfillcolor(BLUE);
			if (button_judge2(m.x,m.y)!=0){
				if (event != button_judge2(m.x, m.y)){
					event = button_judge2(m.x, m.y);
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);
				}
			}
			else if (event != 0){
				if (event != 0){
					fillrectangle(r[event - 1][0], r[event - 1][1], r[event - 1][2], r[event - 1][3]);
					event = 0;
				}
			}
			break;
		default:break;
		}
	}
	return flag;
}