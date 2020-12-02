#include "Challenge_01.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_01::sm_inputFilePath = "Inputs/Input_Challenge_01.txt";

////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_01::SetUp_FirstPart()
{
    return InitiChallenge01();
}

EErrorCode CChallenge_01::Run_FirstPart()
{
    std::cout << "(PART 1) Product of the Sum: " << FindProductOfSumEntries(2) << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_01::CleanUp_FirstPart()
{
    delete[] m_InputElements;

    return EErrorCode::Success;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_01::SetUp_SecondPart()
{
    return InitiChallenge01();
}

EErrorCode CChallenge_01::Run_SecondPart()
{
    std::cout << "(PART 2) Product of the Sum: " << FindProductOfSumEntries(3) << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_01::CleanUp_SecondPart()
{
    delete[] m_InputElements;
    return EErrorCode::Success;
}

//----------------------------------------------------------------------------------------------------

EErrorCode CChallenge_01::InitiChallenge01()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    m_InputElementsSize = lines.size();
    m_InputElements = new int[lines.size()];

    for (size_t lineIdx = 0; lineIdx < lines.size(); ++lineIdx)
    {
        m_InputElements[lineIdx] = atoi(lines[lineIdx].c_str());
    }

    return EErrorCode::Success;
}

//----------------------------------------------------------------------------------------------------

int CChallenge_01::FindProductOfSumEntries(int _count, int _index /*= 0*/, int _sumValue /*= 0*/, int _productValue /*= 1*/) const
{
    //Base
    if (_count == 0)
    {
        //check sum
        if (_sumValue == 2020)
            return _productValue;
        else
            return 0;
    }
    else
    {
        for (int i = _index; i < m_InputElementsSize; ++i)
        {
            int currentValue = m_InputElements[i];
            int currentSum = _sumValue + currentValue;
            int currentProduct = _productValue * currentValue;

            int result = FindProductOfSumEntries(_count - 1, _index + 1, currentSum, currentProduct);
            if (result != 0)
                return result;
        }
    }


    return 0;
}
