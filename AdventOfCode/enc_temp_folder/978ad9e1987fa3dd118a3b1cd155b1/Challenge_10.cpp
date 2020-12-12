#include "Challenge_10.h"
#include "../Helpers/FileHelpers.h"
#include <algorithm> 
//#include <math.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_10::sm_inputFilePath = "Inputs/Input_Challenge_10.txt";

////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_10::SetUp_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    std::vector<long long> linesIntList;

    linesIntList.push_back(0); //Test the 0
    for (size_t i = 0; i < lines.size(); ++i)
    {
        linesIntList.push_back(atoi(lines[i].c_str()));
    }
    linesIntList.push_back(linesIntList.back() + 3); // Adaptors build in jolt

    std::sort(linesIntList.begin(), linesIntList.end()); //sorts by lesser by default
    m_SortedJoltsList = linesIntList;

    return EErrorCode::Success;
}

EErrorCode CChallenge_10::Run_FirstPart()
{
    int joltLowestDiffCount = 0; //The 0 Jolt counts
    int joltDiffHighestCount = 0; // to take into account the built in adapter

    long long currentJolt = 0;

    for (int joltIdx = 0; joltIdx < m_SortedJoltsList.size(); ++joltIdx)
    {
        if (currentJolt == 0)
        {
            currentJolt = m_SortedJoltsList[joltIdx];
            continue;
        }

        long long joltDiff = m_SortedJoltsList[joltIdx] - currentJolt;

        if (joltDiff > 3)
            std::cout << "There is a diff > 3 @" << m_SortedJoltsList[joltIdx] << std::endl;


        if (joltDiff == 1)
            ++joltLowestDiffCount;

        bool endOfList = joltIdx == m_SortedJoltsList.size() - 1;
        if (joltDiff == 3)
            ++joltDiffHighestCount;

        currentJolt = m_SortedJoltsList[joltIdx];
    }

    std::cout << "There are " << joltLowestDiffCount << " differences of 1 jolt" << std::endl;
    std::cout << "There are " << joltDiffHighestCount << " differences of 3 jolt" << std::endl;
    int productOfDiffs = joltDiffHighestCount * joltLowestDiffCount;
    std::cout << "Multiplied: " << productOfDiffs << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_10::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_10::SetUp_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    //USE LONG LONG!
    std::vector<long long> linesIntList;
    linesIntList.push_back(0); //Test the 0
    for (int i = 0; i < lines.size(); ++i)
    {
        linesIntList.push_back(atoll(lines[i].c_str()));
    }

    std::sort(linesIntList.begin(), linesIntList.end()); //sorts by lesser by default

    linesIntList.push_back(linesIntList.back() + 3 ); // Adaptors build in jolt

    m_SortedJoltsList = linesIntList;

    return EErrorCode::Success;
}

EErrorCode CChallenge_10::Run_SecondPart()
{
    std::cout << "Sample Size: " << m_SortedJoltsList.size() << " [Includes: 0 & " << m_SortedJoltsList.back() << "]" << std::endl;

    long long previousJolt = 0;
    int totalPathsCount = 0;

    std::vector<long long> newTotalPathList;
    newTotalPathList.resize(m_SortedJoltsList.size());
    newTotalPathList.back() = 1;

    for (int joltIdx = m_SortedJoltsList.size() - 2 ; joltIdx >= 0; --joltIdx)
    {
        long long currentJolt = m_SortedJoltsList[joltIdx];

        int nextIdx = joltIdx + 1;
        long long numberOfPaths = 0;
        while (nextIdx < m_SortedJoltsList.size())
        {
            if ((m_SortedJoltsList[nextIdx] - currentJolt) <= 3)
            {
                numberOfPaths += newTotalPathList[nextIdx];
                ++nextIdx;
            }
            else
                break;
        }

        newTotalPathList[joltIdx] = numberOfPaths;
    }

    std::cout << "Total Combination: " << newTotalPathList.front() << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_10::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}
