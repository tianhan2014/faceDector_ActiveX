#pragma once
#include "network.h"
#include "mtcnn.h"
#include "CvvImage.h"


// MyDlg �Ի���

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CWnd *pWnd;
	CRect m_rect;
	VideoCapture m_capture;
	mtcnn *dector;

	void faceDector();
	void showFrame(Mat& frame);
	void openVideo();
	void closeVideo();
	void dectorFrame(Mat& frame);
	void openDector();
	void closeDector();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
