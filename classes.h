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