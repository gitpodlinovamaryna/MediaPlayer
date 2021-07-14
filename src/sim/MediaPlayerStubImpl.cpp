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
    setTrackNameAttribute(m_trackNames[0]);

    setCurrentStateAttribute(v1::MediaPlayer::MediaPlayerTypes::CurrentState::PAUSED);
}

MediaPlayerStubImpl::~MediaPlayerStubImpl() = default;

void MediaPlayerStubImpl::play(const std::shared_ptr<CommonAPI::ClientId> _client){}

void MediaPlayerStubImpl::pause(const std::shared_ptr<CommonAPI::ClientId> _client){}

void MediaPlayerStubImpl::next(const std::shared_ptr<CommonAPI::ClientId> _client){}

void MediaPlayerStubImpl::previous(const std::shared_ptr<CommonAPI::ClientId> _client){}
}
