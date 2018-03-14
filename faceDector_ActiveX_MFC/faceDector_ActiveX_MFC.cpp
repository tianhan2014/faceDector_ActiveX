// faceDector_ActiveX_MFC.cpp : CfaceDector_ActiveX_MFCApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CfaceDector_ActiveX_MFCApp theApp;

const GUID CDECL _tlid = { 0xA2932C81, 0x9892, 0x45F5, { 0x8A, 0x0, 0xDA, 0x13, 0xDC, 0xF5, 0xDC, 0xFA } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CfaceDector_ActiveX_MFCApp::InitInstance - DLL 初始化

BOOL CfaceDector_ActiveX_MFCApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CfaceDector_ActiveX_MFCApp::ExitInstance - DLL 终止

int CfaceDector_ActiveX_MFCApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
