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

    void updateUi();

    boost::asio::io_context m_ioContext;
    boost::asio::executor_work_guard<boost::asio::executor> m_workGuard;
    MediaPlayer::DevMediaPlayer m_devMediaPlayer;
};
} // namespace MediaPlayer
