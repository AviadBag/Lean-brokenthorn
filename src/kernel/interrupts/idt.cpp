#include "kernel/interrupts/idt.h"

#include <cstring.h>
#include <cstdio.h>

/* Idt flags */
#define INTERRUPT_IN_USE 0b10000000
#define INTERRUPT_NOT_IN_USE 0b00000000

#define PRIVILEGE_USER 0b01100000
#define PRIVILEGE_KERNEL 0b00000000

extern "C" void install_idt(uint32_t, uint32_t);

extern "C" void isr0();
extern "C" void isr1();
extern "C" void isr2();
extern "C" void isr3();
extern "C" void isr4();
extern "C" void isr5();
extern "C" void isr6();
extern "C" void isr7();
extern "C" void isr8();
extern "C" void isr9();
extern "C" void isr10();
extern "C" void isr11();
extern "C" void isr12();
extern "C" void isr13();
extern "C" void isr14();
extern "C" void isr15();
extern "C" void isr16();
extern "C" void isr17();
extern "C" void isr18();
extern "C" void isr19();
extern "C" void isr20();
extern "C" void isr21();
extern "C" void isr22();
extern "C" void isr23();
extern "C" void isr24();
extern "C" void isr25();
extern "C" void isr26();
extern "C" void isr27();
extern "C" void isr28();
extern "C" void isr29();
extern "C" void isr30();
extern "C" void isr31();
extern "C" void isr32();
extern "C" void isr33();
extern "C" void isr34();
extern "C" void isr35();
extern "C" void isr36();
extern "C" void isr37();
extern "C" void isr38();
extern "C" void isr39();
extern "C" void isr40();
extern "C" void isr41();
extern "C" void isr42();
extern "C" void isr43();
extern "C" void isr44();
extern "C" void isr45();
extern "C" void isr46();
extern "C" void isr47();
extern "C" void isr48();
extern "C" void isr49();
extern "C" void isr50();
extern "C" void isr51();
extern "C" void isr52();
extern "C" void isr53();
extern "C" void isr54();
extern "C" void isr55();
extern "C" void isr56();
extern "C" void isr57();
extern "C" void isr58();
extern "C" void isr59();
extern "C" void isr60();
extern "C" void isr61();
extern "C" void isr62();
extern "C" void isr63();
extern "C" void isr64();
extern "C" void isr65();
extern "C" void isr66();
extern "C" void isr67();
extern "C" void isr68();
extern "C" void isr69();
extern "C" void isr70();
extern "C" void isr71();
extern "C" void isr72();
extern "C" void isr73();
extern "C" void isr74();
extern "C" void isr75();
extern "C" void isr76();
extern "C" void isr77();
extern "C" void isr78();
extern "C" void isr79();
extern "C" void isr80();
extern "C" void isr81();
extern "C" void isr82();
extern "C" void isr83();
extern "C" void isr84();
extern "C" void isr85();
extern "C" void isr86();
extern "C" void isr87();
extern "C" void isr88();
extern "C" void isr89();
extern "C" void isr90();
extern "C" void isr91();
extern "C" void isr92();
extern "C" void isr93();
extern "C" void isr94();
extern "C" void isr95();
extern "C" void isr96();
extern "C" void isr97();
extern "C" void isr98();
extern "C" void isr99();
extern "C" void isr100();
extern "C" void isr101();
extern "C" void isr102();
extern "C" void isr103();
extern "C" void isr104();
extern "C" void isr105();
extern "C" void isr106();
extern "C" void isr107();
extern "C" void isr108();
extern "C" void isr109();
extern "C" void isr110();
extern "C" void isr111();
extern "C" void isr112();
extern "C" void isr113();
extern "C" void isr114();
extern "C" void isr115();
extern "C" void isr116();
extern "C" void isr117();
extern "C" void isr118();
extern "C" void isr119();
extern "C" void isr120();
extern "C" void isr121();
extern "C" void isr122();
extern "C" void isr123();
extern "C" void isr124();
extern "C" void isr125();
extern "C" void isr126();
extern "C" void isr127();
extern "C" void isr128();
extern "C" void isr129();
extern "C" void isr130();
extern "C" void isr131();
extern "C" void isr132();
extern "C" void isr133();
extern "C" void isr134();
extern "C" void isr135();
extern "C" void isr136();
extern "C" void isr137();
extern "C" void isr138();
extern "C" void isr139();
extern "C" void isr140();
extern "C" void isr141();
extern "C" void isr142();
extern "C" void isr143();
extern "C" void isr144();
extern "C" void isr145();
extern "C" void isr146();
extern "C" void isr147();
extern "C" void isr148();
extern "C" void isr149();
extern "C" void isr150();
extern "C" void isr151();
extern "C" void isr152();
extern "C" void isr153();
extern "C" void isr154();
extern "C" void isr155();
extern "C" void isr156();
extern "C" void isr157();
extern "C" void isr158();
extern "C" void isr159();
extern "C" void isr160();
extern "C" void isr161();
extern "C" void isr162();
extern "C" void isr163();
extern "C" void isr164();
extern "C" void isr165();
extern "C" void isr166();
extern "C" void isr167();
extern "C" void isr168();
extern "C" void isr169();
extern "C" void isr170();
extern "C" void isr171();
extern "C" void isr172();
extern "C" void isr173();
extern "C" void isr174();
extern "C" void isr175();
extern "C" void isr176();
extern "C" void isr177();
extern "C" void isr178();
extern "C" void isr179();
extern "C" void isr180();
extern "C" void isr181();
extern "C" void isr182();
extern "C" void isr183();
extern "C" void isr184();
extern "C" void isr185();
extern "C" void isr186();
extern "C" void isr187();
extern "C" void isr188();
extern "C" void isr189();
extern "C" void isr190();
extern "C" void isr191();
extern "C" void isr192();
extern "C" void isr193();
extern "C" void isr194();
extern "C" void isr195();
extern "C" void isr196();
extern "C" void isr197();
extern "C" void isr198();
extern "C" void isr199();
extern "C" void isr200();
extern "C" void isr201();
extern "C" void isr202();
extern "C" void isr203();
extern "C" void isr204();
extern "C" void isr205();
extern "C" void isr206();
extern "C" void isr207();
extern "C" void isr208();
extern "C" void isr209();
extern "C" void isr210();
extern "C" void isr211();
extern "C" void isr212();
extern "C" void isr213();
extern "C" void isr214();
extern "C" void isr215();
extern "C" void isr216();
extern "C" void isr217();
extern "C" void isr218();
extern "C" void isr219();
extern "C" void isr220();
extern "C" void isr221();
extern "C" void isr222();
extern "C" void isr223();
extern "C" void isr224();
extern "C" void isr225();
extern "C" void isr226();
extern "C" void isr227();
extern "C" void isr228();
extern "C" void isr229();
extern "C" void isr230();
extern "C" void isr231();
extern "C" void isr232();
extern "C" void isr233();
extern "C" void isr234();
extern "C" void isr235();
extern "C" void isr236();
extern "C" void isr237();
extern "C" void isr238();
extern "C" void isr239();
extern "C" void isr240();
extern "C" void isr241();
extern "C" void isr242();
extern "C" void isr243();
extern "C" void isr244();
extern "C" void isr245();
extern "C" void isr246();
extern "C" void isr247();
extern "C" void isr248();
extern "C" void isr249();
extern "C" void isr250();
extern "C" void isr251();
extern "C" void isr252();
extern "C" void isr253();
extern "C" void isr254();
extern "C" void isr255();

