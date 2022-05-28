#include "FamilyCar.h"
#include "SportCar.h"

int main() {

	FamilyCar famcar(220, 0, 100);

	famcar.startMovement();
	famcar.accelerate();
	famcar.accelerate();
	famcar.accelerate();
	famcar.stopMovement();


	SportCar spocar(250, 0, 2000);
	spocar.startMovement();
	spocar.accelerate();
	spocar.accelerate();
	spocar.accelerate();
	spocar.stopMovement();

	return 0;
}