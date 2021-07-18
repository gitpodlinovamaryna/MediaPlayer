#include <iostream>
#include "DevMediaPlayer.h"

int main()
{
    MediaPlayer::DevMediaPlayer devMediaPlayer;
    int userChoice;

    while (true)
    {
        std::cout << "Track name: " << devMediaPlayer.getTrackName() << " is " << std::endl;

        std::cout << "1 - play, 2 - pause, 3 - next, 4 - previous, 0 - exit" << std::endl;
        std::cout << "Please select an action:" << std::endl;
        std::cin >> userChoice;

        if (userChoice == 0) break;

        switch (userChoice)
        {
          case 1:
            // play
            break;
          case 2:
            // pause
            break;
          case 3:
            devMediaPlayer.next();
            break;
          case 4:
            // previous
            break;
          default:
            break;
        }
    }

    return 0;
}

