
/*
1 RXY LOAD the register R with the bit pattern found in the memory cell whose address is XY.
Example: 14A3 would cause the contents of the memory cell located at address A3 to be placed in register 4.

2 RXY LOAD the register R with the bit pattern XY.
Example: 20A3 would cause the value A3 to be placed in register 0.

3 RXY STORE the bit pattern found in register R in the memory cell whose address is XY.
Example: 35B1 would cause the contents of register 5 to be placed in the memory cell whose address is B1.

3 R00 STORE to location 00, which is a memory mapping for the screen. Writing to 00 is writing to screen.
4 0RS MOVE the bit pattern found in register R to register S.
Example: 40A4 would cause the contents of register A to be copied into register 4.

5 RST ADD the bit patterns in registers S and T as though they were two’s complement representations and leave the result in register R.
Example: 5726 would cause the binary values in registers 2 and 6 to be added and the sum placed in register 7.

6 RST ADD the bit patterns in registers S and T as though they represented values in floating-point notation and leave the floating-point result in register R.
Example: 634E would cause the values in registers 4 and E to be added as floating-point values and the result to be placed in register 3.

B RXY JUMP to the instruction located in the memory cell at address XY if the bit pattern in register R
        is equal to the bit pattern in register number 0. Otherwise, continue with the normal sequence of
        execution. (The jump is implemented by copying XY into the program counter during the execute phase.)
Example: B43C would first compare the contents of register 4 with the contents of register 0. If
        the two were equal, the pattern 3C would be placed in the program counter so that the next
        instruction executed would be the one located at that memory address. Otherwise, nothing would
be done and program execution would continue in its normal sequence.

C 000 HALT execution.
Example: C000 would cause program execution to stop.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CPU;
class Register;
class Memory;
class Machine;

class Register
{
private:
    string memory[16];
    int size = 16;

public:
    string get_cell(int);
    void set_cell(int, string);
};

class Memory
{
private:
    string memory[256];
    int size = 256;

public:
    string get_cell(int);
    void set_cell(int, string);
};

class CPU
{
private:
    Memory *ptr;
    int PC;
    string IR;
    Register reg;

public:
    CPU(Memory *memory) : ptr(memory), PC(0), IR("") {}
    string hexa_to_dec(string);
    string dec_to_hexa(int);
    int get_twos_comp(int);
    float get_float(int);
    string get_binary(float);
    int convert_from_float(string);
    bool is_valid();
    void add5(int, int, int, Register &);
    void add6(int, int, int, Register &);
    void load(int, int , Register &, Memory &);
    void load(int, int, Register &);
    void store(int,int, Register &, Memory &);
    void move(int, int, Register &);
    void jump(int, int, Register & , int &);
    void halt();
    void runNextStep(Memory *);
    void fetch(Memory *);
    vector<int> decode();
    void execute(Register &, Memory *, vector<int>);
};

class Machine
{
private:
    Memory storage;
    CPU cpu(Memory *);

public:
};
