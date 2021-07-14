#pragma once

#include <CommonAPI/CommonAPI.hpp>
#include <v1/MediaPlayer/MediaPlayerStubDefault.hpp>

class MediaPlayerStubImpl: public v1_0::MediaPlayer::MediaPlayerStubDefault {
public:
    MediaPlayerStubImpl();
    virtual ~MediaPlayerStubImpl();
    const std::string& getTrackNameAttribute() override;
    const std::string& getTrackNameAttribute(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void setTrackNameAttribute(std::string _value)override;
    const uint16_t& getTrackTotalLengthAttribute()override;
    const uint16_t& getTrackTotalLengthAttribute(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void setTrackTotalLengthAttribute(uint16_t _value)override;
    const uint16_t& getPlayPositionAttribute()override;
    const uint16_t& getPlayPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void setPlayPositionAttribute(uint16_t _value)override;
    void setPlayPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _value)override;
    const ::v1::MediaPlayer::MediaPlayerTypes::CurrentState& getCurrentStateAttribute()override;
    const ::v1::MediaPlayer::MediaPlayerTypes::CurrentState& getCurrentStateAttribute(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void setCurrentStateAttribute(::v1::MediaPlayer::MediaPlayerTypes::CurrentState _value)override;

  
    void play(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void pause(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void next(const std::shared_ptr<CommonAPI::ClientId> _client)override;
    void previous(const std::shared_ptr<CommonAPI::ClientId> _client)override;
};


