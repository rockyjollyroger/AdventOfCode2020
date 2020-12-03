#pragma once

#include "Common/Challenge.h"

class CChallenge_03 : public CChallenge
{
private:
    virtual EErrorCode SetUp_FirstPart() override;
    virtual EErrorCode Run_FirstPart() override;

    size_t NumberOfHit(std::vector<std::string> &lines, char tree, size_t stepRight, size_t stepDown) const;

    virtual EErrorCode CleanUp_FirstPart() override;

    virtual EErrorCode SetUp_SecondPart() override;
    virtual EErrorCode Run_SecondPart() override;
    virtual EErrorCode CleanUp_SecondPart() override;

    static std::string const sm_inputFilePath;
};
