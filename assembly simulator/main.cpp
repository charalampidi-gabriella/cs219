
#include "functions.h"

////////////////////////////////Read file///////////////////////////////
void readFile(std::string inputFile)
{
    ifstream file(inputFile);
    if (file.is_open())
    {
        string line;
        string register_values[8] = {"0x0", "0x0", "0x0", "0x0", "0x0", "0x0", "0x0", "0x0"}; // all possible first digits of given numbers in file

        // iterating over each line
        while (getline(file, line))
        {

            string word;                    // each word in a line (operation and operators)
            istringstream wordstream(line); // pass them all in a stringstream

            uint32_t operands[2]; // array to hold the 2 operands
            string op;            // string that holds the operator
            int shifts;           // int that will hold number of shifts if needed
            string registers[3];  // array that will hold the registers appearing in instructions

            int i = 0;                                                            // index for array of operands
            int j = 0;                                                            // index for array of registers
            char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // all possible first digits of given numbers in file

            cout << line << endl;
            while (wordstream >> word) // while the wordstream has words
            {

                if (contain(word, digits)) // checks if the word contains a digit

                {
                    if (word.find('R') != string::npos || word.find('r') != string::npos) //if it contains an 'R' then it is a register
                    {
                        registers[j] = word; // saves the registers
                        j++;                 // increase index
                    }
                    else if (word.find('x') != string::npos) //if it contains an 'x' then it is a hex number
                    {
                        operands[i] = wordToInt(word); // saves the 2 operands to the array
                        i++;                           // increase index
                    }
                    else  //if it contains a digit but not an 'R' or an 'x' then it is number of shifts
                    {
                        word.erase(0, 1);  //deletes the '#'
                        shifts = stoi(word);   //saves the number of shifts
                    }
                }
                else //if it doesn't contain digit then it is the opCode
                {
                    transform(word.begin(), word.end(), word.begin(), ::toupper); //to uppercase 
                    op = word; // save the operand type
                }
            }

            /////////CHECK ALL POSSIBLE CASES/////////////
            if (op == "ADD")
                add(register_values, registers);
            else if (op == "AND")
                bitAnd(register_values, registers);
            else if (op == "ASR")
                asr(register_values, registers, shifts);
            else if (op == "LSR")
                lsr(register_values, registers, shifts);
            else if (op == "LSL")
                lsl(register_values, registers, shifts);
            else if (op == "ORR")
                bitOr(register_values, registers);
            else if (op == "SUB")
                sub(register_values, registers);
            else if (op == "XOR")
                bitXor(register_values, registers);
            else if (op == "MOV")
                mov(register_values, operands, registers);
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
}

int main()
{
    readFile("Programming-Project-3.txt");
    return 0;
}