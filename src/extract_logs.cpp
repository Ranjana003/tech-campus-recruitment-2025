#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;


const std::string LOG_FILE = "logs_2024.log"; // Fixed log file name as per problem statement
const std::string OUTPUT_DIR = "../output";

void extractLogs(const std::string& targetDate) {
    // Ensure the output directory exists
    if (!fs::exists(OUTPUT_DIR)) {
        fs::create_directories(OUTPUT_DIR);
    }

    // Define output file path
    std::string outputFile = OUTPUT_DIR + "/output_" + targetDate + ".txt";

    // Open log file for reading
    std::ifstream logFile(LOG_FILE);
    if (!logFile) {
        std::cerr << "Error: Unable to open log file: " << LOG_FILE << std::endl;
        return;
    }

    // Open output file for writing
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error: Unable to create output file: " << outputFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(logFile, line)) {
        // Check if the line starts with the target date
        if (line.rfind(targetDate, 0) == 0) { // rfind with position 0 ensures efficient prefix matching
            outFile << line << "\n";
        }
    }

    // Close files
    logFile.close();
    outFile.close();

    std::cout << "Logs for " << targetDate << " saved in " << outputFile << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) { // Accept only the date argument
        std::cerr << "Usage: " << argv[0] << " <YYYY-MM-DD>" << std::endl;
        return 1;
    }

    std::string dateToExtract = argv[1];
    extractLogs(dateToExtract);

    return 0;
}
