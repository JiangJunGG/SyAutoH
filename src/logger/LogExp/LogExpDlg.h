// LogExpDlg.h : ͷ�ļ�
//

#pragma once

#include "../LogServer/LogServer.h"
#include "afxwin.h"
// CLogExpDlg �Ի���
class CLogExpDlg : public CDialog
{
// ����
public:
	CLogExpDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGEXP_DIALOG };

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
	afx_msg LRESULT OnLog(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

protected:
	CLogServer m_server;
public:
	afx_msg void OnDestroy();
	CEdit _edit;
};
