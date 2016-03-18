#pragma once
#include<iostream>
using namespace std;
class Work;
//抽象状态
class State
{
public:
	State(){}
	virtual void WriteProgram(Work * w) = 0;
};

//上午工作状态
class ForenoonState : public State
{
public:
	void WriteProgram(Work * w);
};
//中午工作状态
class NoonState : public State
{
public:
	void WriteProgram(Work * w);
	
};
//下午工作状态
class AfternoonState : public State
{
public:
	void WriteProgram(Work * w);
};
//晚间工作状态
class EveningState : public State
{
public:
	void WriteProgram(Work * w);

};
//睡眠状态
class SleepingState : public State
{
public:
	void WriteProgram(Work * w);
};
//下班休息状态
class RestState : public State
{
public:
	void WriteProgram(Work * w);
};
class StopWork : public State
{
public:
	void WriteProgram(Work * w);
};
//工作
class Work
{
private:
	State * current;
	double  hour;
	bool finish = false;
public:
	Work()
	{
		current = new ForenoonState();
	}
	void SetHour(int h)
	{
		hour = h;
	}
	double GetHour()
	{
		return hour;
	}
	void TaskFinished(bool f)
	{
		finish = f;
	}
	bool GetTaskState()
	{
		return finish;
	}
	void SetState(State * s)
	{
		current = s;
	}
	void WriteProgram()
	{
		current->WriteProgram(this);
	}
};
