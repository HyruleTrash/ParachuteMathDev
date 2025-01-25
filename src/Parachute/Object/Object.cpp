#pragma once
#include "./Object.h"
#include "Object.h"

using namespace Parachute;

void Parachute::Object::Update()
{
    bounds = {size};
}