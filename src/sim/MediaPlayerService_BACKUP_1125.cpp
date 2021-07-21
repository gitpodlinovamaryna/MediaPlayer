#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "MediaPlayerStubImpl.h"

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<MediaPlayerSim::MediaPlayerStubImpl> myService =
    	std::make_shared<MediaPlayerSim::MediaPlayerStubImpl>();
    runtime->registerService("local", "MediaPlayer", myService);
    std::cout << "Successfully Registered Service!" << std::endl;

    while (true)
    {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
<<<<<<< HEAD
        std::this_thread::sleep_for(std::chrono::seconds(1));
=======
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
>>>>>>> origin/master
    }

    return 0;
 }
