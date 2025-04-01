#include <iostream>
#include <string>

#include "CranchyLib.h"

using namespace std;






int main()
{
    SetConsoleTitleA("CranchyLib.CPP DEMO");
    WindowsUtilities::ConsoleUTF8();


    cout << "Welcome to CranchyLib.CPP!" << endl;
    cout << "There's a 5 seconds delay between DEMO steps." << endl;


    cout << endl << endl; Sleep(5000);
    cout << "System Drive:        " << WindowsUtilities::GetSystemDrive()              << endl;
    cout << "Program Files (x86): " << WindowsUtilities::GetProgramFilesX86Directory() << endl;
    cout << "%localappdata%:      " << WindowsUtilities::GetAppDataLocalDirectory()    << endl;
    cout << "System User:         " << WindowsUtilities::GetUserDirectory()            << endl;
    cout << "Documents:           " << WindowsUtilities::GetDocumentsDirectory()       << endl;


    cout << endl << endl; Sleep(5000);
    cout << "Executable Name:      " << WindowsUtilities::GetExecutableName(false) << endl;
    cout << "Executable Directory: " << WindowsUtilities::GetExecutableDirectory() << endl;
    cout << "Executable Path:      " << WindowsUtilities::GetExecutablePath()      << endl;


    cout << endl << endl; Sleep(5000);
    WindowsUtilities::WriteLineConsole("Easy new line print");
    WindowsUtilities::WriteLineConsole("Yet another line to be printed");

    const char* charStrings[] = { "Char Line #1", "Char Line #2" };
    WindowsUtilities::WriteAllLinesConsole(charStrings);

    vector<string> vecStrings = { "Vector Line #1", "Vector Line #2" };
    WindowsUtilities::WriteAllLinesConsole(vecStrings);


    cout << endl << endl; Sleep(5000);
    vector<string> encodingStrings = { "ABCD0123 /=%", "+_-", u8"α" };
    for (const auto& string : encodingStrings)
    {
        WindowsUtilities::WriteLineConsole("String: \"" + string + "\" is ASCII: " + (StringUtilities::String_IsASCII(string) ? "Yes" : "No"));
    }


    cout << endl << endl; Sleep(5000);
    string defaultString = "Hello, World!";
    string reversedString = StringUtilities::String_Reverse(defaultString);
    WindowsUtilities::WriteLineConsole(defaultString + "  <<|>>  " + reversedString);


    cout << endl << endl; Sleep(5000);
    string basicString = "This line been converted from String to WideString";
    wstring wideString = StringUtilities::String_ToWString(basicString);
    wcout << wideString << endl;;

    
    cout << endl << endl; Sleep(5000);
    wstring wideStringV2 = L"You can output WideString with WriteWLineConsole()";
    WindowsUtilities::WriteWLineConsole(wideStringV2);


    cout << endl << endl; Sleep(5000);
    string sourceString = "My friends like rock music.";
    string editedString = StringUtilities::String_ReplaceAll(sourceString, "rock", "80's");
    WindowsUtilities::WriteLineConsole(sourceString + "  -->  " + editedString);


    cout << endl << endl; Sleep(5000);
    WindowsUtilities::WriteLineConsole("Specify any file of your choose: ");
    string userChosenFilePath = WindowsUtilities::FileOpenDialog();
    WindowsUtilities::WriteLineConsole(userChosenFilePath.empty() ? "User didn't choose any file." : userChosenFilePath);


    cout << endl << endl; Sleep(5000);
    WindowsUtilities::WriteLineConsole("Reading through \"Example.txt\" file contents...");
    string fileContents = FileUtilities::ReadFileContents("Example.txt");
    WindowsUtilities::WriteLineConsole(fileContents);


    cout << endl << endl; Sleep(5000);
    WindowsUtilities::WriteLineConsole("Write something down: ");
    string userInput;
    cin >> userInput;
    FileUtilities::WriteFileContents("UserInput.txt", userInput);
    WindowsUtilities::WriteLineConsole("User input been written to \"UserInput.txt\" file.");


    cout << endl << endl; Sleep(5000);
    WindowsUtilities::WriteLineConsole("Reading through \"ExampleLines.txt\" file lines...");
    vector<string> fileLines = FileUtilities::ReadFileLines("ExampleLines.txt");
    int lineIndex = 0;
    for (const string line : fileLines)
    {
        WindowsUtilities::WriteLineConsole("[" + to_string(lineIndex) + "] " + line);
        lineIndex++;
    }


    cout << endl << endl; Sleep(5000);
    WindowsUtilities::WriteLineConsole("That's it! No more DEMO left, nothing to see.");
    system("pause");
}