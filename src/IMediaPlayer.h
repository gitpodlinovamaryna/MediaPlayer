#pragma once

#include <boost/signals2.hpp>
#include <string>

class IMediaPlayer
{
public:
    boost::signals2::signal<void ()> trackNameDelegate;
    virtual const std::string& getTrackName() = 0;
};
