// DriveTestConsol.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "../shared/Util.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//CAMHSDrive amhsDev;
	//amhsDev.Init();
	////amhsDev.SetOHTLocation( 200);
	//amhsDev.OHTStatusBackTime(254, 150);


	//getchar();
	//amhsDev.Clean();

	string strVal = "<12,34><34,45><23,77><34,56,78,90,98><33,44,55,66>";

	STR_VEC list = GetVecStrings(strVal);
	for (STR_VEC::iterator it = list.begin();
		it != list.end(); ++it)
	{
		cout << it->c_str() << endl;
		STR_VEC ln = SplitString(*it, ",");
		for (STR_VEC::iterator nit = ln.begin();
			nit != ln.end(); ++ nit)
		{
			cout << nit->c_str() << endl;
		}
	}
	
	getchar();

	return 0;
}
//
//#include <boost/regex.hpp>
//#include <iostream>
//#include <string>
//
//void print_captures(const std::string& regx, const std::string& text)
//{
//	boost::regex e(regx);
//	boost::smatch mathc_what;
//	std::cout << "Expression: \"" << regx << "\"\n";
//	std::cout << "Text: \"" << text << "\"\n";
//	if(boost::regex_match(text, mathc_what, e, boost::match_extra))
//	{
//		unsigned i, j = 0;
//		std::cout << "** Match found **\n Sub-Expressions:\n";
//		for(i = 0; i < mathc_what.size(); ++i)
//			std::cout << " $" << i << " = \"" << mathc_what[i] << "\"\n";
//		std::cout << " Captures:\n";
//		for(i = 0; i < mathc_what.size(); ++i)
//		{
//			std::cout << " $" << i << " = {";
//			//for(j = 0; j < what.captures(i).size(); ++j)
//			{
//				if(j)
//					std::cout << ", ";
//				else
//					std::cout << " ";
//				std::cout << "\"" << mathc_what.captures(i)[j] << "\"";
//				//mathc_what.match_results();
//			}
//			std::cout << " }\n";
//		}
//	}
//	else
//	{
//		std::cout << "** No Match found **\n";
//	}
//}
//int main(int , char* [])
//{
//	print_captures("(([[:lower:]]+)|([[:upper:]]+))+", "aBBcccDDDDDeeeeeeee");
//	print_captures("(.*)bar|(.*)bah", "abcbar");
//	print_captures("(.*)bar|(.*)bah", "abcbah");
//	print_captures("^(?:(\\w+)|(?>\\W+))*$",
//		"now is the time for all good men to come to the aid of the party");
//
//	getchar();
//
//	return 0;
//}



//#include <iostream>
//#include <boost/regex.hpp>
//
//using namespace std;
//int main(int argc, char* argv[])
//{    //( 1 )   ((  3  )  2 )((  5 )4)(    6    )   
//	//(/w+)://((/w+/.)*/w+)((//w*)*)(//w+/./w+)?
//	//^Э��://��ַ(x.x...x)/·��(n��/�ִ�)/��ҳ�ļ�(xxx.xxx)
//	const char *szReg = ".*?(<[123].*?>).*?";
//	const char *szStr = "<12, 34><23,45>";
//
//	{    //�ַ���ƥ��
//		boost::regex reg( szReg );
//		bool r=boost::regex_match( szStr , reg);
//		//assert(r);
//	}
//
//	{    //��ȡ�Ӵ�
//		boost::cmatch mat;
//		boost::regex reg( szReg );
//		bool r=boost::regex_match( szStr, mat, reg);
//		if(r) //���ƥ��ɹ�
//		{
//			//��ʾ�����Ӵ�
//			for(boost::cmatch::iterator itr=mat.begin(); itr!=mat.end(); ++itr)
//			{
//				//       ָ���Ӵ���Ӧ��λ��        ָ���Ӵ���Ӧβλ��          �Ӵ�����
//				cout << itr->first-szStr << ' ' << itr->second-szStr << ' ' << *itr << endl;
//			}
//		}
//		//Ҳ��ֱ��ȡָ��λ����Ϣ
//		if(mat[4].matched) cout << "Path is" << mat[4] << endl;
//	}
//
//	{ //����
//		boost::cmatch mat;
//		boost::regex reg( "<.*?>" );    //�����ַ����������
//		if(boost::regex_search(szStr, mat, reg))
//		{
//			cout << "searched:" << mat[0] << endl;
//			for(boost::cmatch::iterator itr=mat.begin(); itr!=mat.end(); ++itr)
//			{
//				//       ָ���Ӵ���Ӧ��λ��        ָ���Ӵ���Ӧβλ��          �Ӵ�����
//				cout << itr->first-szStr << ' ' << itr->second-szStr << ' ' << *itr << endl;
//			}
//		}
//	}
//
//	{ //�滻
//		boost::regex reg( szReg );
//		string s = boost::regex_replace( string(szStr), reg, "ftp://$2$5");
//		cout << "ftp site:"<< s << endl;
//	}
//	{ //�滻2����<>&ת������ҳ�ַ�
//		string s1 = "(<)|(>)|(&)";
//		string s2 = "(?1&lt;)(?2&gt;)(?3&amp;)";
//		boost::regex reg( s1 );
//		string s = boost::regex_replace( string("cout << a&b << endl;"), reg, s2, boost::match_default | boost::format_all);
//		cout << "HTML:"<< s << endl;
//	}
//
//	{ //ʹ�õ������ҳ���������
//		boost::regex reg( "//d+" );    //�����ַ����������
//		boost::cregex_iterator itrBegin = make_regex_iterator(szStr,reg); //(szStr, szStr+strlen(szStr), reg);
//		boost::cregex_iterator itrEnd;
//		for(boost::cregex_iterator itr=itrBegin; itr!=itrEnd; ++itr)
//		{
//			//       ָ���Ӵ���Ӧ��λ��        ָ���Ӵ���Ӧβλ��          �Ӵ�����
//			cout << (*itr)[0].first-szStr << ' ' << (*itr)[0].second-szStr << ' ' << *itr << endl;
//		}
//	}
//
//	{ //ʹ�õ���������ַ���
//		boost::regex reg("/");  //��/������ַ���
//		boost::cregex_token_iterator itrBegin = make_regex_token_iterator(szStr,reg,-1); //ʹ��-1����ʱ��֣�ʹ����������ʱ��ʾȡ�ڼ����Ӵ�����ʹ������ȡ�����
//		boost::cregex_token_iterator itrEnd;
//		for(boost::cregex_token_iterator itr=itrBegin; itr!=itrEnd; ++itr)
//		{
//			cout << *itr << endl;
//		}
//	}
//
//	{ //ʹ�õ���������ַ���2
//		boost::regex reg("(.)/(.)");  //ȡ/��ǰһ�ַ��ͺ�һ�ַ�������ַ�������ò���е�а��-_-��
//		int subs[] = {1,2};        // ��һ�Ӵ��͵ڶ��Ӵ�
//		boost::cregex_token_iterator itrBegin = make_regex_token_iterator(szStr,reg,subs); //ʹ��-1����ʱ��֣�ʹ����������ʱ��ʾȡ�ڼ����Ӵ�����ʹ������ȡ�����
//		boost::cregex_token_iterator itrEnd;
//		for(boost::cregex_token_iterator itr=itrBegin; itr!=itrEnd; ++itr)
//		{
//			cout << *itr << endl;
//		}
//	}
//
//
//	cin.get();
//	return 0;
//}
//
