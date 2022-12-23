#include "platform-private-pch.h"

#include <mutex>

c_mutex::c_mutex() :
	implementation(new std::mutex())
{

}

c_mutex::~c_mutex()
{
	std::mutex* mutex = static_cast<std::mutex*>(implementation);
	delete mutex;
}

void c_mutex::lock()
{
	std::mutex* mutex = static_cast<std::mutex*>(implementation);
	mutex->lock();
}

bool c_mutex::try_lock()
{
	std::mutex* mutex = static_cast<std::mutex*>(implementation);
	return mutex->try_lock();
}

void c_mutex::unlock()
{
	std::mutex* mutex = static_cast<std::mutex*>(implementation);
	mutex->unlock();
}
