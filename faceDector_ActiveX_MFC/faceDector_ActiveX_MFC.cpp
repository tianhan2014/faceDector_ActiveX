// faceDector_ActiveX_MFC.cpp : CfaceDector_ActiveX_MFCApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CfaceDector_ActiveX_MFCApp theApp;

const GUID CDECL _tlid = { 0xA2932C81, 0x9892, 0x45F5, { 0x8A, 0x0, 0xDA, 0x13, 0xDC, 0xF5, 0xDC, 0xFA } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CfaceDector_ActiveX_MFCApp::InitInstance - DLL ��ʼ��

BOOL CfaceDector_ActiveX_MFCApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CfaceDector_ActiveX_MFCApp::ExitInstance - DLL ��ֹ

int CfaceDector_ActiveX_MFCApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
