#include <iostream>
#include <cstdio>
#include <math.h> 
#include <string>   
#include <cstring>   
#include <stdio.h>    
#include <iostream>   
#include <bits/stdc++.h>

#define PI 3.1415926
#define EPS  1e-6

using namespace std;

struct Object{//���ϱ�־�ṹ 
	string name;
	float x;
	float y;
};

struct Point{//��ṹ 
	float x;
	float y;
};

string seeobj[200];//�洢������Ϣ 
Object obj[14];//�洢��־�� 
Point pt[3];//�洢���ܵ�λ�� 

void split(char str[],char delims[]);//�ָ��ַ��� 
void initobj(Object a[]);//��ʼ���㼯���� 
void printobj(Object a[]);//��ӡ�㼯 
Object getobj(string str);//ͨ�����뷵�ع̶������� 
void InterCircles(float fr, float gr, float fx, float fy, float gx, float gy);//���������ܽ��� 
void printPoint();//��ӡ���ܵĵ� 
float LR(Point P1, Point P2, Point P3);//������ж�����λ�ù�ϵ 
Point solve2(float t, Point A, Point B, Point C , Point D);//�����2 
float normalize(float t1, float t2);//�нǹ淶�� 

int main(){
	int i = 1;
	float fr, ft, gr, gt;//�ֱ�Ϊ���������Ծ���ͼ��� 
	float fx, fy, gx, gy;//�ֱ�Ϊ������ľ������� 
	float ang;//�Ƕ� 
	Point A, C;//�淶����Ҫ���м��� 
	Point B, D;
	Point result;//���շ��صĽ���� 
	char msg[50];
	
	cout << "��������Ե㣡\n";
	cin.get(msg, 50);
	//char msg[50] = "(P10 7 135) (G2 22.5 -135)";//Ҳ����ֱ�Ӱ���Ϣ�������� 
	
	//******************** ���ֲ��Ե㼯 *********************** 
	//���������������Ϣ �Ҳ������õ� 
	/*
	(P8 22 0) (P7 27.7128 30) 			(-8.22565 10.1429)
	(C 7 45) (P8 30 -45) 			(0 7)
	(P8 7 135) (C 30 45) 			(-30 0) 
	(P10 7 135) (G2 22.5 -135) 			(30 0)
	(P6 10 0) (P3 62.5 0)  			(-10 32)
	(P9 22.5 45) (G2 7 135)  		(52.5 7) 
	(P8 39.051248 -56.22368) (P9 39.051248 56.22368) 		(0 , -18)
	*/
	
	char delims[] = ") (";
	Object F, G;//�����۲�� 
	split(msg, delims);

	initobj(obj);
	//printobj(obj);	
	
	//���������Ǵ����������� 
	
	F = getobj(seeobj[1]) ;
	G = getobj(seeobj[4]) ;
		
	fx = F.x;
	fy = F.y;
	gx = G.x;
	gy = G.y;
	
	fr = atof(seeobj[2].c_str()); //������ֵ 
	ft = atof(seeobj[3].c_str());
	gr = atof(seeobj[5].c_str());
	gt = atof(seeobj[6].c_str()); 
	
	//cout << fr << " " << ft << " "<< gr << " "<< gt;	
	
	if(gy < fy)//�õ��м���A,C ������淶�Ƕ� 
	{
		A.x = G.x;
		A.y = G.y;
		C.x = F.x;
		C.y = F.y;
		ang = normalize(ft, gt);
	}
	else
	{
		C.x = G.x;
		C.y = G.y;
		A.x = F.x;
		A.y = F.y;	
		ang = normalize(gt, ft);	
	}
	
	//cout << " A�� "<< A.x << " " << A.y << "\n C�� "<< C.x << " " << C.y << "\n";
	
	//���ݻ�ȡ��ɣ����¿�ʼ����
	 
	InterCircles(fr, gr, fx, fy, gx, gy);//��ȡ��������λ�ô���Point[]

	
	if(pt[1].x < pt[2].x) //�Ӻ�����ѡȡ�м���B,D 
	{
		B = pt[1];
		D = pt[2];
	}
	else
	{
		B = pt[2];
		D = pt[1];
	}
	cout << "\nB���ǣ� (" << B.x << " , " << B.y << " )\n"; 
	
	//�Ƕȹ淶�� 
	
	cout << "�淶���н��ǣ�" << ang << endl;
	 
	float t = fr * gr * sin(ang / 180 * PI); //�����һ���㷨 
	
	cout << "�������1�ǣ�" << t << endl;
	result = solve2(t, A, B, C, D);//�ж����� ����һ�ֲ���������м�������� ������õĵ� 
	
	cout << "\n�����˵������ǣ� ( " << result.x << " , " << result.y << " )"; 
}

