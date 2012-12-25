// LogClientWinTestDlg.h : ͷ�ļ�
//

#pragma once
#include <afxtempl.h>

// CLogClientWinTestDlg �Ի���
class CLogClientWinTestDlg : public CDialog
{
// ����
public:
	CLogClientWinTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGCLIENTWINTEST_DIALOG };

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
	afx_msg void OnBnClickedBnDefmsg();
	afx_msg void OnBnClickedBnSend();
	afx_msg void OnBnClickedBnSend1k();
	afx_msg void OnBnClickedBnAutobegin();
	afx_msg void OnBnClickedBnEndAuto();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();

protected:
	CWinThread* m_pThread;
	static UINT __SendLog(LPVOID lp);
	CList<CWinThread*, CWinThread*> m_listThread;
	int m_nThreadID;
	
public:
	void AddThread(void);
	void CleanThreadAll(void);

	void DrawThreadCount(void);
	afx_msg void OnBnClickedBnAlmcount();
};
