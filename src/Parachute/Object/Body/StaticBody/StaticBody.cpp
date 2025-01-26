#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./StaticBody.h"
#include "StaticBody.h"

using namespace Parachute;

void StaticBody::Update()
{
    Body::Update();
}

double StaticBody::GetDensity()
{
    return INFINITY;
}