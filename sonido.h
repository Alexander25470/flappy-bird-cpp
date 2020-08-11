#pragma once
#include <windows.h>
#include <thread>
#include <process.h>
#include <future>



using namespace std;




//Time Signature = 4/4
//Default Tempo = 150


/*
float tempo = 150;          // change tempo if you want
float t = (15000 / tempo);    // 60=Seconds per minute and 250 = 1000/4 (because time signature is 4/4) and 15000= 250*60

void c(int oct, float time)
{
	float multiplier = pow(2, oct);
	float tem = 16.35 * multiplier;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void cs(int oct, float time)
{
	float tem = (pow(2, oct)) * 17.32;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void d(int oct, float time)
{
	float tem = (pow(2, oct)) * 18.35;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void ds(int oct, float time)
{
	float tem = (pow(2, oct)) * 19.45;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void e(int oct, float time)
{
	float tem = (pow(2, oct)) * 20.60;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void f(int oct, float time)
{
	float tem = (pow(2, oct)) * 21.83;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void fs(int oct, float time)
{
	float tem = (pow(2, oct)) * 23.12;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void g(int oct, float time)
{
	float tem = (pow(2, oct)) * 24.50;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void gs(int oct, float time)
{
	float tem = (pow(2, oct)) * 25.96;
	float tem2 = t * time;
	Beep(tem, tem2);
}
void a(int oct, float time)
{
	float tem = (pow(2, oct)) * 27.50;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void as(int oct, float time)
{
	float tem = (pow(2, oct)) * 29.14;
	float tem2 = t * time;
	Beep(tem, tem2);
}

void b(int oct, float time)
{
	float tem = (pow(2, oct)) * 30.87;
	float tem2 = t * time;
	Beep(tem, tem2);
}
void r(float time)
{
	float tem2 = t * time;
	Sleep(tem2);
}

void asd5() {
	while (true) {
	for (int i = 1; i <= 8; i++)
	{
		d(5, 1); r(1); d(5, 1); r(3); a(5, 2);
		r(2); g(5, 2); f(5, 2); g(5, 2);
		r(2); e(5, 3); r(1); f(5, 2);
		g(5, 3); f(5, 3); e(5, 2);
	}
	g(5, 3); f(5, 3); e(5, 2);
	for (int i = 1; i <= 4; i++)
	{
		d(5, 1); r(1); d(5, 1); r(3); a(5, 2);
		r(2); g(5, 2); f(5, 2); g(5, 2);
		r(2); e(5, 3); r(1); f(5, 2);
		g(5, 3); f(5, 3); e(5, 2);
	}
	}
}*/

