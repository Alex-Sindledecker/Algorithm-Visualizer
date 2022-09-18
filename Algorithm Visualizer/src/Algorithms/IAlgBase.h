#pragma once

enum class Complexity
{
    O_1, O_LOG_N, O_N, O_N_LOG_N, O_N2, O_2N, O_NF 
};

class IAlgBase
{
public:
    virtual ~IAlgBase() = 0 {}
    virtual void enqueueState() = 0;
    virtual bool dequeueState() = 0;
    virtual Complexity getTimeComplexity() = 0;
    virtual Complexity getSpaceComplexity() = 0;
};