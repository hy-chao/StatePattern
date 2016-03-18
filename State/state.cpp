#include "state.h"

void ForenoonState::WriteProgram(Work * w)
{
	if (w->GetHour() < 12)
	{
		cout << "当前时间: " << w->GetHour() << "点 上午工作，精神百倍" << endl;
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
		cout << "当前时间: " << w->GetHour() << "点 饿了，午饭；犯困，午休" << endl;
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
		cout << "当前时间: " << w->GetHour() << "点 下午状态还不错，继续努力" << endl;
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
			cout << "当前时间: " << w->GetHour() << "点 加班哦，疲累之极" << endl;
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
	cout << "当前时间: " << w->GetHour() << "点不行了，睡着了。" << endl;
}

void RestState::WriteProgram(Work * w)
{
	cout << "当前时间: " << w->GetHour() << "点下班回家了" << endl;
}

void StopWork::WriteProgram(Work * w)
{
	cout << "当前时间: " << w->GetHour() << "停止工作  下班" << endl;
}