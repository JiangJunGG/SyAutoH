// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#define DBINITCONSTANTS
#define INITGUID
#define OLEDBVER 0x0250   // to include correct interfaces

#include <stdio.h>
#include <tchar.h>
#include <stddef.h>
#include <iostream>
//#include <oledb.h>
#include <SQLNCLI.h>
#include <msdadc.h>   // for IDataConvert
#include <msdaguid.h>   // for IDataConvert

using namespace std;