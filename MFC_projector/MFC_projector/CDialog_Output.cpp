// CDialog_Output.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialog_Output.h"
#include "afxdialogex.h"


// CDialog_Output 对话框

IMPLEMENT_DYNAMIC(CDialog_Output, CDialog)

CDialog_Output::CDialog_Output(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_OUTPUT, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialog_Output::~CDialog_Output()
{
}

void CDialog_Output::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_edit1);
	DDX_Control(pDX, IDC_EDIT4, m_edit2);
}


BEGIN_MESSAGE_MAP(CDialog_Output, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog_Output::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialog_Output::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialog_Output 消息处理程序


void CDialog_Output::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"转账等待中", L"转账等待中", 0);
	Sleep(3000);
	MessageBox(L"转账成功", L"转账成功", 0);

}


void CDialog_Output::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	m_edit2.SetWindowTextW(L"");
}


BOOL CDialog_Output::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	this->SetWindowTextW(L"打款");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
