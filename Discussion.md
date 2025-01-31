Solutions Considered
Read the entire log file into memory:

One approach considered was reading the entire log file into memory, filtering out the entries for the specific date, and then writing the result to an output file. While this approach is simple, it is not efficient for very large files (like the 1 TB log file in the problem), as it would consume a lot of memory and take considerable time.
Streaming through the file line-by-line:

Another approach considered was reading the log file line-by-line and directly writing the matching entries to an output file. This is more memory-efficient as it doesn't require loading the entire file into memory, making it suitable for large files. This approach was ultimately chosen because it minimizes memory usage and can handle large files effectively.
Using Multi-threading for Faster Search:


Memory efficiency: The log file is large (around 1 TB), and reading it in chunks is a memory-efficient approach since we process each line individually.
Simplicity: The approach avoids complex structures like indexing or multi-threading, making it easier to implement and debug.
Performance: It strikes a good balance between memory usage and processing speed, especially given that the log file contains data distributed almost equally across dates.
The program is designed to output the filtered logs into a new directory output/, and the log file (logs_2024.log) is assumed to be in the root of the project directory.

Steps to Run

├── logs_2024.log
├── output/             <-- Output will be saved here
├── src/
│   └── extract_logs.cpp
└── (other files)
Update the Code (if needed): Ensure that your C++ code correctly references the log file in the root directory. The path should be relative to the repository root:
Compile the code
g++ extract_logs.cpp -o extract_logs -lstdc++fs
Run the Program: Now, run the program to extract logs for a specific date (e.g., 2024-12-01). The following command will process the log file:

Run the code using this command
./extract_logs 2024-12-01
Check Output: After running the program, the filtered logs will be saved in the output/ directory:

