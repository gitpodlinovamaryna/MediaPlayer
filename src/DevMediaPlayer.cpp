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

        m_pMediaPlayerProxy->getCurrentStateAttribute().getChangedEvent().subscribe(
            std::bind(&DevMediaPlayer::onCurrentStateChanged, this, std::placeholders::_1)
        );

        m_pMediaPlayerProxy->getCurrentStateAttribute().getValueAsync(
            [this](const CommonAPI::CallStatus&,
            ::v1::MediaPlayer::MediaPlayerTypes::CurrentState currentState) {
                onCurrentStateChanged(currentState);
            },
            &callInfo);
    }
    else
    {
        std::cout << "Media Player Proxy is null" << std::endl;
    }
}

void DevMediaPlayer::next()
{
    if (m_pMediaPlayerProxy)
    {
        CommonAPI::CallStatus callStatus;
        m_pMediaPlayerProxy->next(callStatus);
    }
}

void DevMediaPlayer::play()
{
    if (m_pMediaPlayerProxy)
    {
        CommonAPI::CallStatus callStatus;
        m_pMediaPlayerProxy->play(callStatus);
    }
}

void DevMediaPlayer::previous()
{
    if (m_pMediaPlayerProxy)
    {
        CommonAPI::CallStatus callStatus;
        m_pMediaPlayerProxy->previous(callStatus);
    }
}

void DevMediaPlayer::pause()
{
    if (m_pMediaPlayerProxy)
    {
        CommonAPI::CallStatus callStatus;
        m_pMediaPlayerProxy->pause(callStatus);
    }
}

void DevMediaPlayer::onTrackNameChanged(const std::string& trackName)
{
    m_trackName = trackName;
    m_trackNameDelegate();
}

void DevMediaPlayer::onCurrentStateChanged(const ::v1::MediaPlayer::MediaPlayerTypes::CurrentState& currentState)
{
    m_currentState = currentState;
    m_currentStateDelegate();
}
}
