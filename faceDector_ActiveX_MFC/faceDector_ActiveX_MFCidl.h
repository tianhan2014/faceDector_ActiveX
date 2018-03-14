

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __faceDector_ActiveX_MFCidl_h__
#define __faceDector_ActiveX_MFCidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DfaceDector_ActiveX_MFC_FWD_DEFINED__
#define ___DfaceDector_ActiveX_MFC_FWD_DEFINED__
typedef interface _DfaceDector_ActiveX_MFC _DfaceDector_ActiveX_MFC;

#endif 	/* ___DfaceDector_ActiveX_MFC_FWD_DEFINED__ */


#ifndef ___DfaceDector_ActiveX_MFCEvents_FWD_DEFINED__
#define ___DfaceDector_ActiveX_MFCEvents_FWD_DEFINED__
typedef interface _DfaceDector_ActiveX_MFCEvents _DfaceDector_ActiveX_MFCEvents;

#endif 	/* ___DfaceDector_ActiveX_MFCEvents_FWD_DEFINED__ */


#ifndef __faceDector_ActiveX_MFC_FWD_DEFINED__
#define __faceDector_ActiveX_MFC_FWD_DEFINED__

#ifdef __cplusplus
typedef class faceDector_ActiveX_MFC faceDector_ActiveX_MFC;
#else
typedef struct faceDector_ActiveX_MFC faceDector_ActiveX_MFC;
#endif /* __cplusplus */

#endif 	/* __faceDector_ActiveX_MFC_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_faceDector_ActiveX_MFC_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_faceDector_ActiveX_MFC_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_faceDector_ActiveX_MFC_0000_0000_v0_0_s_ifspec;


#ifndef __faceDector_ActiveX_MFCLib_LIBRARY_DEFINED__
#define __faceDector_ActiveX_MFCLib_LIBRARY_DEFINED__

/* library faceDector_ActiveX_MFCLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_faceDector_ActiveX_MFCLib;

#ifndef ___DfaceDector_ActiveX_MFC_DISPINTERFACE_DEFINED__
#define ___DfaceDector_ActiveX_MFC_DISPINTERFACE_DEFINED__

/* dispinterface _DfaceDector_ActiveX_MFC */
/* [uuid] */ 


EXTERN_C const IID DIID__DfaceDector_ActiveX_MFC;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4E768596-5D72-456B-B733-F3B2A773ED13")
    _DfaceDector_ActiveX_MFC : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DfaceDector_ActiveX_MFCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DfaceDector_ActiveX_MFC * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DfaceDector_ActiveX_MFC * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DfaceDector_ActiveX_MFC * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DfaceDector_ActiveX_MFC * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DfaceDector_ActiveX_MFC * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DfaceDector_ActiveX_MFC * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DfaceDector_ActiveX_MFC * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DfaceDector_ActiveX_MFCVtbl;

    interface _DfaceDector_ActiveX_MFC
    {
        CONST_VTBL struct _DfaceDector_ActiveX_MFCVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DfaceDector_ActiveX_MFC_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DfaceDector_ActiveX_MFC_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DfaceDector_ActiveX_MFC_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DfaceDector_ActiveX_MFC_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DfaceDector_ActiveX_MFC_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DfaceDector_ActiveX_MFC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DfaceDector_ActiveX_MFC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DfaceDector_ActiveX_MFC_DISPINTERFACE_DEFINED__ */


#ifndef ___DfaceDector_ActiveX_MFCEvents_DISPINTERFACE_DEFINED__
#define ___DfaceDector_ActiveX_MFCEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DfaceDector_ActiveX_MFCEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DfaceDector_ActiveX_MFCEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1976A8FC-C305-490B-8898-47B383F6D4EA")
    _DfaceDector_ActiveX_MFCEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DfaceDector_ActiveX_MFCEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DfaceDector_ActiveX_MFCEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DfaceDector_ActiveX_MFCEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DfaceDector_ActiveX_MFCEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DfaceDector_ActiveX_MFCEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DfaceDector_ActiveX_MFCEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DfaceDector_ActiveX_MFCEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DfaceDector_ActiveX_MFCEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DfaceDector_ActiveX_MFCEventsVtbl;

    interface _DfaceDector_ActiveX_MFCEvents
    {
        CONST_VTBL struct _DfaceDector_ActiveX_MFCEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DfaceDector_ActiveX_MFCEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DfaceDector_ActiveX_MFCEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DfaceDector_ActiveX_MFCEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DfaceDector_ActiveX_MFCEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DfaceDector_ActiveX_MFCEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DfaceDector_ActiveX_MFCEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DfaceDector_ActiveX_MFCEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DfaceDector_ActiveX_MFCEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_faceDector_ActiveX_MFC;

#ifdef __cplusplus

class DECLSPEC_UUID("55D061FF-0628-4E76-927A-70CB353FDF8F")
faceDector_ActiveX_MFC;
#endif
#endif /* __faceDector_ActiveX_MFCLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


