#include "Application.h"

int main(int argc, char** argv)
{
	Application app;
	int returnValue = app.runMathTests();
	//int returnValue = app.runClockTimerTests();

	return returnValue;
}