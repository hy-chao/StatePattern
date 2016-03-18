#include "state.h"

void ForenoonState::WriteProgram(Work * w)
{
	if (w->GetHour() < 12)
	{
		cout << "��ǰʱ��: " << w->GetHour() << "�� ���繤��������ٱ�" << endl;
	}
	else
	{
		w->SetState(new NoonState());
		w->WriteProgram();
	}
}

void NoonState::WriteProgram(Work * w)
{
	if (w->GetHour() < 13)
	{
		cout << "��ǰʱ��: " << w->GetHour() << "�� ���ˣ��緹������������" << endl;
	}
	else
	{
		w->SetState(new AfternoonState());
		w->WriteProgram();
	}
}

void AfternoonState::WriteProgram(Work * w)
{
	if (w->GetHour() < 17)
	{
		cout << "��ǰʱ��: " << w->GetHour() << "�� ����״̬����������Ŭ��" << endl;
	}
	else
	{
		w->SetState(new EveningState());
		w->WriteProgram();
	}
}

void EveningState::WriteProgram(Work * w)
{
	if (w->GetTaskState())
	{
		w->SetState(new RestState());
		w->WriteProgram();
	}
	else if(w->GetHour() > 20)
	{
		w->SetState(new StopWork());
		w->WriteProgram();
	}
	else
	{
		if (w->GetHour() < 21)
		{
			cout << "��ǰʱ��: " << w->GetHour() << "�� �Ӱ�Ŷ��ƣ��֮��" << endl;
		}
		else
		{
			w->SetState(new SleepingState());
			w->WriteProgram();
		}
	}
}

void SleepingState::WriteProgram(Work * w)
{
	cout << "��ǰʱ��: " << w->GetHour() << "�㲻���ˣ�˯���ˡ�" << endl;
}

void RestState::WriteProgram(Work * w)
{
	cout << "��ǰʱ��: " << w->GetHour() << "���°�ؼ���" << endl;
}

void StopWork::WriteProgram(Work * w)
{
	cout << "��ǰʱ��: " << w->GetHour() << "ֹͣ����  �°�" << endl;
}