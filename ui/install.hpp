#ifndef INSTALL_HPP
#define INSTALL_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

// Fungsi logging
void writeLog(const std::string& message);

// Fungsi instalasi
void installLaragon();
void installNodeJS();
void installVisualStudioCode();
void installPython();
void installAll();

#endif // INSTALL_HPP
