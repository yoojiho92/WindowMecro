

namespace MacroFuncs {
	class MacroFuncs
	{
	public:	
		// 마우스 함수
		static void MouseMove(int x, int y);						// 마우스 이동 ( x좌표, y좌표 )
		static void MouseDown(int button);							// 마우스 버튼 누름 ( 버튼 )
		static void MouseUp(int button);							// 마우스 버튼 뗌 ( 버튼 )
		static void MouseClick(int button);							// 마우스 눌렀다 떔 ( 버튼 )
		static void MouseMoveClick(int x, int y, int button);		// 마우스 이동 후 클릭 ( x좌표, y좌표 , 버튼 )
		static void MouseDrag(int x1, int y1, int x2, int y2);		// 마우스 드래그 ( x1좌표, y1좌표, x2좌표, y2좌표 ) 
		static void MouseDoubleClick(int button);					// 아무스 더블클릭 ( 버튼 )

		// 키보드 함수 
		static void KeyDown(char c, int delay);						// 키보드 누름 ( 문자 , 누르는 시간 )
		static void KeyUp(char c);									// 키보드 땜 ( 문자 )
		static void KeyUpDown(char c);								// 키보드 눌렀다 떔 ( 문자 )
		static void TypeString(char * str);							// 타이핑을 함 ( 문자열 )
		static void CtrlKey(char c);								// 컨트롤 + 키보드 눌렀다떔 ( 문자 )
		static void ShiftKey(char c);								// 쉬프트 + 키보드 눌렀다떔 ( 문자 )
		static void AltKey(char c);									// 알트 + 키보드 눌렀다떔 ( 문자 )
	};		
}


