//Title:C++ Programming Homework
//Microsoft Visual Studio 2015
//Date: 4.08.2016

#include "defines.h"
#include "includes.h"

//Custom functions:
void first_function( unsigned int range_1 ); // every method can be with more arguments
void second_function( unsigned int range_2 );
void third_function( unsigned int range_3 );
void fourth_function( unsigned int range_4 );


//Mutex object creation, used in functions for threads to lock shared components, like console output 
mutex mtx;

//Main function
int main(int argc, const char * argv[])
{

#ifdef DEBUG //in Debug mode that shows program execution time
	clock_t startTime;
	startTime = clock();
#endif // DEBUG

		
	//container, which holds all threads for easy managment
	vector<thread*> threadsVector;
		
	//thread creation, for every function different thread
	//after this point all functions will start working

	thread first_thread( first_function, 10 );
	thread second_thread( second_function, 20 );
	thread third_thread( third_function, 30 );
	thread fourth_thread( fourth_function, 40 );

	//put all created threads in vector
	threadsVector.push_back( &first_thread );
	threadsVector.push_back( &second_thread );
	threadsVector.push_back( &third_thread );
	threadsVector.push_back( &fourth_thread );
	
	//complete all active threads
	for (size_t i = 0; i < threadsVector.size(); i++ )
	{
		threadsVector.at(i)->join();
	}
	

#ifdef DEBUG  //in Debug mode that shows program execution time
	startTime = clock() - startTime;
	cout << "\nPROGRAM execution time is: " << ((float)startTime) / CLOCKS_PER_SEC << " seconds.\n" << endl;
#endif // DEBUG

	return 0;
}


void first_function( unsigned int range_1 )
{
	unsigned int sum{0};

	for( size_t i = 0; i < range_1; ++i)
	{
		sum += i;
	}

	mtx.lock();
	cout << "first sum: " << sum << endl;
	mtx.unlock();
} 

void second_function( unsigned int range_2 )
{
	unsigned int sum{0};

	for( size_t i = 0; i < range_2; ++i)
	{
		sum += i;
	}

	mtx.lock();
	cout << "second sum: " << sum << endl;
	mtx.unlock();
}


void third_function( unsigned int range_3 )
{
	unsigned int sum{0};

	for( size_t i = 0; i < range_3; ++i)
	{
		sum += i;
	}

	mtx.lock();
	cout << "third sum: " << sum << endl;
	mtx.unlock();
}

void fourth_function( unsigned int range_4 )
{
	unsigned int sum{0};

	for( size_t i = 0; i < range_4; ++i)
	{
		sum += i;
	}

	mtx.lock();
	cout << "fourth sum: " << sum << endl;
	mtx.unlock();
}


