#pragma once
#include<iostream>
using namespace std;
class Work;
//����״̬
class State
{
public:
	State(){}
	virtual void WriteProgram(Work * w) = 0;
};

//���繤��״̬
class ForenoonState : public State
{
public:
	void WriteProgram(Work * w);
};
//���繤��״̬
class NoonState : public State
{
public:
	void WriteProgram(Work * w);
	
};
//���繤��״̬
class AfternoonState : public State
{
public:
	void WriteProgram(Work * w);
};
//��乤��״̬
class EveningState : public State
{
public:
	void WriteProgram(Work * w);

};
//˯��״̬
class SleepingState : public State
{
public:
	void WriteProgram(Work * w);
};
//�°���Ϣ״̬
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
//����
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
