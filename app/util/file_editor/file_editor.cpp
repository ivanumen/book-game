#include "file_editor.h"

#include <fstream>

std::string NFileEditor::ReadFile(const std::string& fileName) {
    std::ifstream inFile(fileName);
    std::string result, s;
    while (getline(inFile, s)) {
        result += s;
    }
    return result;
}
