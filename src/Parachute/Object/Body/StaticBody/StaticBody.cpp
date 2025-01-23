#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./StaticBody.h"

using namespace Parachute;

StaticBody::StaticBody()
{
}

StaticBody::~StaticBody()
{
}

void StaticBody::Update()
{
    Body::Update();
}