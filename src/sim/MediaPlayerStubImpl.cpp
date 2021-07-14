#include "MediaPlayerStubImpl.h"

MediaPlayerStubImpl::MediaPlayerStubImpl() { }
MediaPlayerStubImpl::~MediaPlayerStubImpl() { }

void MediaPlayerStubImpl::play(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::pause(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::next(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::previous(const std::shared_ptr<CommonAPI::ClientId> _client){}

const std::string& MediaPlayerStubImpl::getTrackNameAttribute(){}
const std::string& MediaPlayerStubImpl::getTrackNameAttribute(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::setTrackNameAttribute(std::string _value){}
const uint16_t& MediaPlayerStubImpl::getTrackTotalLengthAttribute(){}
const uint16_t& MediaPlayerStubImpl::getTrackTotalLengthAttribute(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::setTrackTotalLengthAttribute(uint16_t _value){}
const uint16_t& MediaPlayerStubImpl::getPlayPositionAttribute(){}
const uint16_t& MediaPlayerStubImpl::getPlayPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::setPlayPositionAttribute(uint16_t _value){}
void MediaPlayerStubImpl::setPlayPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _value){}
const ::v1::MediaPlayer::MediaPlayerTypes::CurrentState& MediaPlayerStubImpl::getCurrentStateAttribute(){}
const ::v1::MediaPlayer::MediaPlayerTypes::CurrentState& MediaPlayerStubImpl::getCurrentStateAttribute(const std::shared_ptr<CommonAPI::ClientId> _client){}
void MediaPlayerStubImpl::setCurrentStateAttribute(::v1::MediaPlayer::MediaPlayerTypes::CurrentState _value){}