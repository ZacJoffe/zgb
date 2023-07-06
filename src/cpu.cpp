#include "cpu.h"

// TODO other classes

// TODO does this work?
// InstrExecutor::InstrExecutor() : f_instr(&InstrExecutor::nop) {}
InstrExecutor::InstrExecutor(void (InstrExecuter::*instr), const InstrCtx & ctx) : f_instr(instr), m_ctx(ctx) {}

void InstrExecutor::execute() {
    (*f_instr)();
}

static void InstrExecutor::nop() {}
