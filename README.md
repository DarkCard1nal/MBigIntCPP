# MBigIntCPP
module (library) for using long HEX numbers.

# installation:

#include "MBigIntCPP.h"

# Opportunities:

The MBigIntCPP class has constructors:

MBigIntCPP(std::string hexString) - creates an object by calling the setHex() method.

MBigIntCPP(MBigIntCPP object ) - creates a copy of the object.

Class Methods:

static MBigIntCPP XOR(MBigIntCPP a, MBigIntCPP b) - XOR '^' operation.

static MBigIntCPP OR(MBigIntCPP a, MBigIntCPP b) - OR '|' operation.

static MBigIntCPP AND(MBigIntCPP a, MBigIntCPP b) - operation AND '&'.

static MBigIntCPP ADD(MBigIntCPP a, MBigIntCPP b) - sum '+' operation.

static MBigIntCPP SUB(MBigIntCPP a, MBigIntCPP b) - operation of difference '-'.

static MBigIntCPP MUL(MBigIntCPP a, MBigIntCPP b) - multiplication operation '*'.

Object Methods:

void INV() - bit inversion operation.

void shiftR(int n) - operation of bit shift to the right by n bits '>>'.

void shiftL(int n) - operation of bit shift to the left by n bits '<<'.

# Examples and tests in examples.cpp
