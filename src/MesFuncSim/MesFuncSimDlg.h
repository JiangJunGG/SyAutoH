
// MesFuncSimDlg.h : ͷ�ļ�
//

#pragma once
#include "../MesSim/MesSim.h"

// CMesFuncSimDlg �Ի���
class CMesFuncSimDlg : public CDialogEx
{
// ����
public:
	CMesFuncSimDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MESFUNCSIM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CMesSim m_MesSim;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPick();
	afx_msg void OnBnClickedButtonPlace();
	void GetFoupMoveParam(int& nFoup, int& nTarget);
};
