#ifndef COMPUTER
#define COMPUTER
#include "HardDrive.h"
#include "Processor.h"
#include "Ram.h"
#include "VideoCard.h"

class Computer {
private:
	HardDrive* hd = nullptr;
	Processor* pro = nullptr;
	Ram* ram = nullptr;
	VideoCard* vid = nullptr;

private:
	void clearHardDrive();
	void clearProcessor();
	void clearRam();
	void clearVideoCard();

public:
	Computer();
	Computer(const HardDrive& hd, const Processor& pro, const Ram& ram, const VideoCard& vid);
	~Computer();

	HardDrive getHardDrive() const;
	Processor getProcessor() const;
	Ram getRam() const;
	VideoCard getVideo() const;

	void setHardDrive(const HardDrive& hd);
	void setProcessor(const Processor& pro);
	void setRam(const Ram& ram);
	void setVideoCard(const VideoCard& vid);

	void read();
	void print() const;
};
#endif