#include "Computer.h"

void Computer::clearHardDrive()
{
	delete this->hd;
}

void Computer::clearProcessor()
{
	delete this->pro;
}

void Computer::clearRam()
{
	delete this->ram;
}

void Computer::clearVideoCard()
{
	delete this->vid;
}

Computer::Computer() : hd(nullptr), pro(nullptr), ram(nullptr), vid(nullptr)
{
}

Computer::Computer(const HardDrive& hd, const Processor& pro, const Ram& ram, const VideoCard& vid)
{
	this->setHardDrive(hd);
	this->setProcessor(pro);
	this->setRam(ram);
	this->setVideoCard(vid);
}

Computer::~Computer()
{
	this->clearHardDrive();
	this->clearProcessor();
	this->clearRam();
	this->clearVideoCard();
}

HardDrive Computer::getHardDrive() const
{
	return *this->hd;
}

Processor Computer::getProcessor() const
{
	return *this->pro;
}

Ram Computer::getRam() const
{
	return *this->ram;
}

VideoCard Computer::getVideo() const
{
	return *this->vid;
}

void Computer::setHardDrive(const HardDrive& hd)
{
	this->clearHardDrive();
	this->hd = new HardDrive(hd);
}

void Computer::setProcessor(const Processor& pro)
{
	this->clearProcessor();
	this->pro = new Processor(pro);
}

void Computer::setRam(const Ram& ram)
{
	this->clearRam();
	this->ram = new Ram(ram);
}

void Computer::setVideoCard(const VideoCard& vid)
{
	this->clearVideoCard();
	this->vid = new VideoCard(vid);
}

void Computer::read()
{
	HardDrive hd;
	std::cout << "Enter the Hard Drive parameters of the computer" << std::endl;
	hd.read();
	this->setHardDrive(hd);

	Processor pro;
	std::cout << "Enter the Processor parameters of the computer: " << std::endl;
	pro.read();
	this->setProcessor(pro);

	Ram ram;
	std::cout << "Enter the Ram parameters of the computer: " << std::endl;
	ram.read();
	this->setRam(ram);

	VideoCard vid;
	std::cout << "Enter the Video card parameters of the computer: " << std::endl;
	vid.read();
	this->setVideoCard(vid);

	std::cout << std::endl;
}

void Computer::print() const
{
	this->getHardDrive().print();
	this->getProcessor().print();
	this->getRam().print();
	this->getVideo().print();
}
