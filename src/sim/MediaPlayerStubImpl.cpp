#include "MediaPlayerStubImpl.h"

namespace MediaPlayerSim
{
MediaPlayerStubImpl::MediaPlayerStubImpl()
{
    m_trackNames = {
        "Lucy in the Sky With Diamonds",
        "Lady Madonna",
        "Love Me Do",
        "Here Comes the Sun"};
    m_playingTrackNumber = 0;
    setTrackNameAttribute(m_trackNames[m_playingTrackNumber]);

    setCurrentStateAttribute(v1::MediaPlayer::MediaPlayerTypes::CurrentState::PAUSED);
}

MediaPlayerStubImpl::~MediaPlayerStubImpl() = default;

void MediaPlayerStubImpl::play(const std::shared_ptr<CommonAPI::ClientId> _client)
{
    setCurrentStateAttribute(v1::MediaPlayer::MediaPlayerTypes::CurrentState::PLAYING);
}

void MediaPlayerStubImpl::pause(const std::shared_ptr<CommonAPI::ClientId> _client)
{
    setCurrentStateAttribute(v1::MediaPlayer::MediaPlayerTypes::CurrentState::PAUSED);
}

void MediaPlayerStubImpl::next(const std::shared_ptr<CommonAPI::ClientId> _client)
{
    m_playingTrackNumber = (m_playingTrackNumber + 1) % m_trackNames.size();
    setTrackNameAttribute(m_trackNames[m_playingTrackNumber]);
}

void MediaPlayerStubImpl::previous(const std::shared_ptr<CommonAPI::ClientId> _client)
{
    m_playingTrackNumber = (m_playingTrackNumber - 1) % m_trackNames.size();
    setTrackNameAttribute(m_trackNames[m_playingTrackNumber]);
}
}
