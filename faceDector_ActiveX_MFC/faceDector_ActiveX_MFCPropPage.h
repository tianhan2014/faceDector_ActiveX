#pragma once

// faceDector_ActiveX_MFCPropPage.h : CfaceDector_ActiveX_MFCPropPage ����ҳ���������


// CfaceDector_ActiveX_MFCPropPage : �й�ʵ�ֵ���Ϣ������� faceDector_ActiveX_MFCPropPage.cpp��

class CfaceDector_ActiveX_MFCPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CfaceDector_ActiveX_MFCPropPage)
	DECLARE_OLECREATE_EX(CfaceDector_ActiveX_MFCPropPage)

// ���캯��
public:
	CfaceDector_ActiveX_MFCPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_FACEDECTOR_ACTIVEX_MFC };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

