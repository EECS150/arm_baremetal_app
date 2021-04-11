// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmem_mover.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMem_mover_CfgInitialize(XMem_mover *InstancePtr, XMem_mover_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMem_mover_Start(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMem_mover_IsDone(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMem_mover_IsIdle(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMem_mover_IsReady(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMem_mover_EnableAutoRestart(XMem_mover *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMem_mover_DisableAutoRestart(XMem_mover *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_AP_CTRL, 0);
}

void XMem_mover_Set_in_offset(XMem_mover *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IN_OFFSET_DATA, Data);
}

u32 XMem_mover_Get_in_offset(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IN_OFFSET_DATA);
    return Data;
}

void XMem_mover_Set_out_offset(XMem_mover *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_OUT_OFFSET_DATA, Data);
}

u32 XMem_mover_Get_out_offset(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_OUT_OFFSET_DATA);
    return Data;
}

void XMem_mover_Set_N(XMem_mover *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_N_DATA, Data);
}

u32 XMem_mover_Get_N(XMem_mover *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_N_DATA);
    return Data;
}

void XMem_mover_InterruptGlobalEnable(XMem_mover *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_GIE, 1);
}

void XMem_mover_InterruptGlobalDisable(XMem_mover *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_GIE, 0);
}

void XMem_mover_InterruptEnable(XMem_mover *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IER);
    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IER, Register | Mask);
}

void XMem_mover_InterruptDisable(XMem_mover *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IER);
    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMem_mover_InterruptClear(XMem_mover *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMem_mover_WriteReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_ISR, Mask);
}

u32 XMem_mover_InterruptGetEnabled(XMem_mover *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_IER);
}

u32 XMem_mover_InterruptGetStatus(XMem_mover *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMem_mover_ReadReg(InstancePtr->Control_BaseAddress, XMEM_MOVER_CONTROL_ADDR_ISR);
}

