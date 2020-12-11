#include "Challenge_10.h"
#include "../Helpers/FileHelpers.h"
#include <algorithm> 

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
    for (size_t i = 0; i < lines.size(); ++i)
    {
        linesIntList.push_back(atoi(lines[i].c_str()));
    }

    std::sort(linesIntList.begin(), linesIntList.end()); //sorts by lesser by default
    m_SortedJoltsList = linesIntList;

    return EErrorCode::Success;
}

EErrorCode CChallenge_10::Run_FirstPart()
{
    int joltLowestDiffCount = 1; //The 0 Jolt counts
    int joltDiffHighestCount = 1; // to take into account the built in adapter

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
    for (size_t i = 0; i < lines.size(); ++i)
    {
        linesIntList.push_back(atoi(lines[i].c_str()));
    }

    std::sort(linesIntList.begin(), linesIntList.end()); //sorts by lesser by default
    m_SortedJoltsList = linesIntList;

    return EErrorCode::Success;
}

EErrorCode CChallenge_10::Run_SecondPart()
{
    std::cout << "Total Combination: " << FindAdaptorCombinations() /*+ 2 */<< std::endl;

    //
//     long long cobinationCount = 0;
// 
//     int currentIdx = 0;
//     int nextIdx = 1;
//     long long currentJolt = 0;
//     while (currentIdx < m_SortedJoltsList.size())
//     {
//         if (currentJolt == 0)
//         {
//             currentJolt = m_SortedJoltsList[currentIdx];
//             continue;
//         }
// 
//         if (nextIdx < m_SortedJoltsList.size())
//         {
//             long long joltDiff = m_SortedJoltsList[nextIdx] - currentJolt;
//             if (joltDiff == 1 || joltDiff == 3)
//             {
//                 //TODO: we need to take of the end 0 and build-in adpater jolt
// 
//                 ++cobinationCount;
//                 ++currentIdx;
//                 nextIdx = currentIdx + 1;
// 
//                 if (currentIdx >= m_SortedJoltsList.size())
//                     break;
// 
//                 currentJolt = m_SortedJoltsList[currentIdx];
//             }
//             else
//             {
//                 ++nextIdx;
//             }
//         }
//         else
//         {
//             ++currentIdx;
//             nextIdx = currentIdx + 1;
// 
//             if (currentIdx >= m_SortedJoltsList.size())
//                 break;
// 
//             currentJolt = m_SortedJoltsList[currentIdx];
//         }
//     }
// 
//     std::cout << "Total combos: " << cobinationCount << std::endl;
    return EErrorCode::Success;
}

EErrorCode CChallenge_10::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}

//----------------------------------------------------------------------------------------------------
long long CChallenge_10::FindAdaptorCombinations(int _index /*= 0*/, long long _combSum /*= 0*/) const
{
    std::cout << "NEW CALL" << _index << std::endl;
    if (_index == m_SortedJoltsList.size() - 1) // -1 ?
    {
       if (_combSum != 0)
       {
            return _combSum;
       }
        else
        {
            return 0;
        }
    }
    else
    {
        for (int i = _index; i < m_SortedJoltsList.size(); ++i)
        {
            if (i == m_SortedJoltsList.size() - 1)
            {
                return 0; //
            }

            int currentValue = m_SortedJoltsList[i];
            int nextValue = m_SortedJoltsList[i+1];

            int diff = nextValue - currentValue;

            if (diff <= 3)
                ++_combSum;

            if (diff > 3)
                std::cout << "There is a diff > 3 @" << _index << std::endl;

            std::cout << "Index: " << _index << " SUM: " << _combSum << std::endl;
            long long result = FindAdaptorCombinations(_index + 1, _combSum);
            if (result == 0)
                return result;
        }
    }
    return 0;
}