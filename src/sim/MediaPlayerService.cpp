#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "MediaPlayerStubImpl.h"

using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<MediaPlayerStubImpl> myService =
    	std::make_shared<MediaPlayerStubImpl>();
    runtime->registerService("local", "test", myService);
    std::cout << "Successfully Registered Service!" << std::endl;

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    return 0;
 }
