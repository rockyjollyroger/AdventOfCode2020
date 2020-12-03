#include "Challenge_03.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_03::sm_inputFilePath = "Inputs/Input_Challenge_03.txt";
////////////////////////////////////////////////////////////////////////////////////////////////////

EErrorCode CChallenge_03::SetUp_FirstPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_03::Run_FirstPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    // Identify Tree
    char tree = '#';

    // Identify step right
    size_t stepRight = 3;

    // Identify step down
    size_t stepDown = 1;

    NumberOfHit(lines, tree, stepRight, stepDown);


    return EErrorCode::Success;
}

EErrorCode CChallenge_03::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_03::SetUp_SecondPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_03::Run_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    size_t productOfTreesHit = 1;

    productOfTreesHit *= NumberOfHit(lines, '#', 1, 1);
    productOfTreesHit *= NumberOfHit(lines, '#', 3, 1);
    productOfTreesHit *= NumberOfHit(lines, '#', 5, 1);
    productOfTreesHit *= NumberOfHit(lines, '#', 7, 1);
    productOfTreesHit *= NumberOfHit(lines, '#', 1, 2);

    std::cout << "Total Product of # hit: " << productOfTreesHit << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_03::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}

//----------------------------------------------------------------------------------------------------

size_t CChallenge_03::NumberOfHit(std::vector<std::string> &lines, char tree, size_t stepRight, size_t stepDown) const
{
    // Tree Counter
    int treeCounter = 0;

    size_t x = 0;
    size_t y = 0;

    while (y < lines.size())
    {
        // Set the next line
        std::string& currentLine = lines[y];
        //Check for tree
        if (currentLine[x % currentLine.size()] == tree)
        {
            treeCounter++;
        }

        //Set the next x, y
        x += stepRight;
        y += stepDown;
    }

    std::cout << "Total # hit: " << treeCounter << std::endl;

    return treeCounter;
}
