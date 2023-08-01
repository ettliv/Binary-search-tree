#pragma once
#include<string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct  Auto
{
	char model[200];
	char country[200];
	int date;
	int power;
	float price;
	Auto* left, *right;
};
typedef Auto* PAuto;

PAuto CreateAuto();
void Insert(PAuto& Root, PAuto elem);
void BTout(PAuto Root);
void BTprintLKP(PAuto Root);
void BTprint(PAuto Root);
void BTprintPKL(PAuto Root);
void BToutOneEl(PAuto Root);
PAuto Find(PAuto Root);
PAuto Findr(PAuto Root, char* name);
int Height(PAuto Root);
int NodeCount(PAuto node);
void DeleteNode(PAuto Tree);
void DeleteNoder(PAuto Tree);
void Destroy(PAuto Root);
void Menu();
