#pragma once

class IAlgBase
{
public:
    virtual ~IAlgBase() = 0 {}
    virtual void enqueueState() = 0;
    virtual bool dequeueState() = 0;
};