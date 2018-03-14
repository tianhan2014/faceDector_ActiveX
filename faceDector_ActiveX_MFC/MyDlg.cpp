// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "faceDector_ActiveX_MFC.h"
#include "MyDlg.h"
#include "afxdialogex.h"

typedef struct Rect {
public:
	int Id;
	double scale[4];

	Rect() {
		Id = -2;
		scale[0] = 0;
		scale[1] = 0;
		scale[2] = 0;
		scale[3] = 0;
	}


	Rect(const Rect& c) {
		*this = c;
	}
}control;

// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::faceDector()
{

}


void MyDlg::showFrame(Mat& frame)
{
	CvvImage vimg;
	IplImage img(frame);
	vimg.CopyOf(&img);
	//获取pic控件的DC
	HDC dc = GetDlgItem(IDC_STATIC_01)->GetDC()->GetSafeHdc();
	//获取pic控件的大小
	RECT rect;
	GetDlgItem(IDC_STATIC_01)->GetClientRect(&rect);
	//将视频帧画到控件上
	vimg.DrawToHDC(dc, &rect);
}

void MyDlg::openVideo()
{
	if (!m_capture.isOpened())
	{
		m_capture.open(0);
		SetTimer(1, 40, NULL);
	}
}

void MyDlg::closeVideo()
{
	if (m_capture.isOpened())
	{
		m_capture.release();
		KillTimer(1);
		Invalidate();
	}
}

void MyDlg::openDector()
{
	if (!m_capture.isOpened())
	{
		m_capture.open(0);
		SetTimer(2, 40, NULL);
	}
}

void MyDlg::closeDector()
{
	if (m_capture.isOpened())
	{
		m_capture.release();
		KillTimer(2);
		Invalidate();
	}
}

void MyDlg::dectorFrame(Mat& frame)
{
	if (!dector) {
		dector = new mtcnn(frame.rows, frame.cols);
	}
	dector->findFace(frame);

	CvvImage vimg;
	IplImage img(frame);
	vimg.CopyOf(&img);
	//获取pic控件的DC
	HDC dc = GetDlgItem(IDC_STATIC_01)->GetDC()->GetSafeHdc();
	//获取pic控件的大小
	RECT rect;
	GetDlgItem(IDC_STATIC_01)->GetClientRect(&rect);
	//将视频帧画到控件上
	vimg.DrawToHDC(dc, &rect);
}

void MyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Mat frame;
	m_capture >> frame; //读取
	switch (nIDEvent)
	{
		case 1:
			showFrame(frame);
			break;
		case 2:
			dectorFrame(frame);
		default:
			break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void MyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect   rect;
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(0, 0, 0));   //设置为黑色背景
											// TODO: 在此处添加消息处理程序代码
											// 不为绘图消息调用 CDialogEx::OnPaint()
	CDialog::OnPaint();
}

CRect m_rect;//获取最开始的窗口大小
control m_control[10];//最多10个控件，这里代码可移植性没那么强，但是作者能力比较低，直接用数字代表，也没有用宏定义然后就可以在OnSize中添加方法了
void MyDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	//获取控件得到大小以及原大小，方便进行比例调整
	CWnd *pWnd;
	int woc;
	//列出所有控件
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
	//判定是否为最小状态，是的话就不进行重绘
	if (!cx || !cy) {
		return;
	} else {
		while (hwndChild) {
			woc = ::GetDlgCtrlID(hwndChild);//获得控件的ID
			pWnd = GetDlgItem(woc); //获取ID为woc的空间的句柄
			int i = 0;
			if (pWnd) {
				CRect rect;   //获取当前窗口的大小
				pWnd->GetWindowRect(&rect);
				ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标
				for (i = 0;i<10;i++)
				{
					if (m_control[i].Id == woc)//如果保存的有该控件与窗口比值，直接乘上当前窗口大小
					{
						rect.left = m_control[i].scale[0] * cx;
						rect.right = m_control[i].scale[1] * cx;
						rect.top = m_control[i].scale[2] * cy;
						rect.bottom = m_control[i].scale[3] * cy;
						break;
					}
				}
				if (i == 10) {
					for (i = 0;i<10;i++) {
						if (m_control[i].Id == -2) {//没有找到控件的比值，则选择一个没有数据的空间进行保存
							m_control[i].Id = woc;
							m_control[i].scale[0] = (double)rect.left / m_rect.Width();//注意类型转换，不然保存成long型就直接为0了
							m_control[i].scale[1] = (double)rect.right / m_rect.Width();
							m_control[i].scale[2] = (double)rect.top / m_rect.Height();
							m_control[i].scale[3] = (double)rect.bottom / m_rect.Height();
							/////调整控件大小
							rect.left = m_control[i].scale[0] * cx;
							rect.right = m_control[i].scale[1] * cx;
							rect.top = m_control[i].scale[2] * cy;
							rect.bottom = m_control[i].scale[3] * cy;
							break;
						}
					}
				}
				pWnd->MoveWindow(rect);//设置控件大小
			}
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
		}
		GetClientRect(&m_rect);//将变化后的对话框大小设为旧大小
	}
}


int MyDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}
