#pragma once

#include "Common/Challenge.h"

class CChallenge_01 : public CChallenge
{
private:
    virtual EErrorCode SetUp_FirstPart() override;
    virtual EErrorCode Run_FirstPart() override;
    virtual EErrorCode CleanUp_FirstPart() override;

    virtual EErrorCode SetUp_SecondPart() override;
    virtual EErrorCode Run_SecondPart() override;
    virtual EErrorCode CleanUp_SecondPart() override;

    static std::string const sm_inputFilePath;

    EErrorCode InitiChallenge01();

    int FindProductOfSumEntries(int _count, int _index = 0, int _sumValue = 0, int _productValue = 1) const;
    int* m_InputElements = nullptr;
    size_t m_InputElementsSize = 0;

};
