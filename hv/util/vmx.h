#pragma once

#include "arch.h"

namespace hv {

// INVEPT instruction
void vmx_invept(invept_type type, invept_descriptor const& desc);

// VMXON instruction
bool vmx_vmxon(uint64_t vmxon_phys_addr);

// VMXOFF instruction
void vmx_vmxoff();

// VMCLEAR instruction
bool vmx_vmclear(uint64_t vmcs_phys_addr);

// VMPTRLD instruction
bool vmx_vmptrld(uint64_t vmcs_phys_addr);

// VMWRITE instruction
void vmx_vmwrite(uint64_t field, uint64_t value);

// VMREAD instruction
uint64_t vmx_vmread(uint64_t field);



// write to the guest interruptibility state
void write_interruptibility_state(vmx_interruptibility_state value);

// read the guest interruptibility state
vmx_interruptibility_state read_interruptibility_state();



// write to the pin-based vm-execution controls
void write_ctrl_pin_based_safe(ia32_vmx_pinbased_ctls_register value);

// write to the processor-based vm-execution controls
void write_ctrl_proc_based_safe(ia32_vmx_procbased_ctls_register value);

// write to the secondary processor-based vm-execution controls
void write_ctrl_proc_based2_safe(ia32_vmx_procbased_ctls2_register value);

// write to the vm-exit controls
void write_ctrl_exit_safe(ia32_vmx_exit_ctls_register value);

// write to the vm-entry controls
void write_ctrl_entry_safe(ia32_vmx_entry_ctls_register value);



// write to the pin-based vm-execution controls
void write_ctrl_pin_based(ia32_vmx_pinbased_ctls_register value);

// write to the processor-based vm-execution controls
void write_ctrl_proc_based(ia32_vmx_procbased_ctls_register value);

// write to the secondary processor-based vm-execution controls
void write_ctrl_proc_based2(ia32_vmx_procbased_ctls2_register value);

// write to the vm-exit controls
void write_ctrl_exit(ia32_vmx_exit_ctls_register value);

// write to the vm-entry controls
void write_ctrl_entry(ia32_vmx_entry_ctls_register value);



// read the pin-based vm-execution controls
ia32_vmx_pinbased_ctls_register read_ctrl_pin_based();

// read the processor-based vm-execution controls
ia32_vmx_procbased_ctls_register read_ctrl_proc_based();

// read the secondary processor-based vm-execution controls
ia32_vmx_procbased_ctls2_register read_ctrl_proc_based2();

// read the vm-exit controls
ia32_vmx_exit_ctls_register read_ctrl_exit();

// read the vm-entry controls
ia32_vmx_entry_ctls_register read_ctrl_entry();



// increment the instruction pointer after emulating an instruction
void skip_instruction();



// inject a non-maskable interrupt into the guest
void inject_nmi();

// inject a vectored exception into the guest
void inject_hw_exception(uint32_t vector);

// inject a vectored exception into the guest (with an error code)
void inject_hw_exception(uint32_t vector, uint32_t error);

} // namespace hv

#include "vmx.inl"
