// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Common.h"
#include "../shared/Network.h"
#include "../shared/log.h"
#include "../shared/FastQueue.h"
#include "AMHSPacket.h"

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
