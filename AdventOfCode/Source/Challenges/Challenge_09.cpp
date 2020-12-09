#include "Challenge_09.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_09::sm_inputFilePath = "Inputs/Input_Challenge_09.txt";



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_09::SetUp_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }
    
    for (size_t idx = 25; idx < lines.size(); ++idx)
    {
        m_RemainingElements.push_back(atoi(lines[idx].c_str()));
    }

    return EErrorCode::Success;
}

EErrorCode CChallenge_09::Run_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    for (size_t idx = 0; idx < m_RemainingElements.size(); ++idx)
    {
        int count = 0;
        int sumFound = false;

        // Loop through the previous 25 elements
        for (size_t j = idx; j < lines.size(); ++j)
        {
            if (25 < count)
                continue;

            for (size_t k = j+1; k < lines.size(); ++k)
            {
                // Sum and check if we found value
                long long sum = atoll(lines[k].c_str()) + atoll(lines[j].c_str());
                if (sum == m_RemainingElements[idx])
                {
                    sumFound = true;
                    break;
                }
            }

            if (sumFound)
                break;

            ++count;
        }

        if (!sumFound)
        {
            std::cout << "Invalid Number : " << m_RemainingElements[idx] << std::endl;
            //std::cout << "Range is: " << idx << " - " << idx + 25 << std::endl;
            break;
        }

    }

    return EErrorCode::Success;
}

EErrorCode CChallenge_09::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_09::SetUp_SecondPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_09::Run_SecondPart()
{
    const long long invaildNumber = 50047984;

    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    bool sumFound = false;
    long long totalSum = 0;

    for (size_t i = 0; i < lines.size(); ++i)
    { 
        totalSum = atoll(lines[i].c_str());

        for (size_t j = i + 1; j < lines.size(); ++j)
        {
            totalSum += atoll(lines[j].c_str());

            if (totalSum == invaildNumber)
            {
                // Do stuff
                std::cout << "Found the range: " << atoll(lines[i].c_str()) << "-" << atoll(lines[j].c_str()) << std::endl;

                long long minValue = invaildNumber;
                long long maxValue = -1;
                for (size_t k = i; k <= j; ++k)
                {
                    long long kValue = atoll(lines[k].c_str());
                    if (kValue > maxValue)
                        maxValue = kValue;
                    if (kValue < minValue)
                        minValue = kValue;
                }

                std::cout << "Final answer: " << minValue + maxValue << std::endl;
                break;
            }

            if (totalSum > invaildNumber)
            {
                break;
            }
        }
    }

    return EErrorCode::Success;
}

EErrorCode CChallenge_09::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}
