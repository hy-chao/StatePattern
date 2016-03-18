#include "state.h"
int main()
{
	Work * emp = new Work();
	emp->SetHour(9);
	emp->WriteProgram();
	emp->SetHour(10);
	emp->WriteProgram();
	emp->SetHour(11);
	emp->WriteProgram();
	emp->SetHour(12);
	emp->WriteProgram();
	emp->SetHour(13);
	emp->WriteProgram();
	emp->SetHour(14);
	emp->WriteProgram();
	emp->SetHour(17);
	
	emp->TaskFinished(false);
	emp->WriteProgram();
	emp->SetHour(19);
	emp->WriteProgram();
	emp->SetHour(22);
	emp->WriteProgram();
	return 0;
}