void initobj(Object a[])//��ʼ���㼯���� 
{
	a[1].name = "C";
	a[1].x = 0.0f;
	a[1].y = 0.0f;
	
	a[2].name = "P1";
	a[2].x = -52.5f;
	a[2].y = -32;
	
	a[3].name = "P2";
	a[3].x = -52.5f;
	a[3].y = 32;
	
	a[4].name = "P3";
	a[4].x = 52.5f;
	a[4].y = 32;
	
	a[5].name = "P4";
	a[5].x = 52.5f;
	a[5].y = -32;
	
	a[6].name = "P5";
	a[6].x = 0.0f;
	a[6].y = -32;
		
	a[7].name = "P6";
	a[7].x = 0.0f;
	a[7].y = 32;	
	
	a[8].name = "P7";
	a[8].x = -30;
	a[8].y = -7;
	
	a[9].name = "P8";	
	a[9].x = -30;
	a[9].y = 7;
	
	a[10].name = "P9";
	a[10].x = 30;
	a[10].y = 7;
	
	a[11].name = "P10";	
	a[11].x = 30;
	a[11].y = -7;
	
	a[12].name = "G1";
	a[12].x = -52.5f;
	a[12].y = 0;
	
	a[13].name = "G2";
	a[13].x = 52.5f;
	a[13].y = 0;		
}

void printobj(Object a[])//��ӡ�ο��㼯 
{
	int i = 1;
	for(i = 1; i < 14 ; i++)
	{
		cout << a[i].name << " " << a[i].x << " " << a[i].y << "\n"; 
	} 
} 

void split(char str[],char delims[])//�ָ��ַ��� 
{
    char *result = NULL; 
    int i = 1;
    result = strtok(str, delims);  
    
    while(result != NULL ) 
	{  
	    //printf("result is \"%s\"\n", result);
	    //cout << result << "\n";
	    seeobj[i] = result;
    	result = strtok( NULL, delims);  
    	i++;
    }  
}

Object getobj(string str)//�������Ʒ���obj�ṹ�� 
{
	for(int i = 1; i < 14; i++)
	{
		if(obj[i].name == str)
			return obj[i];
	} 
} 

void printPoint()//��ӡpoint���� 
{
	cout << pt[1].x << " " << pt[1].y << endl;
	cout << pt[2].x << " " << pt[2].y << endl;	
}

