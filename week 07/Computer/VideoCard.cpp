#include "VideoCard.h"

VideoCard::VideoCard() : Component()
{
}

VideoCard::VideoCard(const char* desc, const int& id) : Component(desc,id)
{
}

VideoCard::VideoCard(const VideoCard& other) : Component(other)
{
}

void VideoCard::print() const
{
	Component::print();
}

void VideoCard::read()
{
	Component::read();
}
