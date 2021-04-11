// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMEM_MOVER_H
#define XMEM_MOVER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmem_mover_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XMem_mover_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XMem_mover;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMem_mover_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMem_mover_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMem_mover_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMem_mover_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMem_mover_Initialize(XMem_mover *InstancePtr, u16 DeviceId);
XMem_mover_Config* XMem_mover_LookupConfig(u16 DeviceId);
int XMem_mover_CfgInitialize(XMem_mover *InstancePtr, XMem_mover_Config *ConfigPtr);
#else
int XMem_mover_Initialize(XMem_mover *InstancePtr, const char* InstanceName);
int XMem_mover_Release(XMem_mover *InstancePtr);
#endif

void XMem_mover_Start(XMem_mover *InstancePtr);
u32 XMem_mover_IsDone(XMem_mover *InstancePtr);
u32 XMem_mover_IsIdle(XMem_mover *InstancePtr);
u32 XMem_mover_IsReady(XMem_mover *InstancePtr);
void XMem_mover_EnableAutoRestart(XMem_mover *InstancePtr);
void XMem_mover_DisableAutoRestart(XMem_mover *InstancePtr);

void XMem_mover_Set_in_offset(XMem_mover *InstancePtr, u32 Data);
u32 XMem_mover_Get_in_offset(XMem_mover *InstancePtr);
void XMem_mover_Set_out_offset(XMem_mover *InstancePtr, u32 Data);
u32 XMem_mover_Get_out_offset(XMem_mover *InstancePtr);
void XMem_mover_Set_N(XMem_mover *InstancePtr, u32 Data);
u32 XMem_mover_Get_N(XMem_mover *InstancePtr);

void XMem_mover_InterruptGlobalEnable(XMem_mover *InstancePtr);
void XMem_mover_InterruptGlobalDisable(XMem_mover *InstancePtr);
void XMem_mover_InterruptEnable(XMem_mover *InstancePtr, u32 Mask);
void XMem_mover_InterruptDisable(XMem_mover *InstancePtr, u32 Mask);
void XMem_mover_InterruptClear(XMem_mover *InstancePtr, u32 Mask);
u32 XMem_mover_InterruptGetEnabled(XMem_mover *InstancePtr);
u32 XMem_mover_InterruptGetStatus(XMem_mover *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
