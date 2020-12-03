#include "Challenge_02.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_02::sm_inputFilePath = "Inputs/Input_Challenge_02.txt";



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_02::SetUp_FirstPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_02::Run_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    int validPasswordCount = 0;
    for (size_t lineIdx = 0; lineIdx < lines.size(); ++lineIdx)
    {
        const std::string& currentValue = lines[lineIdx];

        //get separator index
        const size_t seperatorDash = currentValue.find('-');
        const size_t seperatorColon = currentValue.find(':');

        //Params
        const int minCharCount = atoi(currentValue.substr(0, seperatorDash).c_str());
        const int maxCharCount = atoi(currentValue.substr(seperatorDash + 1, seperatorColon - 2).c_str());
        const char vaildLetter = currentValue[seperatorColon-1];

        //Looping the Password
        int charCount = 0;
        for (size_t i = seperatorColon + 2; i < currentValue.size(); ++i)
        {
            if (currentValue[i] == vaildLetter)
            {
                charCount++;
            }
        }

        //Passes Policy
        if (charCount >= minCharCount && charCount <= maxCharCount)
        {
            validPasswordCount++;
        }
    }

    std::cout << "(PART 1) Total Number of valid passwords: " << validPasswordCount << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_02::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_02::SetUp_SecondPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_02::Run_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    int validPasswordCount = 0;
    for (size_t lineIdx = 0; lineIdx < lines.size(); ++lineIdx)
    {
        const std::string& currentValue = lines[lineIdx];

        //get separator index
        const size_t seperatorDash = currentValue.find('-');
        const size_t seperatorColon = currentValue.find(':');

        //Params
        const int firstCharPosition = atoi(currentValue.substr(0, seperatorDash).c_str());
        const int secondCharPosition = atoi(currentValue.substr(seperatorDash + 1, seperatorColon - 2).c_str());
        const char vaildLetter = currentValue[seperatorColon - 1];
        const std::string& password = currentValue.substr(seperatorColon + 2);

        //Looping the Password
        int charCount = 0;

        if (password[firstCharPosition-1] == vaildLetter)
            charCount++;

        if (password[secondCharPosition-1] == vaildLetter)
            charCount++;

        if (charCount == 1)
            validPasswordCount++;
    }

    std::cout << "(PART 2) Total Number of valid passwords: " << validPasswordCount << std::endl;
    return EErrorCode::Success;
}

EErrorCode CChallenge_02::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}
