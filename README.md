# Keylogger Documentation

## Overview
This document describes a Windows-based keylogger implemented in C++ that captures keyboard input and logs it to a file. The keylogger hides its console window, logs both regular and special keys, and includes timestamps for better tracking.

## Features
- Captures all printable ASCII characters and special keys (e.g., Space, Enter, Shift, arrow keys).
- Logs keypresses to a file (`keylog.txt`) with timestamps.
- Handles shift key combinations for common symbols (e.g., `!`, `@`, `#`).
- Hides the console window to run discreetly.
- Prevents multiple logs of held keys.
- Efficient file handling with persistent file stream and flush.

## Requirements
- Windows operating system (uses Windows.h API).
- C++ compiler supporting C++11 or later.
- Write permissions for creating `keylog.txt` in the executable's directory.

## Usage
1. Compile the C++ source code (`keylogger.cpp`) using a compatible compiler (e.g., MSVC, MinGW).
2. Run the executable. The console window will be hidden automatically.
3. The keylogger will create/append to `keylog.txt` in the same directory.
4. Press keys to log them. Special keys (e.g., Enter, Shift) are logged with descriptive tags (e.g., `[ENTER]`, `[SHIFT]`).
5. Terminate the program (e.g., via Task Manager) to stop logging. The log file will include a stop timestamp.

## Code Structure
The keylogger is implemented as a `KeyLogger` class with the following key components:
- **initialize()**: Hides the console and initializes the log file with a start timestamp.
- **handleSpecialKeys(int key)**: Processes special keys (e.g., Space, Enter, arrow keys) and logs them with descriptive tags.
- **logKey(int key)**: Logs printable characters and handles shift key combinations.
- **cleanup()**: Closes the log file with a stop timestamp.
- **Main loop**: Continuously checks for keypresses using `GetAsyncKeyState` and logs them.

## Log File Format
The log file (`keylog.txt`) includes:
- A start timestamp when the keylogger begins.
- Keypresses with timestamps in the format: `[Tue Jul 08 12:26:00 2025] <key>`.
- Special keys in square brackets (e.g., `[ENTER]`, `[SHIFT]`, `[UP]`).
- A stop timestamp when the keylogger terminates.

Example log file content:
```
=== Keylogger Started: Tue Jul 08 12:26:00 2025 ===
[Tue Jul 08 12:26:01 2025] h
[Tue Jul 08 12:26:01 2025] e
[Tue Jul 08 12:26:01 2025] l
[Tue Jul 08 12:26:02 2025] [SPACE]
[Tue Jul 08 12:26:03 2025] [SHIFT]
[Tue Jul 08 12:26:03 2025] !
=== Keylogger Stopped: Tue Jul 08 12:26:04 2025 ===
```

## Improvements Over Original
- Organized into a `KeyLogger` class for better structure.
- Fixed typos (e.g., `CAPS_LCOK` to `CAPS_LOCK`).
- Corrected period key detection (replaced `'¾'` with `VK_OEM_PERIOD`).
- Added timestamp logging for each keypress.
- Improved file handling by keeping the file stream open and using `flush`.
- Added shift key handling for common symbols (e.g., `!`, `@`).
- Added key release detection to prevent duplicate logs for held keys.
- Added cleanup for proper file closure.
- Included error checking for file operations.
- Added left mouse button detection.

## Limitations
- Windows-only due to reliance on `Windows.h` and `GetAsyncKeyState`.
- Logs only basic shift key combinations; full keyboard layout support (e.g., international keyboards) is not implemented.
- Requires manual termination (e.g., via Task Manager).
- No encryption or obfuscation of the log file.

## Ethical Considerations
- **Use responsibly**: Keyloggers can be used for malicious purposes. Ensure you have explicit permission to monitor input on any system.
- **Privacy**: Inform users if their input is being logged.
- **Legal compliance**: Verify that keylogging complies with local laws and regulations.

## Future Improvements
- Add support for international keyboard layouts.
- Implement log file encryption.
- Add a proper exit mechanism (e.g., specific key combination).
- Support logging to a remote server or database.
- Enhance shift key handling for more symbols and key combinations.