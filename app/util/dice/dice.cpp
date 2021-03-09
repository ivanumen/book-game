#include "dice.h"

#include <cstdlib>

int NDice::usingD6() {
	return rand() % 6 + 1;
}
