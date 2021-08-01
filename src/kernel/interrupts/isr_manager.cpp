#include "kernel/interrupts/isr_manager.h"
#include "drivers/pic/pic.h"

#define IRQ_START 32
#define IRQ_END 47

#define NUMBER_OF_INTERRUPTS 256

struct isr_holder
{
    isr i;
    void* context;
    bool exist = false;
} isrs[NUMBER_OF_INTERRUPTS] = {};

struct registers {
    uint32_t ds; // Data segment selector
    uint32_t edi, esi, ebp, useless_value, ebx, edx, ecx, eax; // Pushed by pusha.
    uint32_t interrupt_number, err_code; // Interrupt number and error code (if applicable)
    uint32_t eip, cs, eflags, esp, ss; // Pushed by the processor automatically.
} __attribute__((packed));

extern "C" void general_isr_handler(struct registers regs)
{
    // Send EOI if this is an IRQ.
    if (regs.interrupt_number >= IRQ_START && regs.interrupt_number <= IRQ_END) {
        int irq = regs.interrupt_number - IRQ_START;
        PIC::send_end_of_interrupt(irq);
    }

    // Call the registered handler
    if (isrs[regs.interrupt_number].exist)
        isrs[regs.interrupt_number].i(isrs[regs.interrupt_number].context, regs.err_code);
}

void isr_manager_set_isr(unsigned char interrupt_number, isr i, void* context)
{
    isrs[interrupt_number] = isr_holder{i, context, true};
}
