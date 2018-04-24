//
//  Demo.cpp
//  Final Project
//
//  Created by Elizabeth Zhang on 4/24/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//
#include "YeMatrix.hpp"
#include "Demo.hpp"
using namespace std;

void Menu(const Group& Beat, const Group& Meet, const Group& Miss, const vector<vector<vector<double>>>& ReturnMatrix)
{
	int c = 0;
	while (c != 4)
	{
		cout << "Menu:" << endl;
		cout << "1. Pull information for one stock from one group. " <<endl;
		cout << "2. Show ARR or CAAR for one group. " << endl;
		cout << "3. Show the Excel graph with CAAR for all groups. " <<endl;
		cout << "4. Quit. " << endl;
		cout << "Please choose your task: ";
		cin >> c;
		if (c==1) StockInfo(Beat, Meet, Miss);
		else if (c==2) StatsInfo(ReturnMatrix);
		else if (c==3) PicDemo(ReturnMatrix);
		else if (c==4) cout << "Quit." << endl;
		else
			cout<<"Invalid number." << endl;
		cout << endl <<endl<< endl;
 	}
}

void StockInfo(const Group& Beat, const Group& Meet, const Group& Miss)
{
	cout << "Quest 1: Present all information." << endl;
	string ticker;
	cout << "Enter the ticker: "; cin >> ticker;
	map <string, Stock> :: const_iterator itr1 = Beat.Content.find(sticker)
	if (itr1 != Beat.Content.end())
		itr1->second.printInfo()
	map<string, Stock>::const_iterator itr2 = Meet.Content.find(sticker);
	if (itr2 != Meet.Content.end())
		itr2->second.printInfo();
	map<string, Stock>::const_iterator itr3 = Miss.Content.find(sticker);
	if (itr3 != Miss.Content.end())
		itr3->second.printInfo();
}

void StatsInfo(const vector<vector<vector<double>>>& ReturnMatrix)
{
	cout << "Quest 2: Show ARR or CAAR for one group. " << endl;
	cout << "0. ARR or 1.CAAR?"<<endl;
	int option1;
	cin >> option;
	if (option1 != 0 && option1 != 1)
		cout << "Input number is invalid. Please select again." << endl;
	
	cout << "0.Show group Beat." << endl;
	cout << "1.Show group Meet." << endl;
	cout << "2.Show group Miss." << endl;
	int option2;cin >> option2;
	if (option2 != 1 && option2 != 2 && option2!=3)
		cout << "Input number is invalid. Please select again." << endl;
	
	NumericMatrix<double, long> Data(1,61);
	for (long i = 1; i <= 61; i++)
		Data(1, i) = ReturnMatrix[option2][option1][i - 1];
	Vector<double, long> xarr(1);
	Vector<double, long> yarr(61);
	xarr[1] = 1;
	yarr[yarr.MinIndex()] = 1;
	for (long i = yarr.MinIndex() + 1; i <= yarr.MaxIndex(); i++)
		yarr[i] = yarr[i - 1] + 1;
	vector<vector<string>>title;
	title = Settitle();
	printMatrixInExcel(Data, xarr, yarr, title[option1][option2]);
}

void PicDemo(const vector<vector<vector<double>>>& ReturnMatrix)
{
	cout << "Quest 3: Show the Excel graph with CAAR for all groups." << endl;
	Vector<double, long> CAARx1(61);
	Vector<double, long>CAARx2(61);
	Vector<double, long>CAARx3(61);
	Vector<double, long>CAARy1(61);
	Vector<double, long>CAARy2(61);
	Vector<double, long>CAARy3(61);
	CAARx1[CAARx1.MinIndex()] = -30.0;
	CAARx2[CAARx2.MinIndex()] = -30.0;
	CAARx3[CAARx3.MinIndex()] = -30.0;
	for (long i = CAARx1.MinIndex() + 1; i <= CAARx1.MaxIndex(); i++)
	{
		CAARx1[i] = CAARx1[i - 1] + 1;
		CAARx2[i] = CAARx2[i - 1] + 1;
		CAARx3[i] = CAARx3[i - 1] + 1;
	}
	
	for (long i = CAARy1.MinIndex(); i <= CAARy1.MaxIndex(); i++)
	{
		CAARy1[i] = ReturnMatrix[0][1][i - 1];
		CAARy2[i] = ReturnMatrix[1][1][i - 1];
		CAARy3[i] = ReturnMatrix[2][1][i - 1];
	}
	
	list<std::string> labels;// Names of each vector
	list<Vector<double, long> > yyy;
	labels.push_back("Beat");
	labels.push_back("Meet");
	labels.push_back("Miss");
	
	yyy.push_back(CAARy1);
	yyy.push_back(CAARy2);
	yyy.push_back(CAARy3);
	
	printInExcel(CAARx1, labels, yyy, "CAAR", "T/days", "return");
}


