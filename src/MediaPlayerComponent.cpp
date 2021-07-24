#include "MediaPlayerComponent.h"
#include <boost/bind/bind.hpp>
#include <iostream>

namespace MediaPlayer
{
MediaPlayerComponent& MediaPlayerComponent::Instance()
{
    static MediaPlayerComponent instance;
    return instance;
}

MediaPlayerComponent::MediaPlayerComponent()
: m_ioContext()
, m_workGuard(m_ioContext.get_executor())
, m_devMediaPlayer()
{
    m_devMediaPlayer.getTrackNameDelegate().connect([this] {
        boost::asio::post(m_ioContext, boost::bind(&MediaPlayerComponent::updateUi, this));
    });
    m_devMediaPlayer.getCurrentStateDelegate().connect([this] {
        boost::asio::post(m_ioContext, boost::bind(&MediaPlayerComponent::updateUi, this));
    });
}

MediaPlayerComponent::~MediaPlayerComponent() = default;

void MediaPlayerComponent::Routine()
{
    std::cout << "\033[2J" << std::endl;
    m_ioContext.run();
    /*MediaPlayer::DevMediaPlayer devMediaPlayer;
    int userChoice;

    while (true)
    {
        std::cout << "Track name: " << devMediaPlayer.getTrackName() << std::endl;
        std::cout << "Current State is "  << devMediaPlayer.getCurrentStateAttribute() << std::endl;
        std::cout << "1 - play, 2 - pause, 3 - next, 4 - previous, 0 - exit" << std::endl;
        std::cout << "Please select an action:" << std::endl;
        std::cin >> userChoice;

        if (userChoice == 0) break;

        switch (userChoice)
        {
          case 1:
            devMediaPlayer.play();
            break;
          case 2:
            devMediaPlayer.pause();
            break;
          case 3:
            devMediaPlayer.next();
            break;
          case 4:
            devMediaPlayer.previous();
            break;
          default:
            break;
        }
    }*/
}

void MediaPlayerComponent::updateUi()
{}

} // namespace MediaPlayer
