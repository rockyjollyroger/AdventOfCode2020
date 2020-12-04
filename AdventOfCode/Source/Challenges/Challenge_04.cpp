#include "Challenge_04.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_04::sm_inputFilePath = "Inputs/Input_Challenge_04.txt";



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_04::SetUp_FirstPart()
{
    InitiChallenge04();
    return EErrorCode::Success;
}

EErrorCode CChallenge_04::Run_FirstPart()
{
    // Max number of fields
    const int totalNumOfFields = 8;

    // Count valid passports
    size_t validPassportsCount = 0;

    size_t validFieldCount = 0;
    bool hasCIDField = false;

    // Field values
    std::string byr = "byr";
    std::string fyr = "fyr";
    std::string eyr = "eyr";
    std::string hcl = "hcl";
    std::string ecl = "ecl";
    std::string pid = "pid";
    std::string cid = "cid";

    // Loop
    for (size_t lineIdx = 0; lineIdx < m_InputElementsSize; ++lineIdx)
    {
        // Store the current string
        const std::string& currentValue = m_InputElements[lineIdx];

        // Check if line is empty - Identify New Passport
        bool isEOF = lineIdx == (m_InputElementsSize - 1);
        if (currentValue.empty())
        {
            // Check if missing value is CID
            if (validFieldCount == 7)
            {
                if(!hasCIDField)
                    ++validPassportsCount;
            }

            if(validFieldCount == totalNumOfFields)
            {
                ++validPassportsCount;
            }

            //reset variables:
            validFieldCount = 0;
            hasCIDField = false;

            continue;
        }

        std::vector<std::string> spiltingLines;
        FileHelper::SplitLine(currentValue, " ", spiltingLines);

        for (size_t splitLineIdx = 0; splitLineIdx < spiltingLines.size(); ++splitLineIdx) //eg. hcl:#b5c3db | ecl:grn | hgt:155cm | pid:#baec97 | iyr:2017
        {
            // Check the field ID
            const size_t seperatorColon = spiltingLines[splitLineIdx].find(':');
            const std::string fieldID = spiltingLines[splitLineIdx].substr(0, seperatorColon);

            if (cid.compare(fieldID) == 0)
            {
                hasCIDField = true;
            }

            ++validFieldCount;
        }

        if (isEOF)
        {
            // Check if missing value is CID
            if ( validFieldCount == 7)
            {
                if (!hasCIDField)
                    ++validPassportsCount;
            }

            if (validFieldCount == totalNumOfFields)
            {
                ++validPassportsCount;
            }
        }
    }

    std::cout << "Number of valid passports: " << validPassportsCount << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_04::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_04::SetUp_SecondPart()
{
    CreateSingleLinePassports();

    return EErrorCode::Success;
}

EErrorCode CChallenge_04::Run_SecondPart()
{
    // Count valid passports
    size_t validPassportsCount = 0;

    // Max number of fields
    const int totalNumOfFields = 7;

    // Variables
    size_t validFieldCount = 0;
    bool hasCIDField = false;

    // Field values
    std::string byr = "byr";
    std::string iyr = "iyr";
    std::string eyr = "eyr";
    std::string hgt = "hgt";
    std::string hcl = "hcl";
    std::string ecl = "ecl";
    std::string pid = "pid";
    std::string cid = "cid"; // ignore

    // Loop
    for (size_t lineIdx = 0; lineIdx < m_InputElementsSize; ++lineIdx)
    {
        //Reset
        validFieldCount = 0;

        // Store the current string
        const std::string& currentValue = m_InputElements[lineIdx];

        std::vector<std::string> spiltingLines;
        FileHelper::SplitLine(currentValue, " ", spiltingLines);

        for (std::string const& field : spiltingLines)
        {
            const size_t seperatorColon = field.find(':');
            const std::string fieldID = field.substr(0, seperatorColon);

            if (byr.compare(fieldID) == 0)
            {
                //four digits; at least 1920 and at most 2002
                const int fieldValue = atoi(field.substr(seperatorColon + 1).c_str());
                if (fieldValue >= 1920 && fieldValue <= 2002)
                {
                    ++validFieldCount;
                }
            }
            else if (iyr.compare(fieldID) == 0)
            {
                //four digits; at least 2010 and at most 2020
                const int fieldValue = atoi(field.substr(seperatorColon + 1).c_str());
                if (fieldValue >= 2010 && fieldValue <= 2020)
                {
                    ++validFieldCount;
                }
            }
            else if (eyr.compare(fieldID) == 0)
            {
                //four digits; at least 2020 and at most 2030
                const int fieldValue = atoi(field.substr(seperatorColon + 1).c_str());
                if (fieldValue >= 2020 && fieldValue <= 2030)
                {
                    ++validFieldCount;
                }
            }
            else if (hgt.compare(fieldID) == 0)
            {
                //If cm, the number must be at least 150 and at most 193
                //If in, the number must be at least 59 and at most 76
                const std::string fieldStringValue = field.substr(seperatorColon + 1);

                if (fieldStringValue[fieldStringValue.size() - 2] == 'c' && fieldStringValue[fieldStringValue.size() - 1] == 'm') //cm
                {
                    const int fieldValue = atoi(fieldStringValue.substr(0, fieldStringValue.size() - 2).c_str());
                    if (fieldValue >= 150 && fieldValue <= 193)
                    {
                        ++validFieldCount;
                    }
                }
                else if (fieldStringValue[fieldStringValue.size() - 2] == 'i' && fieldStringValue[fieldStringValue.size() - 1] == 'n') //in
                {
                    const int fieldValue = atoi(fieldStringValue.substr(0, fieldStringValue.size() - 2).c_str());
                    if (fieldValue >= 59 && fieldValue <= 76)
                    {
                        ++validFieldCount;
                    }
                }
            }
            else if (hcl.compare(fieldID) == 0)
            {
                //a # followed by exactly six characters 0-9 or a-f.
                const std::string fieldValue = field.substr(seperatorColon + 1);
                
                if (fieldValue.size() == 7 && fieldValue[0] == '#')
                {
                    int validChars = 1;
                    for (size_t i = 1; i < fieldValue.size(); ++i)
                    {
                        const char charValue = fieldValue[i];
                        if (charValue >= '0' && charValue <= '9')
                        {
                            ++validChars;
                        }
                        else if (charValue >= 'a' && charValue <= 'f')
                        {
                            ++validChars;
                        }
                    }

                    if (validChars == fieldValue.size())
                    {
                        ++validFieldCount;
                    }
                }
            }
            else if (ecl.compare(fieldID) == 0)
            {
                //exactly one of: amb blu brn gry grn hzl oth
                const std::string fieldValue = field.substr(seperatorColon + 1);
                if (fieldValue.compare("amb") == 0
                    || fieldValue.compare("blu") == 0
                    || fieldValue.compare("brn") == 0
                    || fieldValue.compare("gry") == 0
                    || fieldValue.compare("grn") == 0
                    || fieldValue.compare("hzl") == 0
                    || fieldValue.compare("oth") == 0
                    )
                {
                    ++validFieldCount;
                }
            }
            else if (pid.compare(fieldID) == 0)
            {
                //a nine-digit number, including leading zeroes
                const std::string fieldValue = field.substr(seperatorColon + 1);

                if (fieldValue.size() == 9)
                {
                    int validCharCount = 0;
                    for (const char valueChar : fieldValue)
                    {
                        if (valueChar >= '0' && valueChar <= '9')
                            ++validCharCount;
                    }

                    if (validCharCount == 9)
                    {
                        ++validFieldCount;
                    }
                }
            }
        }
    
        // Check if missing value is CID
        if (validFieldCount == totalNumOfFields)
        {
             ++validPassportsCount;
        }
    }

    std::cout << "Number of valid passports: " << validPassportsCount << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_04::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}

//----------------------------------------------------------------------------------------------------

EErrorCode CChallenge_04::InitiChallenge04()
{
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, m_InputElements);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    m_InputElementsSize = m_InputElements.size();

    return EErrorCode::Success;
}

//----------------------------------------------------------------------------------------------------

void CChallenge_04::CreateSingleLinePassports()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return;
    }

    if (lines.size() > 0)
    {
        m_InputElements.push_back("");
        for (size_t lineIdx = 0; lineIdx < lines.size(); ++lineIdx)
        {
            const std::string& currentValue = lines[lineIdx];

            if (currentValue.empty())
            {
                m_InputElements.push_back("");
            }
            else
            {
                if (!m_InputElements[m_InputElements.size() - 1].empty())
                    m_InputElements[m_InputElements.size() - 1] += " ";

                m_InputElements[m_InputElements.size() - 1] += currentValue;
            }
        }
    }

    m_InputElementsSize = m_InputElements.size();
}
