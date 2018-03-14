#pragma once

// faceDector_ActiveX_MFC.h : faceDector_ActiveX_MFC.DLL 的主头文件

#if !defined( __AFXCTL_H__ )
#error "在包括此文件之前包括“afxctl.h”"
#endif

#include "resource.h"       // 主符号


// CfaceDector_ActiveX_MFCApp : 有关实现的信息，请参阅 faceDector_ActiveX_MFC.cpp。

class CfaceDector_ActiveX_MFCApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

