//
//  YeMatrix.cpp
//  Final Project
//
//  Created by Elizabeth Zhang on 4/23/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include "YeMatrix.hpp"

Vector_d operator+(const Vector_d& W,const Vector_d& V)
{
	size_t d = W.size();
	Vector_d M(d);
	for (unsigned int i = 0; i<d; i++) M[i] = W[i] + V[i];
	return M;
}

Vector_d operator-(const Vector_d& W,const Vector_d& V)
{
	size_t d = W.size();
	Vector_d M(d);
	for(unsigned int i=0;i<d;i++) M[i]=W[i]-V[i];
	return M;
}

Vector_d operator/(const Vector_d& W, const int& a)
{
	size_t d = W.size();
	Vector_d M(d);
	for(unsigned int i=0;i<d;i++) M[i]=W[i]/a;
	return M;
}

Vector_d Cumsum(const Vector_d& W)
{
	Vector_d V(W.size());
	V[0]=W[0];
	for(unsigned int i=1;i<W.size();i++)
		V[i]=V[i-1]+W[i];
	return V;
}
vector<vector<vector<double>>> SetMatrix(Vector_d  BeatAAR, Vector_d  BeatCAAR, Vector_d  MeetAAR, Vector_d  MeetCAAR, Vector_d  MissAAR, Vector_d  MissCAAR)
{
	vector<vector<vector<double>>> ReturnMatrix;
	ReturnMatrix.resize(3);
	for (int i = 0; i<3; i++)
		ReturnMatrix[i].resize(2);
	ReturnMatrix[0][0]=BeatAAR / 100;
	ReturnMatrix[1][0] = MeetAAR / 100;
	ReturnMatrix[2][0] = MissAAR / 100;
	ReturnMatrix[0][1] = BeatCAAR / 100;
	ReturnMatrix[1][1] = MeetCAAR / 100;
	ReturnMatrix[2][1] = MissCAAR / 100;
	return ReturnMatrix;
};
vector<vector<string>> Settitle()
{
	vector<vector<string>> title;
	title.resize(2);
	for (int i = 0; i<2; i++)
		title[i].resize(3);
	title[0][0]="AAR1";
	title[0][1] = "AAR2";
	title[0][2] = "AAR3";
	title[1][0] = "CAAR1";
	title[1][1] = "CAAR2";
	title[1][2] = "CAAR3";
	return title;
};
