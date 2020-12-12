#include "Challenge_11.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_11::sm_inputFilePath = "Inputs/Input_Challenge_11.txt";



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_11::SetUp_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_11::Run_FirstPart()
{
    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_11::CleanUp_FirstPart()
{
    return EErrorCode::NotImplemented;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_11::SetUp_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }
    
    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_11::Run_SecondPart()
{
    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_11::CleanUp_SecondPart()
{
    return EErrorCode::NotImplemented;
}
