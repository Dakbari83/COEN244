// DataSharding.cpp
// Simple program for partitioning a CSV-like file into shards (files).
// Each shard contains the header (first line) and up to 'shardSize' samples (lines).

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    string inputPath;
    cout << "Enter input file path (press Enter for default \"RT_IOT2022\"): ";
    getline(cin, inputPath);
    if (inputPath.empty()) inputPath = "RT_IOT2022";

    cout << "Enter shard size (number of samples per shard, positive integer): ";
    string shardSizeStr;
    getline(cin, shardSizeStr);
    int shardSize = 0;
    try {
        shardSize = stoi(shardSizeStr);
    } catch (...) {
        cerr << "Invalid shard size. Must be a positive integer.\n";
        return 1;
    }
    if (shardSize <= 0) {
        cerr << "Shard size must be positive.\n";
        return 1;
    }

    cout << "Enter output directory (press Enter for current directory): ";
    string outDir;
    getline(cin, outDir);
    if (outDir.empty()) outDir = ".";
    // Ensure separator (we use '/' which works on most systems)
    if (outDir.back() != '/' && outDir.back() != '\\') outDir += "/";

    // Open input file
    ifstream infile(inputPath.c_str());
    if (!infile) {
        cerr << "Failed to open input file: " << inputPath << "\n";
        return 1;
    }

    // Read header
    string header;
    if (!getline(infile, header)) {
        cerr << "Input file is empty or header could not be read.\n";
        return 1;
    }

    int sampleCount = 0;
    int shardIndex = 0;
    int writtenInCurrentShard = 0;
    ofstream shardFile;

    string line;
    while (getline(infile, line)) {
        // If starting a new shard, open a new file and write header
        if (writtenInCurrentShard == 0) {
            // Close previous if open (defensive)
            if (shardFile.is_open()) shardFile.close();

            string outName = outDir + "shard_" + to_string(shardIndex) + ".txt";
            shardFile.open(outName.c_str());
            if (!shardFile) {
                cerr << "Failed to create shard file: " << outName << "\n";
                return 1;
            }
            shardFile << header << "\n";
        }

        // Write the sample line into the current shard
        shardFile << line << "\n";

        ++sampleCount;
        ++writtenInCurrentShard;

        // If current shard reached shardSize, close it and prepare for next shard
        if (writtenInCurrentShard >= shardSize) {
            shardFile.close();
            ++shardIndex;
            writtenInCurrentShard = 0;
        }
    }

    // If last shard file is still open, close it
    if (shardFile.is_open()) shardFile.close();

    // Compute number of shards used
    int totalShards = shardIndex + (writtenInCurrentShard > 0 ? 1 : 0);

    cout << "Done.\n";
    cout << "Input file: " << inputPath << "\n";
    cout << "Total samples (lines excluding header): " << sampleCount << "\n";
    cout << "Shard size: " << shardSize << "\n";
    cout << "Total shard files created: " << totalShards << "\n";
    cout << "Shard files are in directory: " << outDir << "\n";
    cout << "(Shard files named shard_0.txt, shard_1.txt, ...)\n";

    infile.close();
    return 0;
}


