#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class MoveComponet;
class SeekBehaviour :
	public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce();

};

