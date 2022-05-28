#ifndef HOUR_H
#define HOUR_h

const int MIN_HOUR = 0;
const int MAX_HOUR = 24;

const int MIN_MINUTES = 0;
const int MAX_MINUTES = 60;

class Hour {
private:
	int hour;
	int minutes;

public:
	Hour();
	Hour(const int& hour, const int& minutes);
	Hour& operator=(const Hour& other);

	Hour operator-(const Hour& other) const;

	bool operator<=(const Hour& event) const;
	bool operator>=(const Hour& event) const;

	int getHour() const;
	int getMinutes() const;

	void setHour(const int& hour);
	void setMinutes(const int& minutes);
};
#endif
