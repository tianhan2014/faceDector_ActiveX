// MyDlg.cpp : ʵ���ļ�
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

// MyDlg �Ի���

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


// MyDlg ��Ϣ�������


void MyDlg::faceDector()
{

}


void MyDlg::showFrame(Mat& frame)
{
	CvvImage vimg;
	IplImage img(frame);
	vimg.CopyOf(&img);
	//��ȡpic�ؼ���DC
	HDC dc = GetDlgItem(IDC_STATIC_01)->GetDC()->GetSafeHdc();
	//��ȡpic�ؼ��Ĵ�С
	RECT rect;
	GetDlgItem(IDC_STATIC_01)->GetClientRect(&rect);
	//����Ƶ֡�����ؼ���
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
	//��ȡpic�ؼ���DC
	HDC dc = GetDlgItem(IDC_STATIC_01)->GetDC()->GetSafeHdc();
	//��ȡpic�ؼ��Ĵ�С
	RECT rect;
	GetDlgItem(IDC_STATIC_01)->GetClientRect(&rect);
	//����Ƶ֡�����ؼ���
	vimg.DrawToHDC(dc, &rect);
}

void MyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Mat frame;
	m_capture >> frame; //��ȡ
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
	dc.FillSolidRect(rect, RGB(0, 0, 0));   //����Ϊ��ɫ����
											// TODO: �ڴ˴������Ϣ����������
											// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CDialog::OnPaint();
}

CRect m_rect;//��ȡ�ʼ�Ĵ��ڴ�С
control m_control[10];//���10���ؼ�������������ֲ��û��ôǿ���������������Ƚϵͣ�ֱ�������ִ���Ҳû���ú궨��Ȼ��Ϳ�����OnSize����ӷ�����
void MyDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	//��ȡ�ؼ��õ���С�Լ�ԭ��С��������б�������
	CWnd *pWnd;
	int woc;
	//�г����пؼ�
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
	//�ж��Ƿ�Ϊ��С״̬���ǵĻ��Ͳ������ػ�
	if (!cx || !cy) {
		return;
	} else {
		while (hwndChild) {
			woc = ::GetDlgCtrlID(hwndChild);//��ÿؼ���ID
			pWnd = GetDlgItem(woc); //��ȡIDΪwoc�Ŀռ�ľ��
			int i = 0;
			if (pWnd) {
				CRect rect;   //��ȡ��ǰ���ڵĴ�С
				pWnd->GetWindowRect(&rect);
				ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
				for (i = 0;i<10;i++)
				{
					if (m_control[i].Id == woc)//���������иÿؼ��봰�ڱ�ֵ��ֱ�ӳ��ϵ�ǰ���ڴ�С
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
						if (m_control[i].Id == -2) {//û���ҵ��ؼ��ı�ֵ����ѡ��һ��û�����ݵĿռ���б���
							m_control[i].Id = woc;
							m_control[i].scale[0] = (double)rect.left / m_rect.Width();//ע������ת������Ȼ�����long�;�ֱ��Ϊ0��
							m_control[i].scale[1] = (double)rect.right / m_rect.Width();
							m_control[i].scale[2] = (double)rect.top / m_rect.Height();
							m_control[i].scale[3] = (double)rect.bottom / m_rect.Height();
							/////�����ؼ���С
							rect.left = m_control[i].scale[0] * cx;
							rect.right = m_control[i].scale[1] * cx;
							rect.top = m_control[i].scale[2] * cy;
							rect.bottom = m_control[i].scale[3] * cy;
							break;
						}
					}
				}
				pWnd->MoveWindow(rect);//���ÿؼ���С
			}
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
		}
		GetClientRect(&m_rect);//���仯��ĶԻ����С��Ϊ�ɴ�С
	}
}


int MyDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}
