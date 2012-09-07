
// DLLTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DLLTest.h"
#include "DLLTestDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "string.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDLLTestDlg �Ի���




CDLLTestDlg::CDLLTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDLLTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDLLTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_input);
	DDX_Control(pDX, IDC_EDIT2, m_output);
	DDX_Control(pDX, IDC_EDIT3, m_name);
	DDX_Control(pDX, IDC_EDIT5, m_passWord);
	DDX_Control(pDX, IDC_EDIT4, m_high);
	DDX_Control(pDX, IDC_EDIT6, m_low);
	DDX_Control(pDX, IDC_EDIT7, m_outInfo);
}

BEGIN_MESSAGE_MAP(CDLLTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDLLTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDLLTestDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDLLTestDlg ��Ϣ�������

BOOL CDLLTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDLLTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDLLTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDLLTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDLLTestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_output.Clear();
	CString input;
	string outdll;
	string indll;
	CString output;
	m_input.GetWindowText(input);
	indll = input.GetBuffer(input.GetLength());
	HMODULE hm;
	hm = LoadLibrary(_T("sha1transform.dll"));
	if(hm == NULL)
	{
		AfxMessageBox(_T("����ʧ��"));
	}
	typedef string(*transform)(string);
	transform pfn = (transform) GetProcAddress(hm,"SHA1Transform");
	if(pfn == NULL)
	{
		AfxMessageBox(_T("��õ�ַʧ��"));
	}
	outdll = pfn(indll);
	output = outdll.c_str();
	m_output.SetWindowText(output);	
	FreeLibrary(hm);
}


void CDLLTestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_outInfo.Clear();
	CString name;
	CString passWord;
	CString high;
	CString low;
	m_name.GetWindowText(name);
	m_passWord.GetWindowText(passWord);
	m_high.GetWindowText(high);
	m_low.GetWindowText(low);
	string namestr = name.GetBuffer(sizeof(name));
	string passWordstr = passWord.GetBuffer(sizeof(passWord));
	string highstr = high.GetBuffer(sizeof(high));
	string lowstr = low.GetBuffer(sizeof(low));
	HMODULE hm = LoadLibrary("sha1transform");
	typedef string(*info)(string&,string&,string&,string&);
	info pfn = (info)GetProcAddress(hm,"HashLoginInfo");
	string loginInfo;
	loginInfo = pfn(namestr,highstr,lowstr,passWordstr);
	CString out;
	out = loginInfo.c_str();
	m_outInfo.SetWindowText(out);
	FreeLibrary(hm);
}
