#pragma once


// CDlgAddOht �Ի���

class CDlgAddOht : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddOht)

public:
	CDlgAddOht(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAddOht();

// �Ի�������
	enum { IDD = IDD_DLG_ADDOHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

private:
	int m_nOhtID;

public:
	int OhtID() const { return m_nOhtID; }
};
