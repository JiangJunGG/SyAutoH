
// DLLTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CDLLTestDlg �Ի���
class CDLLTestDlg : public CDialogEx
{
// ����
public:
	CDLLTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_input;
	CEdit m_output;
	afx_msg void OnBnClickedButton1();
	CEdit m_name;
	CEdit m_passWord;
	CEdit m_high;
	CEdit m_low;
	CEdit m_outInfo;
	afx_msg void OnBnClickedButton2();
};
