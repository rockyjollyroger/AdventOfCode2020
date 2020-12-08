#pragma once

#include "Common/Challenge.h"

class CChallenge_06 : public CChallenge
{
private:
    virtual EErrorCode SetUp_FirstPart() override;
    virtual EErrorCode Run_FirstPart() override;
    virtual EErrorCode CleanUp_FirstPart() override;

    virtual EErrorCode SetUp_SecondPart() override;
    virtual EErrorCode Run_SecondPart() override;
    virtual EErrorCode CleanUp_SecondPart() override;

    void CreateSingleLineAnswers();

    std::vector<std::string> m_SingleLineAnswers;
    static std::string const sm_inputFilePath;
};