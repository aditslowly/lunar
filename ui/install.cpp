#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ios>
#include <iostream>
#include "install.hpp"
#include <string>

using namespace std;

void writeLog(const string& message) {
  ofstream logFile("log/install.log", ios::app);
  if (logFile.is_open()) {
    time_t now = time(nullptr);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    logFile << "[" << timestamp << "]" << message << endl;
    logFile.close();
  }
  else {
    cerr << "Failed to open log file!" << endl;
  }
}


void downloadFile(const std::string& url, const std::string& output) {
    std::string command = "curl -L -o " + output + " " + url;
    system(command.c_str());
}

void installProgram(const std::string& installerPath) {
    std::string command = "\"" + installerPath + "\" /SILENT";
    system(command.c_str());
}

void installLaragon() {
  cout << "Installing Laragon...\n";
  downloadFile("https://laragon.org/download/Laragon.exe", "Laragon.exe");
  installProgram("Laragon.exe");
  cout << "Laragon installation complete!\n";
}

void installNodeJS() {
  cout << "Installing NodeJS...\n";
  system("winget install --id OpenJS.NodeJS -e --source winget");
  cout << "NodeJS installation complete!\n";
}

void installVisualStudioCode() {
  cout << "Installing Visual Studio Code...\n";
  system("winget install --id Microsoft.VisualStudioCode -e --source winget");
  cout << "Visual Studio Code instalation complete!\n";
}

void installPython() {
  cout << "Installing Python...\n";
  system("winget install --id Python.Python.3.12 -e --source winget");
  cout << "Python installation complete!\n";
}

void installAll() {
  cout << "Installing all programs!\n";
  installLaragon();
  installNodeJS();
  installVisualStudioCode();
  installPython();
  cout << "All installation complete!\n";
}
