// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� VEHICLEMOVE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// VEHICLEMOVE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef VEHICLEMOVE_EXPORTS
#define VEHICLEMOVE_API __declspec(dllexport)
#else
#define VEHICLEMOVE_API __declspec(dllimport)
#endif

// �����Ǵ� VehicleMove.dll ������
class VEHICLEMOVE_API CVehicleMove {
public:
	CVehicleMove(void);
	// TODO: �ڴ�������ķ�����
};

extern VEHICLEMOVE_API int nVehicleMove;

VEHICLEMOVE_API int fnVehicleMove(void);
