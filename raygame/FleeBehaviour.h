#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
class FleeBehaviour :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce();
};

