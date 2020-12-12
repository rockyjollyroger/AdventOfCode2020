#include "Challenge_12.h"
#include "../Helpers/FileHelpers.h"



////////////////////////////////////////////////////////////////////////////////////////////////////
std::string const CChallenge_12::sm_inputFilePath = "Inputs/Input_Challenge_12.txt";



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_12::SetUp_FirstPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_12::Run_FirstPart()
{
    // X- axis : West/East
    // Y- axis : North/South
    // Turning : Is always divisible by 90

    int curr_X = 0;
    int curr_Y = 0;
    int curr_dir_idx = 1; // Start at E
    std::vector<char> curr_dir;
    curr_dir.resize(4);
    curr_dir[0] = 'N';
    curr_dir[1] = 'E';
    curr_dir[2] = 'S';
    curr_dir[3] = 'W';

    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    for (int idx = 0; idx < lines.size(); ++idx)
    {
        const std::string& currentLine = lines[idx];
        const char instruction = currentLine.substr(0, 1)[0];
        int value = atoi(currentLine.substr(1).c_str());

        //
        switch (instruction)
        {
            case 'N':
                curr_Y += value;
                break;
            case 'S':
                curr_Y -= value;
                break;
            case 'E':
                curr_X += value;
                break;
            case 'W':
                curr_X -= value;
                break;
            case 'L': //ccw
            {
                int rotations = value / 90;
                curr_dir_idx -= rotations;
                curr_dir_idx = curr_dir_idx % curr_dir.size();
            }
                break;
            case 'R': //cw
            {
                int rotations = value / 90;
                curr_dir_idx += rotations;
                curr_dir_idx = curr_dir_idx % curr_dir.size();
            }
                break;
            case 'F':
            {
                switch (curr_dir[curr_dir_idx])
                {
                case 'N':
                    curr_Y += value;
                    break;
                case 'S':
                    curr_Y -= value;
                    break;
                case 'E':
                    curr_X += value;
                    break;
                case 'W':
                    curr_X -= value;
                    break;
                }
            }
                break;
        }
    }

    // Output:
    std::cout << "X: " << abs(curr_X) << " Y: " << abs(curr_Y) << std::endl;
    std::cout << "Manhattan Distance: " << abs(curr_X) + abs(curr_Y) << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_12::CleanUp_FirstPart()
{
    return EErrorCode::Success;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
EErrorCode CChallenge_12::SetUp_SecondPart()
{
    return EErrorCode::Success;
}

EErrorCode CChallenge_12::Run_SecondPart()
{
    std::vector<std::string> lines;
    EErrorCode const readErrorCode = FileHelper::ReadLines(sm_inputFilePath, lines);
    if (readErrorCode != EErrorCode::Success)
    {
        return readErrorCode;
    }

    int curr_X = 0;
    int curr_Y = 0;

    std::vector<int> waypoint;
    waypoint.resize(2);
    waypoint[0] = 10; // 10 units east
    waypoint[1] = 1; // 1 unit north

    for (int idx = 0; idx < lines.size(); ++idx)
    {
        const std::string& currentLine = lines[idx];
        const char instruction = currentLine.substr(0, 1)[0];
        int value = atoi(currentLine.substr(1).c_str());

        switch (instruction)
        {
        case 'N':
        {
            waypoint[1] += value;
        }
            break;
        case 'S':
        {
            waypoint[1] -= value;
        }
            break;
        case 'E':
        {
            waypoint[0] += value;
        }
            break;
        case 'W':
        {
            waypoint[0] -= value;
        }
            break;
        case 'L': //ccw
        {
            if (value == 90)
            {
                int temp_x = waypoint[0];
                int temp_y = waypoint[1];

                waypoint[0] = -1 * temp_y;
                waypoint[1] = temp_x;
            }
            else if (value == 180)
            {
                waypoint[0] *= -1; // x = -x
                waypoint[1] *= -1; // y = -y
            }
            else if (value == 270)
            {
                int temp_x = waypoint[0];
                int temp_y = waypoint[1];

                waypoint[0] = temp_y;
                waypoint[1] = -1 * temp_x;
            }
        }
        break;
        case 'R': //cw
        {
            if (value == 90)
            {
                int temp_x = waypoint[0];
                int temp_y = waypoint[1];

                waypoint[0] = temp_y;
                waypoint[1] = -1 * temp_x;
            }
            else if (value == 180)
            {
                waypoint[0] *= -1; // x = -x
                waypoint[1] *= -1; // y = -y
            }
            else if (value == 270)
            {
                int temp_x = waypoint[0];
                int temp_y = waypoint[1];

                waypoint[0] = -1 * temp_y;
                waypoint[1] = temp_x;
            }
        }
        break;
        case 'F':
        {
            curr_X += value * waypoint[0];
            curr_Y += value * waypoint[1];
        }
        break;
        }
    }

    // Output:
    std::cout << "X: " << abs(curr_X) << " Y: " << abs(curr_Y) << std::endl;
    std::cout << "Manhattan Distance: " << abs(curr_X) + abs(curr_Y) << std::endl;

    return EErrorCode::Success;
}

EErrorCode CChallenge_12::CleanUp_SecondPart()
{
    return EErrorCode::Success;
}
