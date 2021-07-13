#pragma once

#include "IMediaPlayer.h"
#include <memory>
#include <v1/MediaPlayer/MediaPlayerProxy.hpp>

namespace MediaPlayer{
class DevMediaPlayer : public IMediaPlayer
{
private:
    using MediaPlayerProxy = ::v1::MediaPlayer::MediaPlayerProxy<>;
    
public:
    DevMediaPlayer();
    virtual ~DevMediaPlayer();

    const std::string& getTrackName() override;
    virtual const boost::signals2::signal<void ()>& getTrackNameDelegate() override;

private:
    void createProxy();
    void onTrackNameChanged(const std::string& trackName);

    std::shared_ptr<MediaPlayerProxy> m_pMediaPlayerProxy;
    std::string m_TrackName;
    boost::signals2::signal<void ()> m_trackNameDelegate;
};
}