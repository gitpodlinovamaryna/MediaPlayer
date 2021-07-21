#include <iostream>
#include <exception>
#include "MediaPlayerComponent.h"

int main()
{
    try
    {
        MediaPlayer::MediaPlayerComponent::Instance().Routine();
    }
    catch (const std::exception& e)
    {
        std::cout << "A standard exception was caught, with message: " <<
            e.what() << std::endl;
    }

    return 0;
}
