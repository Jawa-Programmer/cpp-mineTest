
#include <GL/glut.h>



static void (*sts)(unsigned char, bool);
	
class Keyboard
{
	private:

	static bool KEY_UP_STATE,
				KEY_DOWN_STATE,
				KEY_RIGHT_STATE,
				KEY_LEFT_STATE,
				
				KEY_W_STATE,
				KEY_S_STATE,
				KEY_A_STATE,
				KEY_D_STATE,
				
				KEY_C_STATE,
				
				KEY_SPACE_STATE,
				KEY_ESC_STATE;

	static void pressSpecialKey(int key, int x, int y)
	{
		switch(key)
		{
			case GLUT_KEY_UP: 
			KEY_UP_STATE = true;
			break;
			case GLUT_KEY_DOWN:
			KEY_DOWN_STATE = true;
			break;
			case GLUT_KEY_LEFT:
			KEY_LEFT_STATE = true;
			break;
			case GLUT_KEY_RIGHT:
			KEY_RIGHT_STATE = true;
			break;
			}
		}
	static void pressKey(unsigned char key, int x, int y)
	{
		switch(key)
		{
			case 27:
			KEY_ESC_STATE = true;
			break;
			case ' ':
			KEY_SPACE_STATE = true;
			break;
			case 's':
			Keyboard::KEY_S_STATE = true;
			break;
			case 'a':
			Keyboard::KEY_A_STATE = true;
			break;
			case 'd':
			Keyboard::KEY_D_STATE = true;
			break;
			case 'w':
			Keyboard::KEY_W_STATE = true;
			break;
			case 'c':
			Keyboard::KEY_C_STATE = true;
			break;
			}
			sts(key, true);
		}
		static void releaseKey(unsigned char key, int x, int y)
	{
		switch(key)
		{
			case 27:
			KEY_ESC_STATE = false;
			break;
			case ' ':
			KEY_SPACE_STATE = false;
			break;
			case 's':
			Keyboard::KEY_S_STATE = false;
			break;
			case 'a':
			Keyboard::KEY_A_STATE = false;
			break;
			case 'd':
			Keyboard::KEY_D_STATE = false;
			break;
			case 'w':
			Keyboard::KEY_W_STATE = false;
			break;
			case 'c':
			Keyboard::KEY_C_STATE = false;
			break;
			}
			sts(key, false);
		}
	static void releaseSpecialKey(int key, int x, int y)
	{
		switch(key)
		{
			case GLUT_KEY_UP: 
			KEY_UP_STATE = false;
			break;
			case GLUT_KEY_DOWN:
			KEY_DOWN_STATE = false;
			break;
			case GLUT_KEY_LEFT:
			KEY_LEFT_STATE = false;
			break;
			case GLUT_KEY_RIGHT:
			KEY_RIGHT_STATE = false;
			break;
			
			case 27:
			KEY_ESC_STATE = false;
			break;
			case ' ':
			KEY_SPACE_STATE = false;
			break;
			}
		}


	public:
	
	//static const int KEYBOARD_KEY_W = 1,
	
	static void init()
	{
		glutIgnoreKeyRepeat(1);
		glutSpecialFunc(pressSpecialKey);
		glutSpecialUpFunc(releaseSpecialKey);
		glutKeyboardFunc(pressKey);
		glutKeyboardUpFunc(releaseKey);
		}
		
	static bool IsSpecialButtonDown(int key)
	{
		switch(key)
		{
			case GLUT_KEY_UP: 
			return KEY_UP_STATE;
			case GLUT_KEY_DOWN:
			return KEY_DOWN_STATE;
			case GLUT_KEY_LEFT:
			return KEY_LEFT_STATE;
			case GLUT_KEY_RIGHT:
			return KEY_RIGHT_STATE;
			}
		}
	static bool IsButtonDown(unsigned char key)
	{
		switch(key)
		{
			case 'a': 
			return KEY_A_STATE;
			case 's':
			return KEY_S_STATE;
			case 'd':
			return KEY_D_STATE;
			case 'w':
			return KEY_W_STATE;
			case 'c':
			return KEY_C_STATE;
			
			case 27:
			return KEY_ESC_STATE;
			case ' ':
			return KEY_SPACE_STATE;
			}
		}
		static void ChangeStateListener(void (*list)(unsigned char, bool))
		{
			sts = list;
			}
	};
	
		bool Keyboard::KEY_UP_STATE = false;
		bool Keyboard::KEY_DOWN_STATE = false;
		bool Keyboard::KEY_RIGHT_STATE = false;
		bool Keyboard::KEY_LEFT_STATE = false;
				
		bool Keyboard::KEY_W_STATE = false;
		bool Keyboard::KEY_S_STATE = false;
		bool Keyboard::KEY_A_STATE = false;
		bool Keyboard::KEY_D_STATE = false;
		
		bool Keyboard::KEY_C_STATE = false;
		
		bool Keyboard::KEY_SPACE_STATE = false;
		bool Keyboard::KEY_ESC_STATE = false;
