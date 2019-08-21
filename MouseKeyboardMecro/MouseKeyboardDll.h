#ifdef MOUSEKEYBOARDDLL_EXPORTS
	#define MOUSEKEYBOARDDLL __declspec(dllexport)
#else
	#define MOUSEKEYBOARDDLL __declspec(dllimport)
#endif



#ifdef __cplusplus 

#define EXTERN_C extern "C" 
#define EXTERN_C_START extern "C" { 
#define EXTERN_C_END } 
#else 
#define EXTERN_C extern 
#define EXTERN_C_START 
#define EXTERN_C_END 
#endif 

EXTERN_C_START


// ���콺 �Լ�
// ��ư == 0 : ����Ŭ�� , 1 : ������ Ŭ��, 2 : ��� Ŭ��
// ��ǥ�� ���밪���� �̵��Ѵ�.
MOUSEKEYBOARDDLL void MouseMove(int x, int y);							// ���콺 �̵� ( x��ǥ, y��ǥ )
MOUSEKEYBOARDDLL void MouseDown(int button);							// ���콺 ��ư ���� ( ��ư )	
MOUSEKEYBOARDDLL void MouseUp(int button);								// ���콺 ��ư �� ( ��ư )
MOUSEKEYBOARDDLL void MouseClick(int button);							// ���콺 ������ �� ( ��ư )
MOUSEKEYBOARDDLL void MouseMoveClick(int x, int y, int button);			// ���콺 �̵� �� Ŭ�� ( x��ǥ, y��ǥ , ��ư )
MOUSEKEYBOARDDLL void MouseDrag(int x1, int y1);						// ���콺 �巡�� (x1��ǥ, y1��ǥ ) ������ġ���� ��������ġ ���� �巡�� 
MOUSEKEYBOARDDLL void MouseDoubleClick(int button);						// �ƹ��� ����Ŭ�� ( ��ư )

// Ű���� �Լ�
MOUSEKEYBOARDDLL void KeyDown(char c);									// Ű���� ���� ( ���� , ������ �ð� )
MOUSEKEYBOARDDLL void KeyUp(char c);									// Ű���� �� ( ���� )
MOUSEKEYBOARDDLL void KeyUpDown(char c, int delay);						// Ű���� ������ �� ( ���� )
MOUSEKEYBOARDDLL void TypeString(char *str);							// Ÿ������ �� ( ���ڿ� )
MOUSEKEYBOARDDLL void CtrlKey(char c);									// ��Ʈ�� + Ű���� �����ً� ( ���� )
MOUSEKEYBOARDDLL void ShiftKey(char c);									// ����Ʈ + Ű���� �����ً� ( ���� )
MOUSEKEYBOARDDLL void AltKey(char c);									// ��Ʈ + Ű���� �����ً� ( ���� )

// Ư��Ű�� ÷�� txt������ ����
MOUSEKEYBOARDDLL void cmdKeyDown(int key);								// Ư��Ű ���� ( Ư��Ű ��ȣ )
MOUSEKEYBOARDDLL void cmdKeyUp(int key);								// Ư��Ű �� ( Ư��Ű ��ȣ)
MOUSEKEYBOARDDLL void cmdKeyUpDown(int key);							// Ư��Ű ������ �� ( Ư��Ű ��ȣ)
MOUSEKEYBOARDDLL void sleep_dt(int delay);							
int specialKey(int vk);

EXTERN_C_END
