#include <iostream>
#include <cstdio>
#include <math.h> 
#include <string>   
#include <cstring>   
#include <stdio.h>    
#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

struct Object{
	string name;
	float x;
	float y;
};

string seeobj[200] ;
Object obj[14];

void split(char str[],char delims[]);
void initobj(Object a[]);
void printobj(Object a[]);
Object getobj(string str);

int main(){
	int i = 1;
	float fr, ft, gr, gt;//�ֱ�Ϊ���������Ծ���ͼ��� 
	float fx, fy, gx, gy;//�ֱ�Ϊ������ľ������� 
	float px, py;//�����
	 
	char msg[50] = "(P10 7 135) (G2 22.5 -135)";
	/*
	(P8 22 0) (P7 15 30)
	(C 7 45) (P8 30 -45)
	(P10 7 135) (G2 22.5 -135) 
	(P6 10 0) (P3 62.5 0) ׼ȷ (-10 , 32 )
	*/
	char delims[] = ") (";
	Object F, G;//�����۲�� 
	split(msg, delims);

	initobj(obj);
	//printobj(obj);	
	
	for(i = 1; i < 7;)
	{  
		//cout << seeobj[i] << "\n";
		i++;
    }  
	
	F = getobj(seeobj[1]) ;
	G = getobj(seeobj[4]) ;
		
	fx = F.x;
	fy = F.y;
	gx = G.x;
	gy = G.y;
	
	cout << fx << " " << fy << " "<< gx << " " << gy << "\n";
	
	fr = atof(seeobj[2].c_str()); //������ֵ 
	ft = atof(seeobj[3].c_str());
	gr = atof(seeobj[5].c_str());
	gt = atof(seeobj[6].c_str()); 
	
	cout << fr << " " << ft << " "<< gr << " "<< gt;	
	
	//�����Ѿ��õ�ȫ�����ݣ����濪ʼ����
	float d;
	d = sqrt((fx - gx) * (fx - gx) + (fy - gy) * (fy - gy));
	
	float a;
	a = (fr * fr - gr * gr + d * d) / (2 * d);
	
	float dx = fabs(fx - gx);
	float dy = fabs(fy - gy); 
	
	float ppx = fx + (a * dx) / d;
	float ppy = fy - (a * dy) / d;
	
	float h = sqrt(fr * fr - a * a);
	 
	if(gt - ft > 0)
	{
		px = ppx + h * dy / d;
		py = ppy + h * dx / d; 
	}
	else
	{
		px = ppx - h * dy / d;
		py = ppy - h * dx / d; 
	}
	
	cout << "\n�����˵������ǣ� (" << px << " , " << py << " )"; 
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

void printobj(Object a[])
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
