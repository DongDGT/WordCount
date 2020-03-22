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
		cout << "����Ĳ����������������������Ĳ�����" << endl;
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
		cout << "û������ɲ������ļ���" << endl;
		return;
	}
	WordCount wordCount;
	for (int i = 0; i < fileName.size(); i++)
	{
		controlFileNum++;
		wordCount.ReSetFile(fileName[i]);
		if (!wordCount.IsSet())
		{
			cout << fileName[i] << "Ϊ��Ч���ļ���" << endl;
			continue;
		}
		for (int j = 0; j < control.size(); j++)
		{
			wordCount.Controller(control[j]);
			switch (control[j])
			{
			case 'c':
				cout << "�ļ������ַ�����" << wordCount.GetCharsCount() << endl;
				break;
			case 'w':
				cout << "�ļ�������������" << wordCount.GetWordsCount() << endl;
				break;
			case 'l':
				cout << "�ļ�����������" << wordCount.GetLinesCount() << endl;
				break;
			case 'a':
				cout << "�ļ�������������" << wordCount.GetEmptyLinesCount() << endl;
				cout << "�ļ���������������" << wordCount.GetDataLinesCount() << endl;
				cout << "�ļ�����ע��������" << wordCount.GetNotesLinesCount() << endl;
				break;
			default:
				break;
			}
		}
	}
}
