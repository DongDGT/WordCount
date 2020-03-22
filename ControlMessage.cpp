#include "ControlMessage.h"

ControlMessage::ControlMessage()
{
}

ControlMessage::~ControlMessage()
{
}

void ControlMessage::AddMessage(string singleMessage)
{
	if(addAble)
	message.push_back(singleMessage);
}

void ControlMessage::Distribution()
{
	bool controlError = false;
	for (int i = 0; i < message.size(); i++)
	{
		if ((message[i].data())[0] == '-')
		{
			if ((message[i].data())[1] == 'c' || (message[i].data())[1] == 'w' || (message[i].data())[1] == 'l' || (message[i].data())[1] == 'a')
			{
				this->control.push_back((message[i].data())[1]);
			}
			else
				controlError = true;
		}
		else
		{
			fileName.push_back(message[i]);
		}
	}
	if (controlError)
	{
		cout << "输入的操作有误，请检查有无输入错误的操作符" << endl;
	}
	this->isDistribution = true;
	this->addAble = false;
}

void ControlMessage::Control()
{
	if (!isDistribution)
		return;
	int controlFileNum = 0;
	if (fileName.size() <= 0)
	{
		cout << "没有输入可操作的文件名" << endl;
		return;
	}
	WordCount wordCount;
	for (int i = 0; i < fileName.size(); i++)
	{
		controlFileNum++;
		wordCount.ReSetFile(fileName[i]);
		if (!wordCount.IsSet())
		{
			cout << fileName[i] << "为无效的文件名" << endl;
			continue;
		}
		for (int j = 0; j < control.size(); j++)
		{
			wordCount.Controller(control[j]);
			switch (control[j])
			{
			case 'c':
				cout << "文件所含字符数：" << wordCount.GetCharsCount() << endl;
				break;
			case 'w':
				cout << "文件所含单词数：" << wordCount.GetWordsCount() << endl;
				break;
			case 'l':
				cout << "文件所含行数：" << wordCount.GetLinesCount() << endl;
				break;
			case 'a':
				cout << "文件所含空行数：" << wordCount.GetEmptyLinesCount() << endl;
				cout << "文件所含代码行数：" << wordCount.GetDataLinesCount() << endl;
				cout << "文件所含注释行数：" << wordCount.GetNotesLinesCount() << endl;
				break;
			default:
				break;
			}
		}
	}
}
