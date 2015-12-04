#include "Application.h"
#include <JADEngine\Clock.h>
#include <JADEngine\Timer.h>
#include <JADEngine\LogManager.h>
#include <JADEngine\Math\Quaternion.h>
#include <iostream>

Application::Application()
{
}


Application::~Application()
{
}

/*
Runs tests
*/
int Application::runClockTimerTests()
{

	char tmp = 't';

	/*
	Returns an instance of the Clock class
	Since ther should be only one.
	*/
	auto clock = Clock::getInstance();

	auto log = LogManager::getInstance();

	/*
	Initializes the clock
	*/
	clock->init();

	/*
	Creates the Timer
	*/
	Timer timer(clock);

	/*
	Initializes the Timer
	*/
	timer.initTimer();

	/*
	While the clock has less than 5 minutes on it since it was started,
	print out to standard output the clock time in seconds and
	the timer time in seconds.

	At the 3 seconds mark on the timer,
	pause the timer if the letter 't' is typed into standard input
	and only start it again
	if the letter 's' is typed into standard input.
	*/

	while (clock->toMilliseconds(clock->getElapsedTime(clock->getTimeNow())) < 16000.0f)
	{
		auto c = clock->getElapsedTime(clock->getTimeNow());
		timer.updateSeconds();

		std::cout << "Elapsed Timer Time in seconds : " << timer.getSeconds() << std::endl;
		std::cout << std::endl;

		if (timer.getSeconds() > 3.0f && timer.getSeconds() < 3.1f)
		{
			tmp = std::cin.get();
			if (tmp == 't')
			{
				timer.pauseTimer();
			}

			if (tmp == 's')
			{
				log->info("Timer was paused at 3 secs, and then restarted by user.", clock->retrieveSystemTime());
				timer.startTimer();
				log->setLogFile(std::string("JigglyPuff.txt"));
			}
			log->info("New file was created for test purposes", clock->retrieveSystemTime());
		}
	}

	tmp = 'a';
	/*
	Capture standard input at end of timer cycle.
	*/
	tmp = std::cin.get();

	if (tmp == 'x')
	{
		exit(0);
	}

	/*
	dispose of the timer
	*/
	timer.dispose();



	return 0;
}

int Application::runMathTests()
{
	/*char tmp;

	vec3<double> bob(0.0, 0.0, 2.1 / 45.0);
	vec3<float> fred(100.1f / 1.0f, 0.0f, 0.0f);

	mat4<float> jane;
	jane = jane.identity();
	float angle = 30.0f;
	jane = jane.rotateMatrix(vec3<float>(angle, angle, angle));

	mat4<double> john;
	john = john.identity();
	double angle2 = 30.0;
	john = john.rotateMatrix(angle2, 'x');

	mat4<double> george;
	george = george.identity();

	Quaternion<float> betty(2.125f, fred * 3.33f);
	Quaternion<double> wentworth(4.4001, bob / 4.55);

	std::cout << "----****>Math Library Works<****----" << std::endl;

	std::cout << std::endl;

	std::cout << "----Vec3<double> test----" << "\n"
		<< "x : " << bob.x << "\n"
		<< "y : " << bob.y << "\n"
		<< "z : " << bob.z << "\n";

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;

	std::cout << "----Vec3<float> test----" << "\n"
		<< "x : " << fred.x << "\n"
		<< "y : " << fred.y << "\n"
		<< "z : " << fred.z << "\n";

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;

	std::cout << "----mat4<float> test----" << "\n"
		<< "I11 : " << jane.I11 << " I12 : " << jane.I12 << " I13 : " << jane.I13 << " I14 : " << jane.I14 << "\n"
		<< "I21 : " << jane.I21 << " I22 : " << jane.I22 << " I23 : " << jane.I23 << " I24 : " << jane.I24 << "\n"
		<< "I31 : " << jane.I31 << " I32 : " << jane.I32 << " I33 : " << jane.I33 << " I34 : " << jane.I34 << "\n"
		<< "I41 : " << jane.I41 << " I42 : " << jane.I42 << " I43 : " << jane.I43 << " I44 : " << jane.I44 << "\n";

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;

	std::cout << "----mat4<double> test----" << "\n"
		<< "I11 : " << john.I11 << " I12 : " << john.I12 << " I13 : " << john.I13 << " I14 : " << john.I14 << "\n"
		<< "I21 : " << john.I21 << " I22 : " << john.I22 << " I23 : " << john.I23 << " I24 : " << john.I24 << "\n"
		<< "I31 : " << john.I31 << " I32 : " << john.I32 << " I33 : " << john.I33 << " I34 : " << john.I34 << "\n"
		<< "I41 : " << john.I41 << " I42 : " << john.I42 << " I43 : " << john.I43 << " I44 : " << john.I44 << "\n";

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;

	std::cout << "----Quaternion<float> test----" << "\n"
		<< "Quaternion Vector" << "\n"
		<< "x : " << betty.v.x << "\n"
		<< "y : " << betty.v.y << "\n"
		<< "z : " << betty.v.z << "\n"
		<< "Quaternion Scalar" << "\n"
		<< "s : " << betty.s << "\n";

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;

	std::cout << "----Quaternion<double> test----" << "\n"
		<< "Quaternion Vector" << "\n"
		<< "x : " << wentworth.v.x << "\n"
		<< "y : " << wentworth.v.y << "\n"
		<< "z : " << wentworth.v.z << "\n"
		<< "Quaternion Scalar" << "\n"
		<< "s : " << wentworth.s << "\n";

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;

	tmp = std::cin.get();

	if (tmp == 'x')
	{
		exit(0);
	}*/

	return 0;
}