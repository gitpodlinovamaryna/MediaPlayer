#pragma once

#include <boost/signals2.hpp>
#include <string>
#include <v1/MediaPlayer/MediaPlayerTypes.hpp>

namespace MediaPlayer
{
class IMediaPlayer
{
public:
    virtual const std::string& getTrackName() = 0;
    virtual const boost::signals2::signal<void ()>& getTrackNameDelegate() = 0;
    virtual const ::v1::MediaPlayer::MediaPlayerTypes::CurrentState& getCurrentStateAttribute() = 0;
};
}
