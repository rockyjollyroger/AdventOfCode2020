#include "Challenge_08.h"
#include "../Helpers/FileHelpers.h"
#include <algorithm>



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_08::sm_inputFilePath = "Inputs/Input_Challenge_08.txt";

////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_08::SetUp_FirstPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_08::Run_FirstPart()
{
    // Keep a list of index that have already ran
        //If we reach an index that has already ran -
            //Find the Accumulator before that repeated instruction

    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);

    int accumulatorValue = 0;
    size_t operationIdx = 0;
    std::string operation = "";
    std::string operatorString = "";
    std::vector<int> operationIdxList;
    std::vector<int>::iterator it;

    while (operationIdx < lines.size())
    {
        //Check operation idx is not the same
        if (operationIdxList.size() != 0)
        {
            it = std::find(operationIdxList.begin(), operationIdxList.end(), operationIdx);
            if (it != operationIdxList.end())
            {
                //The loop was found - return the last acc
                break;
            }
        }

        operationIdxList.push_back(operationIdx);

        //Split the string in operation, operators (+/-) and argument
        const std::string& currentLine = lines[operationIdx];

        //operation
        const size_t seperatorSpace = currentLine.find(' ');
        operation = currentLine.substr(0, seperatorSpace);

        //operator (+/-)
        operatorString = currentLine.substr(seperatorSpace, seperatorSpace - 1);

        // argument
        const int argValue = atoi(currentLine.substr(seperatorSpace + 2).c_str());

        if (operation.compare("acc") == 0)
        {
            if (operatorString.compare(" +") == 0)
                accumulatorValue += argValue;
            else if (operatorString.compare(" -") == 0)
                accumulatorValue -= argValue;

            ++operationIdx;
        }
        else if (operation.compare("jmp") == 0)
        {
            if (operatorString.compare(" +") == 0)
                operationIdx = operationIdx + argValue;
            else if (operatorString.compare(" -") == 0)
                operationIdx = operationIdx - argValue;
        }
        else if (operation.compare("nop") == 0)
        {
            ++operationIdx;
        }
    }

    std::cout << "Accumator: " << accumulatorValue << std::endl;
    std::cout << "Idx before the loop: " << operationIdx - 1 << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_08::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_08::SetUp_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);

    int accumulatorValue = 0;
    size_t operationIdx = 0;
    std::string operation = "";
    std::string operatorString = "";
    std::vector<size_t> operationIdxList;
    std::vector<size_t>::iterator it;

    bool swappedOperation = false;
    size_t orginalOperationIdx = 0;
    int originalAccumulatorValue = 0;
    bool alreadySwappedOpperator = false;
    size_t operationIdxListSize = 0;

    size_t totalLoops = 0;

    while (operationIdx < lines.size())
    {
        //Check operation idx is not the same
        if (operationIdxList.size() != 0)
        {
            it = std::find(operationIdxList.begin(), operationIdxList.end(), operationIdx);
            if (it != operationIdxList.end())
            {
                //The loop was found - return the last acc

                //reset all the variables
                alreadySwappedOpperator = true;
                swappedOperation = false;

                accumulatorValue = originalAccumulatorValue;
                operationIdx = orginalOperationIdx;

                operationIdxList.erase(operationIdxList.begin() + operationIdxListSize, operationIdxList.end() - 1);
                operationIdxListSize = 0;

                ++totalLoops;
            }
        }

        operationIdxList.push_back(operationIdx);

        //Split the string in operation, operators (+/-) and argument
        const std::string& currentLine = lines[operationIdx];

        //operation
        const size_t seperatorSpace = currentLine.find(' ');
        operation = currentLine.substr(0, seperatorSpace);
        std::string newLine = currentLine;
        if (!swappedOperation)
        {
            if (alreadySwappedOpperator)
            {
                //skip
                alreadySwappedOpperator = false;
            }
            else if (operation.compare("jmp") == 0)
            {
                //change to nop
                operation = "nop";
                swappedOperation = true;
                originalAccumulatorValue = accumulatorValue;
                orginalOperationIdx = operationIdx;
                operationIdxListSize = operationIdxList.size() - 1;
            }
            else if (operation.compare("nop") == 0)
            {
                //change to jmp
                operation = "jmp";
                swappedOperation = true;
                originalAccumulatorValue = accumulatorValue;
                orginalOperationIdx = operationIdx;
                operationIdxListSize = operationIdxList.size() - 1;
            }
        }

        //operator (+/-)
        operatorString = currentLine.substr(seperatorSpace, seperatorSpace - 1);

        // argument
        const int argValue = atoi(currentLine.substr(seperatorSpace + 2).c_str());

        if (operation.compare("acc") == 0)
        {
            if (operatorString.compare(" +") == 0)
                accumulatorValue += argValue;
            else if (operatorString.compare(" -") == 0)
                accumulatorValue -= argValue;

            ++operationIdx;
        }
        else if (operation.compare("jmp") == 0)
        {
            if (operatorString.compare(" +") == 0)
                operationIdx = operationIdx + argValue;
            else if (operatorString.compare(" -") == 0)
                operationIdx = operationIdx - argValue;
        }
        else if (operation.compare("nop") == 0)
        {
            ++operationIdx;
        }
    }

    std::cout << "Accumulator: " << accumulatorValue << std::endl;
    std::cout << "Total Loops: " << totalLoops << std::endl;

    return EErrorCode::Success;

}

EErrorCode CChallenge_08::Run_SecondPart()
{
    return EErrorCode::NotImplemented;
}

EErrorCode CChallenge_08::CleanUp_SecondPart()
{
    return EErrorCode::NotImplemented;
}