void IDT::install()
{
    kprintf("Initializing IDT...\n");
    put_descriptors();
    
    uint32_t idt_size = sizeof(idt_descriptor) * IDT_SIZE - 1;
    install_idt((uint32_t)&idt, idt_size); // Calls the assembly function
}

void IDT::put_descriptors()
{
    memset(&idt, 0, sizeof(idt_descriptor) * IDT_SIZE);

    put_descriptor(0, (uint32_t)isr0, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(1, (uint32_t)isr1, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(2, (uint32_t)isr2, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(3, (uint32_t)isr3, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(4, (uint32_t)isr4, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(5, (uint32_t)isr5, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(6, (uint32_t)isr6, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(7, (uint32_t)isr7, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(8, (uint32_t)isr8, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(9, (uint32_t)isr9, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(10, (uint32_t)isr10, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(11, (uint32_t)isr11, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(12, (uint32_t)isr12, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(13, (uint32_t)isr13, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(14, (uint32_t)isr14, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(15, (uint32_t)isr15, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(16, (uint32_t)isr16, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(17, (uint32_t)isr17, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(18, (uint32_t)isr18, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(19, (uint32_t)isr19, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(20, (uint32_t)isr20, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(21, (uint32_t)isr21, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(22, (uint32_t)isr22, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(23, (uint32_t)isr23, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(24, (uint32_t)isr24, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(25, (uint32_t)isr25, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(26, (uint32_t)isr26, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(27, (uint32_t)isr27, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(28, (uint32_t)isr28, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(29, (uint32_t)isr29, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(30, (uint32_t)isr30, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(31, (uint32_t)isr31, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(32, (uint32_t)isr32, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(33, (uint32_t)isr33, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(34, (uint32_t)isr34, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(35, (uint32_t)isr35, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(36, (uint32_t)isr36, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(37, (uint32_t)isr37, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(38, (uint32_t)isr38, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(39, (uint32_t)isr39, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(40, (uint32_t)isr40, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(41, (uint32_t)isr41, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(42, (uint32_t)isr42, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(43, (uint32_t)isr43, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(44, (uint32_t)isr44, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(45, (uint32_t)isr45, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(46, (uint32_t)isr46, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(47, (uint32_t)isr47, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(48, (uint32_t)isr48, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(49, (uint32_t)isr49, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(50, (uint32_t)isr50, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(51, (uint32_t)isr51, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(52, (uint32_t)isr52, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(53, (uint32_t)isr53, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(54, (uint32_t)isr54, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(55, (uint32_t)isr55, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(56, (uint32_t)isr56, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(57, (uint32_t)isr57, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(58, (uint32_t)isr58, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(59, (uint32_t)isr59, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(60, (uint32_t)isr60, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(61, (uint32_t)isr61, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(62, (uint32_t)isr62, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(63, (uint32_t)isr63, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(64, (uint32_t)isr64, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(65, (uint32_t)isr65, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(66, (uint32_t)isr66, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(67, (uint32_t)isr67, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(68, (uint32_t)isr68, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(69, (uint32_t)isr69, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(70, (uint32_t)isr70, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(71, (uint32_t)isr71, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(72, (uint32_t)isr72, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(73, (uint32_t)isr73, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(74, (uint32_t)isr74, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(75, (uint32_t)isr75, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(76, (uint32_t)isr76, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(77, (uint32_t)isr77, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(78, (uint32_t)isr78, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(79, (uint32_t)isr79, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(80, (uint32_t)isr80, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(81, (uint32_t)isr81, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(82, (uint32_t)isr82, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(83, (uint32_t)isr83, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(84, (uint32_t)isr84, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(85, (uint32_t)isr85, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(86, (uint32_t)isr86, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(87, (uint32_t)isr87, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(88, (uint32_t)isr88, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(89, (uint32_t)isr89, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(90, (uint32_t)isr90, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(91, (uint32_t)isr91, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(92, (uint32_t)isr92, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(93, (uint32_t)isr93, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(94, (uint32_t)isr94, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(95, (uint32_t)isr95, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(96, (uint32_t)isr96, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(97, (uint32_t)isr97, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(98, (uint32_t)isr98, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(99, (uint32_t)isr99, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(100, (uint32_t)isr100, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(101, (uint32_t)isr101, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(102, (uint32_t)isr102, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(103, (uint32_t)isr103, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(104, (uint32_t)isr104, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(105, (uint32_t)isr105, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(106, (uint32_t)isr106, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(107, (uint32_t)isr107, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(108, (uint32_t)isr108, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(109, (uint32_t)isr109, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(110, (uint32_t)isr110, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(111, (uint32_t)isr111, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(112, (uint32_t)isr112, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(113, (uint32_t)isr113, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(114, (uint32_t)isr114, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(115, (uint32_t)isr115, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(116, (uint32_t)isr116, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(117, (uint32_t)isr117, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(118, (uint32_t)isr118, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(119, (uint32_t)isr119, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(120, (uint32_t)isr120, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(121, (uint32_t)isr121, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(122, (uint32_t)isr122, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(123, (uint32_t)isr123, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(124, (uint32_t)isr124, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(125, (uint32_t)isr125, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(126, (uint32_t)isr126, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(127, (uint32_t)isr127, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(128, (uint32_t)isr128, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(129, (uint32_t)isr129, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(130, (uint32_t)isr130, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(131, (uint32_t)isr131, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(132, (uint32_t)isr132, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(133, (uint32_t)isr133, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(134, (uint32_t)isr134, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(135, (uint32_t)isr135, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(136, (uint32_t)isr136, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(137, (uint32_t)isr137, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(138, (uint32_t)isr138, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(139, (uint32_t)isr139, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(140, (uint32_t)isr140, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(141, (uint32_t)isr141, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(142, (uint32_t)isr142, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(143, (uint32_t)isr143, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(144, (uint32_t)isr144, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(145, (uint32_t)isr145, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(146, (uint32_t)isr146, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(147, (uint32_t)isr147, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(148, (uint32_t)isr148, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(149, (uint32_t)isr149, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(150, (uint32_t)isr150, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(151, (uint32_t)isr151, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(152, (uint32_t)isr152, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(153, (uint32_t)isr153, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(154, (uint32_t)isr154, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(155, (uint32_t)isr155, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(156, (uint32_t)isr156, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(157, (uint32_t)isr157, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(158, (uint32_t)isr158, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(159, (uint32_t)isr159, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(160, (uint32_t)isr160, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(161, (uint32_t)isr161, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(162, (uint32_t)isr162, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(163, (uint32_t)isr163, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(164, (uint32_t)isr164, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(165, (uint32_t)isr165, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(166, (uint32_t)isr166, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(167, (uint32_t)isr167, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(168, (uint32_t)isr168, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(169, (uint32_t)isr169, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(170, (uint32_t)isr170, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(171, (uint32_t)isr171, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(172, (uint32_t)isr172, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(173, (uint32_t)isr173, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(174, (uint32_t)isr174, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(175, (uint32_t)isr175, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(176, (uint32_t)isr176, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(177, (uint32_t)isr177, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(178, (uint32_t)isr178, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(179, (uint32_t)isr179, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(180, (uint32_t)isr180, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(181, (uint32_t)isr181, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(182, (uint32_t)isr182, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(183, (uint32_t)isr183, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(184, (uint32_t)isr184, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(185, (uint32_t)isr185, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(186, (uint32_t)isr186, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(187, (uint32_t)isr187, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(188, (uint32_t)isr188, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(189, (uint32_t)isr189, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(190, (uint32_t)isr190, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(191, (uint32_t)isr191, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(192, (uint32_t)isr192, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(193, (uint32_t)isr193, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(194, (uint32_t)isr194, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(195, (uint32_t)isr195, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(196, (uint32_t)isr196, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(197, (uint32_t)isr197, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(198, (uint32_t)isr198, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(199, (uint32_t)isr199, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(200, (uint32_t)isr200, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(201, (uint32_t)isr201, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(202, (uint32_t)isr202, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(203, (uint32_t)isr203, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(204, (uint32_t)isr204, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(205, (uint32_t)isr205, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(206, (uint32_t)isr206, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(207, (uint32_t)isr207, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(208, (uint32_t)isr208, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(209, (uint32_t)isr209, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(210, (uint32_t)isr210, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(211, (uint32_t)isr211, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(212, (uint32_t)isr212, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(213, (uint32_t)isr213, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(214, (uint32_t)isr214, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(215, (uint32_t)isr215, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(216, (uint32_t)isr216, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(217, (uint32_t)isr217, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(218, (uint32_t)isr218, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(219, (uint32_t)isr219, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(220, (uint32_t)isr220, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(221, (uint32_t)isr221, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(222, (uint32_t)isr222, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(223, (uint32_t)isr223, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(224, (uint32_t)isr224, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(225, (uint32_t)isr225, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(226, (uint32_t)isr226, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(227, (uint32_t)isr227, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(228, (uint32_t)isr228, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(229, (uint32_t)isr229, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(230, (uint32_t)isr230, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(231, (uint32_t)isr231, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(232, (uint32_t)isr232, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(233, (uint32_t)isr233, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(234, (uint32_t)isr234, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(235, (uint32_t)isr235, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(236, (uint32_t)isr236, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(237, (uint32_t)isr237, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(238, (uint32_t)isr238, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(239, (uint32_t)isr239, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(240, (uint32_t)isr240, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(241, (uint32_t)isr241, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(242, (uint32_t)isr242, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(243, (uint32_t)isr243, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(244, (uint32_t)isr244, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(245, (uint32_t)isr245, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(246, (uint32_t)isr246, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(247, (uint32_t)isr247, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(248, (uint32_t)isr248, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(249, (uint32_t)isr249, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(250, (uint32_t)isr250, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(251, (uint32_t)isr251, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(252, (uint32_t)isr252, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(253, (uint32_t)isr253, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(254, (uint32_t)isr254, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    put_descriptor(255, (uint32_t)isr255, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
}

void IDT::put_descriptor(int index, uint32_t handler, uint16_t selector, uint8_t flags)
{
    idt_descriptor descriptor;

    descriptor.handler_lower = handler & 0xFFFF; // Extract lower 16 bits
    descriptor.handler_higher = (handler >> 16) & 0xFFFF; // Extract heigher 16 bits

    descriptor.selector = selector;
    descriptor.zero = 0;
    descriptor.flags = flags | 0b00001110;

    idt[index] = descriptor;
}

/* ------------------------- Singelton stuff. ------------------------- */
IDT* IDT::instance = nullptr;

IDT::IDT() {}

IDT* IDT::get_instance() 
{
    if (!instance)
        instance = new IDT;

    return instance;
}