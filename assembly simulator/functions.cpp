
#include "functions.h"

//////////////////converts the numbers on the file  from string to long ints///////////////////////////
uint32_t wordToInt(string word)
{
    uint32_t number;                   // declare var to hold number
    int pos = word.find("x");          // position where x from 0x is
    string num = word.substr(pos + 1); // cut the string so it doesn't have 0x
    stringstream numberstream;         // create stream to hold numbers
    numberstream << std::hex << num;   // passes the hex number to the stream
    numberstream >> number;            // passes the stream to the number
    return number;
}

////////////////////////////////converts long int into hex string///////////////////////////////

string intToHexString(uint32_t number)
{
    stringstream snumber;                 // create stream to hold the number
    snumber << std::hex << number;        // passes the number converted to hex string into the string
    string result = "0x" + snumber.str(); // string that holds the number stringstream converted to string
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

////////////////CHECKS IF THE WORD CONTAINS ANY OF THE ELEMENTS IN THE ARRAY DIGITS /////////////////////////
bool contain(string word, char digits[])
{
    for (int i = 0; i < 10; i++)
    {
        if (word.find(digits[i]) != std::string::npos)
            return true;
    }
    return false;
}

////////////////////////////////ADD function//////////////////////////////
void add(string *registers, string r[])
{
    // the string array r contains the registers that were included in the instruction.
    // r[0] is the destination and r[1] and r[2] are the registers with the operands

    int reg1 = r[1][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the first operand
    int reg2 = r[2][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the second operand

    // the register values are saved in the register array
    uint32_t add1 = wordToInt(registers[reg1]);     // operand 1 is in register array in the index given by reg1
    uint32_t add2 = wordToInt(registers[reg2]);     // operand 2 is in register array in the index given by reg2
    uint32_t sum = add1 + add2;                     // perform addition
    int reg_to_update = r[0][1] - '0';              // gets the 2nd character (for example the 0 in 'R0') from the destination register
    registers[reg_to_update] = intToHexString(sum); // updates destination register with result found  above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ":" << registers[i] << "  "; // prints updated register array
    cout << endl;
}
////////////////////////////////SUB function///////////////////////////////
void sub(string *registers, string r[])
{
    int reg1 = r[1][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the first operand
    int reg2 = r[2][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the second operand

    uint32_t sub1 = wordToInt(registers[reg1]);     // operand 1 is in register array in the index given by reg1
    uint32_t sub2 = wordToInt(registers[reg2]);     // operand 2 is in register array in the index given by reg2
    uint32_t sub = sub1 - sub2;                     // perform subtraction
    int reg_to_update = r[0][1] - '0';              // gets the 2nd character (for example the 0 in 'R0') from the destination register
    registers[reg_to_update] = intToHexString(sub); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ":" << registers[i] << "  "; // prints updated register array
    cout << endl;
}

////////////////////////////////AND function///////////////////////////////
void bitAnd(string *registers, string r[])
{
    int reg1 = r[1][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the first operand
    int reg2 = r[2][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the second operand

    uint32_t and1 = wordToInt(registers[reg1]);        // operand 1 is in register array in the index given by reg1
    uint32_t and2 = wordToInt(registers[reg2]);        // operand 2 is in register array in the index given by reg2
    uint32_t bitAnd = and1 & and2;                     // performs and
    int reg_to_update = r[0][1] - '0';                 // gets the 2nd character (for example the 0 in 'R0') from the destination register
    registers[reg_to_update] = intToHexString(bitAnd); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ":" << registers[i] << "  "; // prints updated register array
    cout << endl;
}
////////////////////////////////OR function///////////////////////////////
void bitOr(string *registers, string r[])
{
    int reg1 = r[1][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the first operand
    int reg2 = r[2][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the second operand

    uint32_t or1 = wordToInt(registers[reg1]);        // operand 1 is in register array in the index given by reg1
    uint32_t or2 = wordToInt(registers[reg2]);        // operand 2 is in register array in the index given by reg2
    uint32_t bitOr = or1 | or2;                       // performs or
    int reg_to_update = r[0][1] - '0';                // gets the 2nd character (for example the 0 in 'R0') from the destination register
    registers[reg_to_update] = intToHexString(bitOr); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ":" << registers[i] << "  "; // prints updated register array
    cout << endl;
}
////////////////////////////////XOR function///////////////////////////////
void bitXor(string *registers, string r[])
{
    int reg1 = r[1][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the first operand
    int reg2 = r[2][1] - '0'; // gets the 2nd character (for example the 0 in 'R0') from the register with the second operand

    uint32_t xor1 = wordToInt(registers[reg1]);        // operand 1 is in register array in the index given by reg1
    uint32_t xor2 = wordToInt(registers[reg2]);        // operand 2 is in register array in the index given by reg2
    uint32_t bitXor = xor1 ^ xor2;                     // performs xor
    int reg_to_update = r[0][1] - '0';                 // gets the 2nd character (for example the 0 in 'R0') from the destination register
    registers[reg_to_update] = intToHexString(bitXor); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ":" << registers[i] << "  "; // prints updated register array
    cout << endl;
}

////////////////////////////////ASR function///////////////////////////////
void asr(string *registers, string r[], int shifts)
{
    int reg_to_update = r[0][1] - '0';              // gets the 2nd character (for example the 0 in 'R0') from the destination register
    int reg = r[1][1] - '0';                        // gets the 2nd character (for example the 0 in 'R0') from the register with the number to be shifted
    uint32_t to_shift = wordToInt(registers[reg]);  // the number to be shifted is in the register array in the index given by reg
    uint32_t asr = signed(to_shift) >> shifts;      // perform asr
    registers[reg_to_update] = intToHexString(asr); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ": " << registers[i] << " "; // prints updated register array
    cout << endl;
}
////////////////////////////////LSL function///////////////////////////////
void lsl(string *registers, string r[], int shifts)
{
    int reg_to_update = r[0][1] - '0';              // gets the 2nd character (for example the 0 in 'R0') from the destination register
    int reg = r[1][1] - '0';                        // gets the 2nd character (for example the 0 in 'R0') from the register with the number to be shifted
    uint32_t to_shift = wordToInt(registers[reg]);  // the number to be shifted is in the register array in the index given by reg
    uint32_t lsl = to_shift << shifts;              // performs lsl
    registers[reg_to_update] = intToHexString(lsl); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ": " << registers[i] << " "; // prints updated register array
    cout << endl;
}
////////////////////////////////LSR function///////////////////////////////
void lsr(string *registers, string r[], int shifts)
{
    int reg_to_update = r[0][1] - '0';              // gets the 2nd character (for example the 0 in 'R0') from the destination register
    int reg = r[1][1] - '0';                        // gets the 2nd character (for example the 0 in 'R0') from the register with the number to be shifted
    uint32_t to_shift = wordToInt(registers[reg]);  // the number to be shifted is in the register array in the index given by reg
    uint32_t lsr = to_shift >> shifts;              // performs lsr
    registers[reg_to_update] = intToHexString(lsr); // updates destination register with result found above
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ": " << registers[i] << " "; // prints updated register array
    cout << endl;
}

////////////////////////////////MOV function///////////////////////////////
void mov(string *registers, uint32_t operands[], string r[])
{
    int reg_to_update = r[0][1] - '0';                      // gets the 2nd character (for example the 0 in 'R0') from the destination register
    registers[reg_to_update] = intToHexString(operands[0]); // operands[0] is the nuber to be moved. It gets moved into the registers array at the index given by reg_to__update
    for (int i = 0; i < 8; i++)
        cout << "R" << i << ": " << registers[i] << " "; // prints updated registers array
    cout << endl;
}