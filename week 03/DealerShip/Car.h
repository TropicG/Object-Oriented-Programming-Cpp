#ifndef CAR
#define CAR
#include "Engine.h"
#include "Visual.h"
#include "Details.h"

class Car {
private:
	Engine eng;
	Visual vis;
	Details d;

public:
	Car();
	Car(const Engine& eng, const Visual& vis, const Details& d);
	Car& operator=(const Car& other);

	bool operator==(const Car& other) const;

	Engine& getEngine();
	Visual& getVisual();
	Details& getDetails();

	const Engine& getEngine() const;
	const Visual& getVisual() const;
	const Details& getDetails() const;

	void setEngine(const Engine& eng);
	void setVisual(const Visual& vis);
	void setDetails(const Details& d);

	void print() const;
	void read();
};
#endif
