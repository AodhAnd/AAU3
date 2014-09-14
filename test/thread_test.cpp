/*
 * thread_test.cpp
 *
 *  Created on: 01/09/2014
 *      Author: benjaminkrebs
 */



#include <iostream>

using namespace std;



void threadFunc(void)
{
	cout<<"hello from thread"<<endl;
}


int main()
{
	/*
	boost::asio::io_service ioService;
	boost::asio::deadline_timer dTimer(ioService,boost::posix_time::milliseconds(1000));
	boost::thread testThread(threadFunc);
	for (int i = 0; i < 1000; ++i) {
		//testThread.start_thread();
		dTimer.wait();
		testThread.start_thread();
		ioService.run();
	}
	testThread.join();*/



}


