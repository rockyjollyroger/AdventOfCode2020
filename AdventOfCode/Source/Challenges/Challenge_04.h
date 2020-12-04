#pragma once

#include "Common/Challenge.h"

class CChallenge_04 : public CChallenge
{
private:
    virtual EErrorCode SetUp_FirstPart() override;
    virtual EErrorCode Run_FirstPart() override;
    virtual EErrorCode CleanUp_FirstPart() override;

    virtual EErrorCode SetUp_SecondPart() override;
    virtual EErrorCode Run_SecondPart() override;
    virtual EErrorCode CleanUp_SecondPart() override;

    static std::string const sm_inputFilePath;

    EErrorCode InitiChallenge04();
    void CreateSingleLinePassports();

    std::vector<std::string> m_InputElements;
    size_t m_InputElementsSize = 0;
};
