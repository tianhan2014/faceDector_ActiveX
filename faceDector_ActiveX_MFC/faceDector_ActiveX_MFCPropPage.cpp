// faceDector_ActiveX_MFCPropPage.cpp : CfaceDector_ActiveX_MFCPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"
#include "faceDector_ActiveX_MFCPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CfaceDector_ActiveX_MFCPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CfaceDector_ActiveX_MFCPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CfaceDector_ActiveX_MFCPropPage, "FACEDECTOR_ACT.faceDector_ActPropPage.1",
	0x5b52f6b4, 0xb08a, 0x4224, 0x8c, 0xc3, 0x5a, 0xf3, 0xb8, 0x7b, 0x7a, 0x45)

// CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CfaceDector_ActiveX_MFCPropPage ��ϵͳע�����

BOOL CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FACEDECTOR_ACTIVEX_MFC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPage - ���캯��

CfaceDector_ActiveX_MFCPropPage::CfaceDector_ActiveX_MFCPropPage() :
	COlePropertyPage(IDD, IDS_FACEDECTOR_ACTIVEX_MFC_PPG_CAPTION)
{
}

// CfaceDector_ActiveX_MFCPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CfaceDector_ActiveX_MFCPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CfaceDector_ActiveX_MFCPropPage ��Ϣ�������
