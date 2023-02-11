#pragma once
#include <comdef.h>


#define CFG_COM_HANDLER_LOCATION "C:\\demos\\other\\com_handler.dll"


// this must be changed to the CLSID specified in the registry 
//ECABD3A3-725D-4334-AAFC-BB13234F1202
extern "C" {
    DEFINE_GUID(CLSID_TaskHandler,
        0xECABD3A3, 0x725D, 0x4334, 0xAA, 0xFC, 0xBB, 0x13, 0x23, 0x4F, 0x12, 0x02
    );
}