#pragma once
#include<vector>
#include<string>
#include<iostream>
#include"WordCount.h"

using namespace std;

class ControlMessage
{
private:
	vector<string> message;
	vector<char> control;
	vector<string>fileName;
	bool isDistribution = false;
	bool addAble = true;


public:
	ControlMessage();
	~ControlMessage();
	void AddMessage(string message);
	void Distribution();
	void Control();

};

