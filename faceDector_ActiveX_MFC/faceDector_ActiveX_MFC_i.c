

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Mar 14 08:46:49 2018
 */
/* Compiler settings for faceDector_ActiveX_MFC.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_faceDector_ActiveX_MFCLib,0xA2932C81,0x9892,0x45F5,0x8A,0x00,0xDA,0x13,0xDC,0xF5,0xDC,0xFA);


MIDL_DEFINE_GUID(IID, DIID__DfaceDector_ActiveX_MFC,0x4E768596,0x5D72,0x456B,0xB7,0x33,0xF3,0xB2,0xA7,0x73,0xED,0x13);


MIDL_DEFINE_GUID(IID, DIID__DfaceDector_ActiveX_MFCEvents,0x1976A8FC,0xC305,0x490B,0x88,0x98,0x47,0xB3,0x83,0xF6,0xD4,0xEA);


MIDL_DEFINE_GUID(CLSID, CLSID_faceDector_ActiveX_MFC,0x55D061FF,0x0628,0x4E76,0x92,0x7A,0x70,0xCB,0x35,0x3F,0xDF,0x8F);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



