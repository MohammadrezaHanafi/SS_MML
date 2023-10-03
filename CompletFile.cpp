#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Date
{
	int year;
	int month;
	int day;
  public:
	  Date(int a, int b, int c):year(a), month(b), day(c) {}
	Date() {}
	friend ostream & operator <<(ostream & out, Date & d);
};



class Time
{
	int hour;
	int minute;
	int second;
  public:
	  Time(int a, int b, int c):hour(a), minute(b), second(c){}
	Time() {}
	
	friend ostream & operator <<(ostream & out, Time & d);
};



class Penalty
{
	int num;
	double amountPenalty;
	string plate;
	Time _time;
	Date date;
  public:
	  Penalty(double ap, string p):amountPenalty(ap), plate(p)
	{
		static int n = 0;
		  num = ++n;
		time_t now = time(NULL);
		tm *lt = localtime(&now);
		  _time = Time(lt->tm_hour, lt->tm_min, lt->tm_sec);
		  date = Date(1900 + lt->tm_year, 1 + lt->tm_mon, lt->tm_mday);
	}

	int getNum()
	{
		return num;
	}
	string getPlate()
	{
		return plate;
	}

	friend ostream & operator <<(ostream & out, Penalty & p);
};



class Police
{
	vector < Penalty > penalty;
  public:
	int getSize()
	{
		return penalty.size();
	}

	void savePenalty(Penalty p)
	{
		penalty.push_back(p);
	}

	void showPenaltes(string plate);

	bool peyPenalty(int _num);
};


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



int main(){
	Police police;
	while (1){
		int choice = intGiver ("choose an option: \n1)add new penalty. \n2)show plaque penaltes. \n3)pey penalty. \n4)EXIT \n-->" , 4 , 1);
		
		if (choice == 1){
			
			double ap;
			string plate = plateGiver();
			while (1){
				cout<<"input amount penalty:";
				cin>>ap;
				if (ap>0) break;
				cout<<"incorrect amount of penalty."<<endl;
			}
			police.savePenalty(Penalty(ap, plate));
			cout<<endl<<endl;
			
		}else if (choice == 2){
			
			string plate = plateGiver();
			police.showPenaltes(plate);
			cout<<endl<<endl;
			
		}else if (choice == 3){
			
			int num ;
			while (1){
				cout<<"input num of penalty: ";
				cin>>num;
				if (police.peyPenalty (num)) {
					cout<<"penalty pey successfuly!"<<endl<<endl;
					break;
				}
				cout<<"there is not any penalty with num:"<<num<<" set to our DB!"<<endl;
				if ( !YorN() ) break;
			}
			cout<<endl<<endl;
			
		}else{
			cout<<"GoodBye!"<<endl;
			break;
		}
	}
	return 0;
}