#pragma once

#include <boost/signals2.hpp>
#include <string>

namespace MediaPlayer
{
class IMediaPlayer
{
public:
    virtual const std::string& getTrackName() = 0;
    virtual const boost::signals2::signal<void ()>& getTrackNameDelegate() = 0;
};
}


