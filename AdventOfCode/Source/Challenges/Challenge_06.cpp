#include "Challenge_06.h"
#include "../Helpers/FileHelpers.h"
#include <algorithm>


////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_06::sm_inputFilePath = "Inputs/Input_Challenge_06.txt";
////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_06::SetUp_FirstPart()
{
    CreateSingleLineAnswers();

    return EErrorCode::Success;
}

EErrorCode CChallenge_06::Run_FirstPart()
{
    int yesCount = 0;

    for (const std::string& line : m_SingleLineAnswers)
    {
        std::string currentLine = line;

        std::sort(currentLine.begin(), currentLine.end()); //sorts by lesser by default

        auto uniqueLettersIt = std::unique(currentLine.begin(), currentLine.end());
        currentLine.erase(uniqueLettersIt, currentLine.end());

        yesCount += static_cast<int>(currentLine.size()) - 1;

    }

    std::cout << "Total yes's: " << yesCount << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_06::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_06::SetUp_SecondPart()
{
    CreateSingleLineAnswers();

    return EErrorCode::Success;
}

EErrorCode CChallenge_06::Run_SecondPart()
{
    int yesCount = 0;

    for (const std::string& line : m_SingleLineAnswers)
    {
        std::string uniqueLine = line;

        std::vector<std::string> people;
        FileHelper::SplitLine(uniqueLine, " ", people);
        size_t personCount = people.size();

        std::sort(uniqueLine.begin(), uniqueLine.end()); //sorts by lesser by default
        auto uniqueLettersIt = std::unique(uniqueLine.begin(), uniqueLine.end());
        uniqueLine.erase(uniqueLettersIt, uniqueLine.end());

        for (char letter : uniqueLine)
        {
            if (letter == ' ')
                continue;

            int letterCount = static_cast<int>(std::count(line.begin(), line.end(), letter));
            if (letterCount == personCount)
                ++yesCount;
        }
    }

    std::cout << "Total yes's: " << yesCount << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_06::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}

void CChallenge_06::CreateSingleLineAnswers()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return;
    }

    if (lines.size() > 0)
    {
        m_SingleLineAnswers.push_back("");
        for (size_t lineIdx = 0; lineIdx < lines.size(); ++lineIdx)
        {
            const std::string& currentValue = lines[lineIdx];

            if (currentValue.empty())
            {
                m_SingleLineAnswers.push_back("");
            }
            else
            {
                if (!m_SingleLineAnswers[m_SingleLineAnswers.size() - 1].empty())
                    m_SingleLineAnswers[m_SingleLineAnswers.size() - 1] += " ";

                m_SingleLineAnswers[m_SingleLineAnswers.size() - 1] += currentValue;
            }
        }
    }
}
