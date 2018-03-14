#pragma once

// faceDector_ActiveX_MFCPropPage.h : CfaceDector_ActiveX_MFCPropPage 属性页类的声明。


// CfaceDector_ActiveX_MFCPropPage : 有关实现的信息，请参阅 faceDector_ActiveX_MFCPropPage.cpp。

class CfaceDector_ActiveX_MFCPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CfaceDector_ActiveX_MFCPropPage)
	DECLARE_OLECREATE_EX(CfaceDector_ActiveX_MFCPropPage)

// 构造函数
public:
	CfaceDector_ActiveX_MFCPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_FACEDECTOR_ACTIVEX_MFC };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

