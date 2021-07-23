#pragma once

#include <boost/asio.hpp>
#include "DevMediaPlayer.h"

namespace MediaPlayer
{
class MediaPlayerComponent
{
public:
    virtual ~MediaPlayerComponent();

    static MediaPlayerComponent& Instance();
    void Routine();

private:
    MediaPlayerComponent();
    MediaPlayerComponent(const MediaPlayerComponent&) = delete;
    MediaPlayerComponent(const MediaPlayerComponent&&) = delete;
    MediaPlayerComponent& operator=(const MediaPlayerComponent&) = delete;
    MediaPlayerComponent& operator=(const MediaPlayerComponent&&) = delete;

    boost::asio::io_context m_io_context;
};
} // namespace MediaPlayer
