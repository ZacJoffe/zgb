#pragma once

#include <cstdint>

struct Registers {
    struct DoubleRegister { // TODO make this private? define outside of Registers scope?
        uint8_t Hi;
        uint8_t Lo;
    };

    uint8_t A;
    DoubleRegister BC;
    DoubleRegister DE;
    DoubleRegister HL;
    uint16_t SP;
    uint16_t PC;
};

struct Flags {
    bool Z; // zero flag
    bool N; // subtraction flag (bcd)
    bool H; // half carry flag (bcd)
    bool C; // carry flag
};

struct CpuCtx {
    Registers registers;
    Flags flags;
    uint32_t clock;
};

class InstrExecutor;

class InstrDecoder {
public:
    InstrDecoder();

    InstrExecutor decode(uint8_t opcode) const; // returns an instance of InstrExecutor with the correct method pointer
};

class InstrExecutor {
public:
    InstrExecutor();


private:

};

class Cpu {
public:
    Cpu();

private:
    CpuCtx m_ctx;
};
