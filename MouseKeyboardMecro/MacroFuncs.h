

namespace MacroFuncs {
	class MacroFuncs
	{
	public:	
		// ���콺 �Լ�
		static void MouseMove(int x, int y);						// ���콺 �̵� ( x��ǥ, y��ǥ )
		static void MouseDown(int button);							// ���콺 ��ư ���� ( ��ư )
		static void MouseUp(int button);							// ���콺 ��ư �� ( ��ư )
		static void MouseClick(int button);							// ���콺 ������ �� ( ��ư )
		static void MouseMoveClick(int x, int y, int button);		// ���콺 �̵� �� Ŭ�� ( x��ǥ, y��ǥ , ��ư )
		static void MouseDrag(int x1, int y1, int x2, int y2);		// ���콺 �巡�� ( x1��ǥ, y1��ǥ, x2��ǥ, y2��ǥ ) 
		static void MouseDoubleClick(int button);					// �ƹ��� ����Ŭ�� ( ��ư )

		// Ű���� �Լ� 
		static void KeyDown(char c, int delay);						// Ű���� ���� ( ���� , ������ �ð� )
		static void KeyUp(char c);									// Ű���� �� ( ���� )
		static void KeyUpDown(char c);								// Ű���� ������ �� ( ���� )
		static void TypeString(char * str);							// Ÿ������ �� ( ���ڿ� )
		static void CtrlKey(char c);								// ��Ʈ�� + Ű���� �����ً� ( ���� )
		static void ShiftKey(char c);								// ����Ʈ + Ű���� �����ً� ( ���� )
		static void AltKey(char c);									// ��Ʈ + Ű���� �����ً� ( ���� )
	};		
}


