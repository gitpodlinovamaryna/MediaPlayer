#include <iostream>
#include "DevMediaPlayer.h"

int main()
{
    MediaPlayer::DevMediaPlayer devMediaPlayer;
    std::cout << "Track name: " << devMediaPlayer.getTrackName() << std::endl;
    
    return 0;
}

