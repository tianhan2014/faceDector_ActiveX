#pragma once
#include "MyDlg.h"

// faceDector_ActiveX_MFCCtrl.h : CfaceDector_ActiveX_MFCCtrl ActiveX 控件类的声明。


// CfaceDector_ActiveX_MFCCtrl : 有关实现的信息，请参阅 faceDector_ActiveX_MFCCtrl.cpp。

class CfaceDector_ActiveX_MFCCtrl : public COleControl
{
	DECLARE_DYNCREATE(CfaceDector_ActiveX_MFCCtrl)

// 构造函数
public:
	CfaceDector_ActiveX_MFCCtrl();
	MyDlg m_MyDlg;

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CfaceDector_ActiveX_MFCCtrl();

	DECLARE_OLECREATE_EX(CfaceDector_ActiveX_MFCCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CfaceDector_ActiveX_MFCCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CfaceDector_ActiveX_MFCCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CfaceDector_ActiveX_MFCCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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

