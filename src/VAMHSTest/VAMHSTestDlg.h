
// VAMHSTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "../VirtualAMHS/VirtualAMHS.h"

// CVAMHSTestDlg �Ի���
class CVAMHSTestDlg : public CDialogEx
{
// ����
public:
	CVAMHSTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CVAMHSTestDlg();

// �Ի�������
	enum { IDD = IDD_VAMHSTEST_DIALOG };

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
	afx_msg void OnBnClickedBnOHTonline();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBnAddstk();
	afx_msg void OnBnClickedBnStkIn();
	afx_msg void OnBnClickedBnStkOut();
	afx_msg void OnBnClickedBnOhtAdd();
	afx_msg void OnBnClickedBnSethand();
	afx_msg void OnBnClickedBnSetpos();
	CListCtrl m_listCtrlOHT;
	CListCtrl m_listCtrlFOUP;
	void InitListCtrlOHT(void);
	void InitListCtrlFOUP(void);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void SetOHTListItemData(ItemOHT* pOHT, int nListIndex);
	afx_msg void OnBnClickedBnStkHistory();
};
