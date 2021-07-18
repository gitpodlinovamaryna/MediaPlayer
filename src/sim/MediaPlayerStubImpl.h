#pragma once

#include <vector>
#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/MediaPlayer/MediaPlayerStubDefault.hpp>

namespace MediaPlayerSim
{
class MediaPlayerStubImpl : public v1::MediaPlayer::MediaPlayerStubDefault
{
public:
    MediaPlayerStubImpl();
    virtual ~MediaPlayerStubImpl();

    void play(const std::shared_ptr<CommonAPI::ClientId> _client) override;
    void pause(const std::shared_ptr<CommonAPI::ClientId> _client) override;
    void next(const std::shared_ptr<CommonAPI::ClientId> _client) override;
    void previous(const std::shared_ptr<CommonAPI::ClientId> _client) override;

private:
    std::vector<std::string> m_trackNames;
    decltype(m_trackNames)::size_type m_playingTrackNumber;
};
}
