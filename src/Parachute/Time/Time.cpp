#pragma once
#include "./Time.h"

using namespace Parachute;

Time::Time()
{
    startTime = std::chrono::high_resolution_clock::now();
    runTime = std::chrono::duration_cast<std::chrono::duration<double>>(startTime - startTime).count();
}

Time::~Time()
{
}

void Time::Update()
{
    auto now = std::chrono::high_resolution_clock::now();
    double t_runTime = std::chrono::duration_cast<std::chrono::duration<double>>(now - startTime).count();
    deltaTime = t_runTime - runTime;
    runTime = t_runTime;
}