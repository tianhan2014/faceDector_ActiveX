// faceDector_ActiveX_MFCPropPage.cpp : CfaceDector_ActiveX_MFCPropPage 属性页类的实现。

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"
#include "faceDector_ActiveX_MFCPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CfaceDector_ActiveX_MFCPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CfaceDector_ActiveX_MFCPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CfaceDector_ActiveX_MFCPropPage, "FACEDECTOR_ACT.faceDector_ActPropPage.1",
	0x5b52f6b4, 0xb08a, 0x4224, 0x8c, 0xc3, 0x5a, 0xf3, 0xb8, 0x7b, 0x7a, 0x45)

// CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPageFactory::UpdateRegistry -
// 添加或移除 CfaceDector_ActiveX_MFCPropPage 的系统注册表项

BOOL CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FACEDECTOR_ACTIVEX_MFC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPage - 构造函数

CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPage() :
	COlePropertyPage(IDD, IDS_FACEDECTOR_ACTIVEX_MFC_PPG_CAPTION)
{
}

// CfaceDector_ActiveX_MFCPropPage::DoDataExchange - 在页和属性间移动数据

void CfaceDector_ActiveX_MFCPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CfaceDector_ActiveX_MFCPropPage 消息处理程序
