#include "Challenge_05.h"
#include "../Helpers/FileHelpers.h"
#include <algorithm>



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_05::sm_inputFilePath = "Inputs/Input_Challenge_05.txt";
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

EErrorCode CChallenge_05::SetUp_FirstPart()
{
    // Split the list into 2 parts?
    // We need parse through the first 7 characters
    // We need to parse the last tree

    // Set up a binary tree for the first list
    // Set up a binary tree for the  second list

    // find the Uniquid ID - Row Value * 8 + Coloum

    // Final answer will be what was the highest Unique ID

    return EErrorCode::Success;
}

EErrorCode CChallenge_05::Run_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    // Vector of IDs
    std::vector<int> seatIDs;

    for (const std::string& line : lines)
    {
        //eg. FBFBBFFRLR

        // Iterate the string
        int numberOfRows = 128;
        int lowestBoundRow = 0;

        int numberOfColums = 8;
        int lowestBoundCol = 0;

        for (const char charValue : line)
        {
            if (charValue == 'F') // take lower half
            {
                numberOfRows /= 2;
            }
            else if (charValue == 'B') // take upper half
            {
                numberOfRows /= 2;
                lowestBoundRow += numberOfRows;
            }
            else if (charValue == 'L') // take the lower half
            {
                numberOfColums /= 2;
            }
            else if (charValue == 'R') // take the upper half
            {
                numberOfColums /= 2;
                lowestBoundCol += numberOfColums;
            }
        }

        //Do the math:
        seatIDs.push_back(lowestBoundRow * 8 + lowestBoundCol);
    }//final condition if numberOfRows & numberOfCol is 1.

    std::vector<int>::iterator  highestSeatIDs;
    // Find the max ID
    highestSeatIDs = std::max_element(seatIDs.begin(), seatIDs.end());

    if (highestSeatIDs != seatIDs.end())
    {
        const int highestSeatID = *highestSeatIDs; // dereference
        std::cout << "Max seat ID: " << highestSeatID << std::endl;
    }


    return EErrorCode::Success;
}

EErrorCode CChallenge_05::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_05::SetUp_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }
    
    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_05::Run_SecondPart()
{
    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_05::CleanUp_SecondPart()
{
    return EErrorCode::NotImplemented;
}
