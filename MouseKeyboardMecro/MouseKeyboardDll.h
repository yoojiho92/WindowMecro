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


// 마우스 함수
// 버튼 == 0 : 왼쪽클릭 , 1 : 오른쪽 클릭, 2 : 가운데 클릭
// 좌표는 절대값으로 이동한다.
MOUSEKEYBOARDDLL void MouseMove(int x, int y);							// 마우스 이동 ( x좌표, y좌표 )
MOUSEKEYBOARDDLL void MouseDown(int button);							// 마우스 버튼 누름 ( 버튼 )	
MOUSEKEYBOARDDLL void MouseUp(int button);								// 마우스 버튼 뗌 ( 버튼 )
MOUSEKEYBOARDDLL void MouseClick(int button);							// 마우스 눌렀다 떔 ( 버튼 )
MOUSEKEYBOARDDLL void MouseMoveClick(int x, int y, int button);			// 마우스 이동 후 클릭 ( x좌표, y좌표 , 버튼 )
MOUSEKEYBOARDDLL void MouseDrag(int x1, int y1);						// 마우스 드래그 (x1좌표, y1좌표 ) 현재위치에서 목적지위치 까지 드래그 
MOUSEKEYBOARDDLL void MouseDoubleClick(int button);						// 아무스 더블클릭 ( 버튼 )

// 키보드 함수
MOUSEKEYBOARDDLL void KeyDown(char c);									// 키보드 누름 ( 문자 , 누르는 시간 )
MOUSEKEYBOARDDLL void KeyUp(char c);									// 키보드 땜 ( 문자 )
MOUSEKEYBOARDDLL void KeyUpDown(char c, int delay);						// 키보드 눌렀다 떔 ( 문자 )
MOUSEKEYBOARDDLL void TypeString(char *str);							// 타이핑을 함 ( 문자열 )
MOUSEKEYBOARDDLL void CtrlKey(char c);									// 컨트롤 + 키보드 눌렀다떔 ( 문자 )
MOUSEKEYBOARDDLL void ShiftKey(char c);									// 쉬프트 + 키보드 눌렀다떔 ( 문자 )
MOUSEKEYBOARDDLL void AltKey(char c);									// 알트 + 키보드 눌렀다떔 ( 문자 )

// 특수키는 첨부 txt파일을 참고
MOUSEKEYBOARDDLL void cmdKeyDown(int key);								// 특수키 누름 ( 특수키 번호 )
MOUSEKEYBOARDDLL void cmdKeyUp(int key);								// 특수키 땜 ( 특수키 번호)
MOUSEKEYBOARDDLL void cmdKeyUpDown(int key);							// 특수키 눌렀다 떔 ( 특수키 번호)
MOUSEKEYBOARDDLL void sleep_dt(int delay);							
int specialKey(int vk);

EXTERN_C_END
