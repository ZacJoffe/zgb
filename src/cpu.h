#pragma once

#include "memory.h"

#include <cstdint>
#include <function>
#include <memory>

struct Registers {
    struct DoubleRegister { // TODO make this private? define outside of Registers's scope?
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
    Memory memory;
    uint32_t clock;
};

class InstrExecutor;

class InstrDecoder {
public:
    InstrDecoder();

    InstrExecutor decode(uint8_t opcode) const; // returns an instance of InstrExecutor with the correct method pointer
};


struct InstrCtx {
    std::unique_ptr<CpuCtx> cpu_ctx;
    uint8_t bytes;
    // TODO more fields
    InstrCtx(const std::unique_ptr<CpuCtx> & cpu_ctx, uint8_t bytes) : cpu_ctx(cpu_ctx), bytes(bytes) {}
};

class InstrExecutor {
public:
    // InstrExecutor();
    InstrExecutor(void (InstrExecuter::*instr), const InstrCtx & ctx);

    void execute();

private:
    friend class InstrDecoder;

    // https://stackoverflow.com/questions/11057206/creating-a-class-member-pointer-function-variable-that-points-to-a-non-static-cl
    void (InstrExecutor::*f_instr)(void);
    // TODO context, include reference to cpuctx
    InstrCtx m_ctx;

    static void nop();
    // TODO here tomorrow more instructions

};

class Cpu {
public:
    Cpu();

private:
    CpuCtx m_ctx;
};
