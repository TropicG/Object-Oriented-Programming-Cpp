#ifndef VIDEOCARD
#define VIDEOCARD
#include "Component.h"

class VideoCard : public Component {
public:
	VideoCard();
	VideoCard(const char* desc, const int& id);
	VideoCard(const VideoCard& other);

	void print() const;
	void read();
};
#endif

