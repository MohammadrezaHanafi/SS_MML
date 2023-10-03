#include "classes.h"

ostream & operator <<(ostream & out, Date & d)
{
	cout << d.year << "/" << d.month << "/" << d.day;
	return out;
}



ostream & operator <<(ostream & out, Time & t)
{
	cout << t.hour << ":" << t.minute << ":" << t.second;
	return out;
}



ostream & operator <<(ostream & out, Penalty & p)
{
	cout << "------------------------" << endl;
	cout << "num       :" << p.num << endl;
	cout << "amount    :" << p.amountPenalty << endl;
	cout << "plaque    :" << p.plate << endl;
	cout << "time      :" << p._time << endl;
	cout << "date      :" << p.date << endl;
	cout << "------------------------" << endl;
	return out;
}



void Police::showPenaltes(string plate)
{
	bool printed = 0;
	for (int i = 0; i < penalty.size(); i++)
		if (penalty[i].getPlate() == plate)
		{
			cout << penalty[i] << endl;
			printed = 1;
		}
	if (printed)
		return;
	cout << "there is not any penalty set for plaque \"" << plate << "\" ." << endl;
}



bool Police::peyPenalty(int _num)
{
	for (int i = 0; i < penalty.size(); i++)
		if (penalty[i].getNum() == _num)
		{
			penalty.erase(penalty.begin() + i);
			return 1;
		}
	return 0;
}



 bool checkPlaque(string p)
{
	return ((p[0] > 47 && p[0] < 58) && (p[1] > 47 && p[1] < 58) && (p[5] > 47 && p[5] < 58)
			&& (p[6] > 47 && p[6] < 58) && (p[7] > 47 && p[7] < 58) && (p[2] == '-')
			&& (p[4] == '-') && (p[3] >= 'A' && p[3] <= 'Z'));
}



int intGiver(string str, int max, int min = 1) {
	int x;
	while (1)
	{
		cout << str;
		cin >> x;
		if (x <= max && x >= min)
			return x;
		cout << "incorrecr input (min:" << min << " , max:" << max << ")" << endl;
	}
}



string plateGiver()
{
	string plate;
	while (1)
	{
		cout << "input Plaque: ";
		cin >> plate;
		if (checkPlaque(plate))
			return plate;
		cout << "incorrect input (correct plaque is like 12-A-358)" << endl;
	}
}



bool YorN(string str = "do you want to try again?(y/n)")
{
	while (1)
	{
		cout << str;
		char ch;
		cin >> ch;
		if (ch == 'n' || ch == 'N')
		{
			return 0;
		}
		else if (ch == 'y' || ch == 'Y')
		{
			return 1;
		}
		else
			cout << "incorrect input!" << endl;
	}
}
