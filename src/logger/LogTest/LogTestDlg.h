// LogTestDlg.h : ͷ�ļ�
//

#pragma once

// CLogTestDlg �Ի���
class CLogTestDlg : public CDialog
{
// ����
public:
	CLogTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGTEST_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnHello();
	afx_msg void OnBnClickedBnSend();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBnSendm();
	afx_msg void OnBnClickedBnBeginauto();
	afx_msg void OnBnClickedBnEndauto();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void LogRandMsg(void);
	int GetRandNum(int nMax, int nMin);
};
