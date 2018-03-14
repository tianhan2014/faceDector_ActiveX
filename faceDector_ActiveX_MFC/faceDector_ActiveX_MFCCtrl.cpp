// faceDector_ActiveX_MFCCtrl.cpp : CfaceDector_ActiveX_MFCCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"
#include "faceDector_ActiveX_MFCCtrl.h"
#include "faceDector_ActiveX_MFCPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CfaceDector_ActiveX_MFCCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CfaceDector_ActiveX_MFCCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CfaceDector_ActiveX_MFCCtrl, COleControl)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "faceDector", dispidfaceDector, faceDector, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "openVideo", dispidopenVideo, openVideo, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "closeVideo", dispidcloseVideo, closeVideo, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "openDector", dispidopenDector, openDector, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "closeDector", dispidcloseDector, closeDector, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CfaceDector_ActiveX_MFCCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CfaceDector_ActiveX_MFCCtrl, 1)
	PROPPAGEID(CfaceDector_ActiveX_MFCPropPage::guid)
END_PROPPAGEIDS(CfaceDector_ActiveX_MFCCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CfaceDector_ActiveX_MFCCtrl, "FACEDECTOR_ACTIV.faceDector_ActivCtrl.1",
	0x55d061ff, 0x628, 0x4e76, 0x92, 0x7a, 0x70, 0xcb, 0x35, 0x3f, 0xdf, 0x8f)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CfaceDector_ActiveX_MFCCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DfaceDector_ActiveX_MFC = { 0x4E768596, 0x5D72, 0x456B, { 0xB7, 0x33, 0xF3, 0xB2, 0xA7, 0x73, 0xED, 0x13 } };
const IID IID_DfaceDector_ActiveX_MFCEvents = { 0x1976A8FC, 0xC305, 0x490B, { 0x88, 0x98, 0x47, 0xB3, 0x83, 0xF6, 0xD4, 0xEA } };

// 控件类型信息

static const DWORD _dwfaceDector_ActiveX_MFCOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CfaceDector_ActiveX_MFCCtrl, IDS_FACEDECTOR_ACTIVEX_MFC, _dwfaceDector_ActiveX_MFCOleMisc)

// CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrlFactory::UpdateRegistry -
// 添加或移除 CfaceDector_ActiveX_MFCCtrl 的系统注册表项

BOOL CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_FACEDECTOR_ACTIVEX_MFC,
			IDB_FACEDECTOR_ACTIVEX_MFC,
			afxRegApartmentThreading,
			_dwfaceDector_ActiveX_MFCOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrl - 构造函数

CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrl()
{
	InitializeIIDs(&IID_DfaceDector_ActiveX_MFC, &IID_DfaceDector_ActiveX_MFCEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CfaceDector_ActiveX_MFCCtrl::~CfaceDector_ActiveX_MFCCtrl - 析构函数

CfaceDector_ActiveX_MFCCtrl::~CfaceDector_ActiveX_MFCCtrl()
{
	// TODO:  在此清理控件的实例数据。
	m_MyDlg.DestroyWindow();
}

// CfaceDector_ActiveX_MFCCtrl::OnDraw - 绘图函数

void CfaceDector_ActiveX_MFCCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	m_MyDlg.MoveWindow(rcBounds, true);
	m_MyDlg.pWnd = m_MyDlg.GetDlgItem(IDC_STATIC_01);
}

// CfaceDector_ActiveX_MFCCtrl::DoPropExchange - 持久性支持

void CfaceDector_ActiveX_MFCCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CfaceDector_ActiveX_MFCCtrl::OnResetState - 将控件重置为默认状态

void CfaceDector_ActiveX_MFCCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CfaceDector_ActiveX_MFCCtrl::AboutBox - 向用户显示“关于”框

void CfaceDector_ActiveX_MFCCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_FACEDECTOR_ACTIVEX_MFC);
	dlgAbout.DoModal();
}


// CfaceDector_ActiveX_MFCCtrl 消息处理程序


void CfaceDector_ActiveX_MFCCtrl::faceDector()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MyDlg.faceDector();
}


int CfaceDector_ActiveX_MFCCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_MyDlg.Create(IDD_DIALOG1, this);  //初始化对话框
	m_MyDlg.GetWindowRect(&m_MyDlg.m_rect);
	m_MyDlg.MoveWindow(lpCreateStruct->x, lpCreateStruct->y, lpCreateStruct->cx, lpCreateStruct->cy, true);
	m_MyDlg.ShowWindow(SW_SHOW);

	m_MyDlg.pWnd = m_MyDlg.GetDlgItem(IDC_STATIC_01);

	return 0;
}


void CfaceDector_ActiveX_MFCCtrl::openVideo()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MyDlg.openVideo();
}


void CfaceDector_ActiveX_MFCCtrl::closeVideo()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MyDlg.closeVideo();
}


void CfaceDector_ActiveX_MFCCtrl::openDector()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MyDlg.openDector();
}


void CfaceDector_ActiveX_MFCCtrl::closeDector()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MyDlg.closeDector();
}
