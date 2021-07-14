#include <CommonAPI/CommonAPI.hpp>
#include <functional>
#include "DevMediaPlayer.h"

namespace MediaPlayer
{

DevMediaPlayer::DevMediaPlayer()
: m_trackName()
{
    createProxy();
}

DevMediaPlayer::~DevMediaPlayer() = default;

void DevMediaPlayer::createProxy()
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    if (runtime)
    {
        m_pMediaPlayerProxy = runtime->buildProxy<v1::MediaPlayer::MediaPlayerProxy>("local", "MediaPlayer");
    }

    if (m_pMediaPlayerProxy)
    {
        m_pMediaPlayerProxy->getTrackNameAttribute().getChangedEvent().subscribe(
            std::bind(&DevMediaPlayer::onTrackNameChanged, this, std::placeholders::_1)
        );
        CommonAPI::CallInfo callInfo;
        m_pMediaPlayerProxy->getTrackNameAttribute().getValueAsync(
            [this](const CommonAPI::CallStatus&, std::string trackName) {
              onTrackNameChanged(trackName);
            },
            &callInfo);
    }
    else
    {
        std::cout << "Media Player Proxy is null" << std::endl;
    }
}

void DevMediaPlayer::onTrackNameChanged(const std::string& trackName)
{
    m_trackName = trackName;
    m_trackNameDelegate();
}
}

