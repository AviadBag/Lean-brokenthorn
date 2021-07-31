#include "kernel/idt/idt.h"

#include <cstring.h>
#include <cstdio.h>

/* Idt flags */
#define INTERRUPT_IN_USE 0b10000000
#define INTERRUPT_NOT_IN_USE 0b00000000

#define PRIVILEGE_USER 0b01100000
#define PRIVILEGE_KERNEL 0b00000000

extern "C" void install_idt(uint32_t, uint32_t);
extern "C" void first_handler();

idt_descriptor IDT::idt[IDT_SIZE];

void IDT::initialize()
{
    kprintf("Initializing IDT...\n");
    init_descriptors();
    install();
}

void IDT::install()
{
    uint32_t size = sizeof(idt_descriptor) * IDT_SIZE - 1;
    install_idt((uint32_t)&idt, size); // Calls the assembly function
}

void IDT::init_descriptors()
{
    memset(&idt, 0, sizeof(idt_descriptor) * IDT_SIZE);

    set_descriptor(0, (uint32_t)isr0, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(1, (uint32_t)isr1, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(2, (uint32_t)isr2, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(3, (uint32_t)isr3, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(4, (uint32_t)isr4, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(5, (uint32_t)isr5, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(6, (uint32_t)isr6, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(7, (uint32_t)isr7, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(8, (uint32_t)isr8, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(9, (uint32_t)isr9, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(10, (uint32_t)isr10, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(11, (uint32_t)isr11, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(12, (uint32_t)isr12, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(13, (uint32_t)isr13, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(14, (uint32_t)isr14, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(15, (uint32_t)isr15, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(16, (uint32_t)isr16, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(17, (uint32_t)isr17, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(18, (uint32_t)isr18, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(19, (uint32_t)isr19, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(20, (uint32_t)isr20, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(21, (uint32_t)isr21, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(22, (uint32_t)isr22, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(23, (uint32_t)isr23, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(24, (uint32_t)isr24, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(25, (uint32_t)isr25, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(26, (uint32_t)isr26, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(27, (uint32_t)isr27, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(28, (uint32_t)isr28, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(29, (uint32_t)isr29, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(30, (uint32_t)isr30, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(31, (uint32_t)isr31, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(32, (uint32_t)isr32, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(33, (uint32_t)isr33, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(34, (uint32_t)isr34, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(35, (uint32_t)isr35, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(36, (uint32_t)isr36, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(37, (uint32_t)isr37, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(38, (uint32_t)isr38, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(39, (uint32_t)isr39, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(40, (uint32_t)isr40, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(41, (uint32_t)isr41, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(42, (uint32_t)isr42, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(43, (uint32_t)isr43, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(44, (uint32_t)isr44, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(45, (uint32_t)isr45, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(46, (uint32_t)isr46, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(47, (uint32_t)isr47, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(48, (uint32_t)isr48, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(49, (uint32_t)isr49, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(50, (uint32_t)isr50, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(51, (uint32_t)isr51, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(52, (uint32_t)isr52, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(53, (uint32_t)isr53, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(54, (uint32_t)isr54, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(55, (uint32_t)isr55, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(56, (uint32_t)isr56, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(57, (uint32_t)isr57, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(58, (uint32_t)isr58, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(59, (uint32_t)isr59, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(60, (uint32_t)isr60, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(61, (uint32_t)isr61, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(62, (uint32_t)isr62, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(63, (uint32_t)isr63, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(64, (uint32_t)isr64, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(65, (uint32_t)isr65, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(66, (uint32_t)isr66, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(67, (uint32_t)isr67, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(68, (uint32_t)isr68, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(69, (uint32_t)isr69, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(70, (uint32_t)isr70, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(71, (uint32_t)isr71, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(72, (uint32_t)isr72, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(73, (uint32_t)isr73, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(74, (uint32_t)isr74, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(75, (uint32_t)isr75, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(76, (uint32_t)isr76, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(77, (uint32_t)isr77, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(78, (uint32_t)isr78, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(79, (uint32_t)isr79, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(80, (uint32_t)isr80, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(81, (uint32_t)isr81, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(82, (uint32_t)isr82, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(83, (uint32_t)isr83, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(84, (uint32_t)isr84, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(85, (uint32_t)isr85, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(86, (uint32_t)isr86, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(87, (uint32_t)isr87, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(88, (uint32_t)isr88, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(89, (uint32_t)isr89, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(90, (uint32_t)isr90, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(91, (uint32_t)isr91, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(92, (uint32_t)isr92, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(93, (uint32_t)isr93, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(94, (uint32_t)isr94, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(95, (uint32_t)isr95, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(96, (uint32_t)isr96, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(97, (uint32_t)isr97, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(98, (uint32_t)isr98, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(99, (uint32_t)isr99, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(100, (uint32_t)isr100, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(101, (uint32_t)isr101, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(102, (uint32_t)isr102, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(103, (uint32_t)isr103, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(104, (uint32_t)isr104, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(105, (uint32_t)isr105, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(106, (uint32_t)isr106, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(107, (uint32_t)isr107, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(108, (uint32_t)isr108, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(109, (uint32_t)isr109, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(110, (uint32_t)isr110, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(111, (uint32_t)isr111, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(112, (uint32_t)isr112, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(113, (uint32_t)isr113, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(114, (uint32_t)isr114, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(115, (uint32_t)isr115, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(116, (uint32_t)isr116, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(117, (uint32_t)isr117, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(118, (uint32_t)isr118, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(119, (uint32_t)isr119, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(120, (uint32_t)isr120, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(121, (uint32_t)isr121, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(122, (uint32_t)isr122, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(123, (uint32_t)isr123, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(124, (uint32_t)isr124, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(125, (uint32_t)isr125, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(126, (uint32_t)isr126, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(127, (uint32_t)isr127, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(128, (uint32_t)isr128, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(129, (uint32_t)isr129, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(130, (uint32_t)isr130, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(131, (uint32_t)isr131, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(132, (uint32_t)isr132, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(133, (uint32_t)isr133, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(134, (uint32_t)isr134, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(135, (uint32_t)isr135, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(136, (uint32_t)isr136, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(137, (uint32_t)isr137, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(138, (uint32_t)isr138, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(139, (uint32_t)isr139, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(140, (uint32_t)isr140, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(141, (uint32_t)isr141, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(142, (uint32_t)isr142, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(143, (uint32_t)isr143, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(144, (uint32_t)isr144, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(145, (uint32_t)isr145, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(146, (uint32_t)isr146, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(147, (uint32_t)isr147, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(148, (uint32_t)isr148, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(149, (uint32_t)isr149, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(150, (uint32_t)isr150, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(151, (uint32_t)isr151, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(152, (uint32_t)isr152, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(153, (uint32_t)isr153, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(154, (uint32_t)isr154, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(155, (uint32_t)isr155, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(156, (uint32_t)isr156, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(157, (uint32_t)isr157, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(158, (uint32_t)isr158, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(159, (uint32_t)isr159, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(160, (uint32_t)isr160, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(161, (uint32_t)isr161, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(162, (uint32_t)isr162, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(163, (uint32_t)isr163, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(164, (uint32_t)isr164, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(165, (uint32_t)isr165, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(166, (uint32_t)isr166, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(167, (uint32_t)isr167, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(168, (uint32_t)isr168, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(169, (uint32_t)isr169, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(170, (uint32_t)isr170, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(171, (uint32_t)isr171, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(172, (uint32_t)isr172, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(173, (uint32_t)isr173, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(174, (uint32_t)isr174, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(175, (uint32_t)isr175, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(176, (uint32_t)isr176, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(177, (uint32_t)isr177, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(178, (uint32_t)isr178, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(179, (uint32_t)isr179, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(180, (uint32_t)isr180, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(181, (uint32_t)isr181, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(182, (uint32_t)isr182, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(183, (uint32_t)isr183, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(184, (uint32_t)isr184, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(185, (uint32_t)isr185, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(186, (uint32_t)isr186, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(187, (uint32_t)isr187, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(188, (uint32_t)isr188, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(189, (uint32_t)isr189, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(190, (uint32_t)isr190, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(191, (uint32_t)isr191, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(192, (uint32_t)isr192, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(193, (uint32_t)isr193, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(194, (uint32_t)isr194, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(195, (uint32_t)isr195, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(196, (uint32_t)isr196, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(197, (uint32_t)isr197, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(198, (uint32_t)isr198, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(199, (uint32_t)isr199, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(200, (uint32_t)isr200, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(201, (uint32_t)isr201, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(202, (uint32_t)isr202, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(203, (uint32_t)isr203, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(204, (uint32_t)isr204, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(205, (uint32_t)isr205, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(206, (uint32_t)isr206, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(207, (uint32_t)isr207, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(208, (uint32_t)isr208, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(209, (uint32_t)isr209, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(210, (uint32_t)isr210, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(211, (uint32_t)isr211, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(212, (uint32_t)isr212, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(213, (uint32_t)isr213, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(214, (uint32_t)isr214, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(215, (uint32_t)isr215, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(216, (uint32_t)isr216, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(217, (uint32_t)isr217, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(218, (uint32_t)isr218, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(219, (uint32_t)isr219, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(220, (uint32_t)isr220, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(221, (uint32_t)isr221, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(222, (uint32_t)isr222, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(223, (uint32_t)isr223, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(224, (uint32_t)isr224, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(225, (uint32_t)isr225, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(226, (uint32_t)isr226, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(227, (uint32_t)isr227, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(228, (uint32_t)isr228, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(229, (uint32_t)isr229, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(230, (uint32_t)isr230, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(231, (uint32_t)isr231, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(232, (uint32_t)isr232, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(233, (uint32_t)isr233, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(234, (uint32_t)isr234, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(235, (uint32_t)isr235, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(236, (uint32_t)isr236, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(237, (uint32_t)isr237, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(238, (uint32_t)isr238, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(239, (uint32_t)isr239, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(240, (uint32_t)isr240, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(241, (uint32_t)isr241, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(242, (uint32_t)isr242, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(243, (uint32_t)isr243, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(244, (uint32_t)isr244, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(245, (uint32_t)isr245, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(246, (uint32_t)isr246, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(247, (uint32_t)isr247, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(248, (uint32_t)isr248, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(249, (uint32_t)isr249, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(250, (uint32_t)isr250, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(251, (uint32_t)isr251, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(252, (uint32_t)isr252, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(253, (uint32_t)isr253, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(254, (uint32_t)isr254, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
    set_descriptor(255, (uint32_t)isr255, 0x8, INTERRUPT_IN_USE | PRIVILEGE_KERNEL);
}

void IDT::set_descriptor(int index, uint32_t handler, uint16_t selector, uint8_t flags)
{
    idt_descriptor descriptor;

    descriptor.handler_lower = handler & 0xFFFF; // Extract lower 16 bits
    descriptor.handler_higher = (handler >> 16) & 0xFFFF; // Extract heigher 16 bits

    descriptor.selector = selector;
    descriptor.zero = 0;
    descriptor.flags = flags | 0b00001110;

    idt[index] = descriptor;
}