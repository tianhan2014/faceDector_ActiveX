#pragma once

// faceDector_ActiveX_MFC.h : faceDector_ActiveX_MFC.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CfaceDector_ActiveX_MFCApp : �й�ʵ�ֵ���Ϣ������� faceDector_ActiveX_MFC.cpp��

class CfaceDector_ActiveX_MFCApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

