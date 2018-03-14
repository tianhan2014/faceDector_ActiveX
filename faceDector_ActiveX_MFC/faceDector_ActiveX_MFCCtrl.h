#pragma once
#include "MyDlg.h"

// faceDector_ActiveX_MFCCtrl.h : CfaceDector_ActiveX_MFCCtrl ActiveX �ؼ����������


// CfaceDector_ActiveX_MFCCtrl : �й�ʵ�ֵ���Ϣ������� faceDector_ActiveX_MFCCtrl.cpp��

class CfaceDector_ActiveX_MFCCtrl : public COleControl
{
	DECLARE_DYNCREATE(CfaceDector_ActiveX_MFCCtrl)

// ���캯��
public:
	CfaceDector_ActiveX_MFCCtrl();
	MyDlg m_MyDlg;

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CfaceDector_ActiveX_MFCCtrl();

	DECLARE_OLECREATE_EX(CfaceDector_ActiveX_MFCCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CfaceDector_ActiveX_MFCCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CfaceDector_ActiveX_MFCCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CfaceDector_ActiveX_MFCCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidcloseDector = 5L,
		dispidopenDector = 4L,
		dispidcloseVideo = 3L,
		dispidopenVideo = 2L,
		dispidfaceDector = 1L
	};
protected:
	void faceDector();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	void openVideo();
	void closeVideo();
	void openDector();
	void closeDector();
};