void InterCircles(float fr, float gr, float fx, float fy, float gx, float gy)//�������ܵ�λ���Թ���� 
{
	float a1, b1, R1, a2, b2, R2;
	float p1x, p1y, p2x, p2y;
	a1 = fx;
	b1 = fy;
	R1 = fr;

	a2 = gx;
	b2 = gy;
	R2 = gr;

	//
	float R1R1 = R1*R1;
	float a1a1 = a1*a1;
	float b1b1 = b1*b1;

	float a2a2 = a2*a2;
	float b2b2 = b2*b2;
	float R2R2 = R2*R2;

	float subs1 = a1a1 - 2 * a1*a2 + a2a2 + b1b1 - 2 * b1 * b2 + b2b2;
	float subs2 = -R1R1 * a1 + R1R1 * a2 + R2R2 * a1 - R2R2 * a2 + a1a1 * a1 - a1a1 * a2 - a1*a2a2 + a1*b1b1 - 2 * a1*b1*b2 + a1*b2b2 + a2a2*a2 + a2*b1b1 - 2 * a2*b1*b2 + a2*b2b2;
	float subs3 = -R1R1 * b1 + R1R1 * b2 + R2R2 * b1 - R2R2 * b2 + a1a1 * b1 + a1a1 * b2 - 2 * a1*a2*b1 - 2 * a1*a2*b2 + a2a2 * b1 + a2a2 * b2 + b1b1*b1 - b1b1 * b2 - b1*b2b2 + b2b2*b2;
	float sigma = sqrt((R1R1 + 2 * R1 * R2 + R2R2 - a1a1 + 2 * a1*a2 - a2a2 - b1b1 + 2 * b1*b2 - b2b2)*(-R1R1 + 2 * R1*R2 - R2R2 + subs1));
	if(abs(subs1)>0.0000001)//��ĸ��Ϊ0
	{
		p1x = (subs2 - sigma * b1 + sigma * b2) / (2 * subs1);
		p2x = (subs2 + sigma * b1 - sigma * b2) / (2 * subs1);
	
		p1y = (subs3 + sigma * a1 - sigma * a2) / (2 * subs1);
		p2y = (subs3 - sigma * a1 + sigma * a2) / (2 * subs1);
	}

	if((fabs(p1x) <= 52.5 && fabs(p1y) <= 32) && (fabs(p2x) <= 52.5 && fabs(p2y) <= 32)) //�������ܵ� 
	{
		if(fabs(p1x - p2x) < EPS && fabs(p1y - p2y) < EPS)//��Բ���� ��� 
		{
			cout << "\n�����˵������ǣ� (" << p1x << " , " << p1y << " )";
			exit(100);
		}
		else
		{
			cout << "���������ܵ㣡" << endl; 
			cout << "\n�����˵��������1�ǣ� (" << p1x << " , " << p1y << " )"; 
			cout << "\n�����˵��������2�ǣ� (" << p2x << " , " << p2y << " )\n"; 
		} 
	}	
	else//ֻ��һ����Ϸ� ֱ����� 
	{
		if(fabs(p1x) <= 52.5 && fabs(p1y) <= 32)
			cout << "\n�����˵������ǣ� (" << p1x << " , " << p1y << " )"; 
		else
			cout << "\n�����˵������ǣ� (" << p2x << " , " << p2y << " )"; 
		exit(100);
	} 

	
	pt[1].x = p1x;
	pt[1].y = p1y;
	pt[2].x = p2x;
	pt[2].y = p2y; 
}

float LR(Point P1, Point P2, Point P3)//��������ж����߹�ϵ 
{
	float x1, x2, x3;
	float y1, y2, y3;
	x1 = P1.x;
	y1 = P1.y;
	x2 = P2.x;
	y2 = P2.y;		
	x3 = P3.x;
	y3 = P3.y;
	
	float S = ((x1 - x3) * (y2 - y3) - (y1 - y3) * (x2 - x3)) / 2; 
	return 1 * S; 
} 

float normalize(float t1, float t2)//�нǹ淶�� ����t1�Ǻ�C�ļнǣ�t2�Ǻ�A�ļн� 
{
	float ang;
	if(t1 * t2 > 0)
	{
		ang = t1 - t2;
	} 
	else if(t1 > 0 && t2 < 0)
	{
		ang = t1 - t2; 
	} 
	else if(t1 < 0 && t2 > 0)
	{
		ang = 360 - t2 + t1; 
	}
	return ang;
}

Point solve2(float t, Point A, Point B, Point C, Point D)//����� 
{
	float a, b, c, d, x, y;
	a = A.x;
	b = A.y;
	c = C.x;
	d = C.y;
	
	x = B.x;//����һ�����Ƶ� 
	y = B.y;
	
	float flag; //ʹ�ò����һ���㷨���ж����� 
	flag = (b - d) * x + (c - a) * y + a * d - c * b;
	//flag = -flag;
	
	cout << "�������2�ǣ�" << flag << endl;//У��ʽ 
	
	//flag = flag - t;
	
	cout << flag << endl;
	if(flag * t > 0 && (fabs(flag) - fabs(t)) < EPS)//������ֲ����� ˵�����Ƶ�����ȷ�� 
	{
		return B; 
		cout << "\n�����˵�����11�ǣ� (" << x << " , " << y << " )"; 
	}
	else//˵�����Ƶ����������һ���� 
	{
		return D; 
		cout << "\n�����˵�����22�ǣ� (" << D.x << " , " << D.y << " )";
	} 
	 
}


