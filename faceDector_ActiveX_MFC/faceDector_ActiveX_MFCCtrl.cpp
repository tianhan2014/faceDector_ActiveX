// faceDector_ActiveX_MFCCtrl.cpp : CfaceDector_ActiveX_MFCCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"
#include "faceDector_ActiveX_MFCCtrl.h"
#include "faceDector_ActiveX_MFCPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CfaceDector_ActiveX_MFCCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CfaceDector_ActiveX_MFCCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CfaceDector_ActiveX_MFCCtrl, COleControl)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "faceDector", dispidfaceDector, faceDector, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "openVideo", dispidopenVideo, openVideo, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "closeVideo", dispidcloseVideo, closeVideo, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "openDector", dispidopenDector, openDector, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CfaceDector_ActiveX_MFCCtrl, "closeDector", dispidcloseDector, closeDector, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CfaceDector_ActiveX_MFCCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CfaceDector_ActiveX_MFCCtrl, 1)
	PROPPAGEID(CfaceDector_ActiveX_MFCPropPage::guid)
END_PROPPAGEIDS(CfaceDector_ActiveX_MFCCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CfaceDector_ActiveX_MFCCtrl, "FACEDECTOR_ACTIV.faceDector_ActivCtrl.1",
	0x55d061ff, 0x628, 0x4e76, 0x92, 0x7a, 0x70, 0xcb, 0x35, 0x3f, 0xdf, 0x8f)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CfaceDector_ActiveX_MFCCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DfaceDector_ActiveX_MFC = { 0x4E768596, 0x5D72, 0x456B, { 0xB7, 0x33, 0xF3, 0xB2, 0xA7, 0x73, 0xED, 0x13 } };
const IID IID_DfaceDector_ActiveX_MFCEvents = { 0x1976A8FC, 0xC305, 0x490B, { 0x88, 0x98, 0x47, 0xB3, 0x83, 0xF6, 0xD4, 0xEA } };

// �ؼ�������Ϣ

static const DWORD _dwfaceDector_ActiveX_MFCOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CfaceDector_ActiveX_MFCCtrl, IDS_FACEDECTOR_ACTIVEX_MFC, _dwfaceDector_ActiveX_MFCOleMisc)

// CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CfaceDector_ActiveX_MFCCtrl ��ϵͳע�����

BOOL CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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


// CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrl - ���캯��

CfaceDector_ActiveX_MFCCtrl::CfaceDector_ActiveX_MFCCtrl()
{
	InitializeIIDs(&IID_DfaceDector_ActiveX_MFC, &IID_DfaceDector_ActiveX_MFCEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CfaceDector_ActiveX_MFCCtrl::~CfaceDector_ActiveX_MFCCtrl - ��������

CfaceDector_ActiveX_MFCCtrl::~CfaceDector_ActiveX_MFCCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
	m_MyDlg.DestroyWindow();
}

// CfaceDector_ActiveX_MFCCtrl::OnDraw - ��ͼ����

void CfaceDector_ActiveX_MFCCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	m_MyDlg.MoveWindow(rcBounds, true);
	m_MyDlg.pWnd = m_MyDlg.GetDlgItem(IDC_STATIC_01);
}

// CfaceDector_ActiveX_MFCCtrl::DoPropExchange - �־���֧��

void CfaceDector_ActiveX_MFCCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CfaceDector_ActiveX_MFCCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CfaceDector_ActiveX_MFCCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CfaceDector_ActiveX_MFCCtrl::AboutBox - ���û���ʾ�����ڡ���

void CfaceDector_ActiveX_MFCCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_FACEDECTOR_ACTIVEX_MFC);
	dlgAbout.DoModal();
}


// CfaceDector_ActiveX_MFCCtrl ��Ϣ�������


void CfaceDector_ActiveX_MFCCtrl::faceDector()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MyDlg.faceDector();
}


int CfaceDector_ActiveX_MFCCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_MyDlg.Create(IDD_DIALOG1, this);  //��ʼ���Ի���
	m_MyDlg.GetWindowRect(&m_MyDlg.m_rect);
	m_MyDlg.MoveWindow(lpCreateStruct->x, lpCreateStruct->y, lpCreateStruct->cx, lpCreateStruct->cy, true);
	m_MyDlg.ShowWindow(SW_SHOW);

	m_MyDlg.pWnd = m_MyDlg.GetDlgItem(IDC_STATIC_01);

	return 0;
}


void CfaceDector_ActiveX_MFCCtrl::openVideo()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MyDlg.openVideo();
}


void CfaceDector_ActiveX_MFCCtrl::closeVideo()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MyDlg.closeVideo();
}


void CfaceDector_ActiveX_MFCCtrl::openDector()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MyDlg.openDector();
}


void CfaceDector_ActiveX_MFCCtrl::closeDector()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MyDlg.closeDector();
}
