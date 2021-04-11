// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmem_mover.h"

extern XMem_mover_Config XMem_mover_ConfigTable[];

XMem_mover_Config *XMem_mover_LookupConfig(u16 DeviceId) {
	XMem_mover_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMEM_MOVER_NUM_INSTANCES; Index++) {
		if (XMem_mover_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMem_mover_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMem_mover_Initialize(XMem_mover *InstancePtr, u16 DeviceId) {
	XMem_mover_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMem_mover_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMem_mover_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

